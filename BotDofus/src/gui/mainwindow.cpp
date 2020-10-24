#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initTrayMenu();

    ui->treeWidgetAccount->setItemDelegate(new QTreeWidgetItemDelegate);

    // Liste de connexions
    connect(ui->pushButtonAccountManager, SIGNAL(clicked()), this, SLOT(on_actionAccountManager_triggered()));
    connect(ui->pushButtonAccountManager_2, SIGNAL(clicked()), this, SLOT(on_actionAccountManager_triggered()));
    connect(&m_engine, SIGNAL(informationsUpdated(SocketIO*)), this, SLOT(updateBotInferface(SocketIO*)));
}

MainWindow::~MainWindow()
{
    foreach(AccountForm *accountForm, m_accountForms)
        delete accountForm;

    foreach(QTreeWidgetItem *item, getTreeWidgetItems())
        delete item;

    delete trayIcon;
    delete ui;
}

void MainWindow::initTrayMenu()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("SweatedBox");

    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction("Afficher", this);
    QAction * quitAction = new QAction("Quitter", this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    trayIcon->setContextMenu(menu);
    trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::remove(AccountForm *accountForm, bool child)
{
    int index = m_accountForms.indexOf(accountForm);

    delete m_accountForms.at(index);
    m_accountForms.removeAt(index);

    if(!child)
        delete ui->treeWidgetAccount->topLevelItem(index);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    bool isActive = false;
    foreach(AccountForm *accountForm, m_accountForms)
    {
        if (accountForm->getSocket()->isActive())
        {
            isActive = true;
            break;
        }
    }

    if(isActive)
    {
        int answ = QMessageBox::warning(this, "Attention", "Etes-vous sûr de vouloir fermer SweatedBox ?\nIl y a un ou plusieur bot actuellement en ligne.", QMessageBox::Yes | QMessageBox::No);
        if(answ == QMessageBox::No)
        {
            event->ignore();
            return;
        }
    }

    event->accept();
}

void MainWindow::addAccount(const QList<ConnectionInfos> &accounts)
{
    bool alreadyExist = false;

    foreach(AccountForm *accountForm, m_accountForms)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accountForm->getConnectionInfos().login == accounts.at(i).login)
                alreadyExist = true;
        }
    }

    if (alreadyExist)
        QMessageBox::critical(NULL,"Erreur","Le compte est déjà chargé en mémoire");

    else
    {
        QProgressDialog progressDlg(this);
        progressDlg.setWindowModality(Qt::WindowModal);
        progressDlg.setMinimumWidth(350);
        progressDlg.setWindowTitle("Chargement des comptes");
        progressDlg.setCancelButton(nullptr);
        progressDlg.setAutoClose(true);
        progressDlg.setMaximum(accounts.size());
        progressDlg.show();

        QList<AccountForm*> accountFormsToAutoConnect;

        if(accounts.first().masterGroup.isEmpty())
        {
            // Remplissement de la liste de comptes avec leur Widget
            for(int i = 0; i < accounts.size(); i++)
            {
                progressDlg.setLabelText(QString("Chargement du compte <b>%1</b>...").arg(accounts.at(i).alias.isEmpty() ? accounts.at(i).login: accounts.at(i).alias));
                progressDlg.setValue(i+1);
                qApp->processEvents();

                AccountForm *accountForm = new AccountForm(&m_engine, accounts.at(i));
                connect(accountForm, SIGNAL(remove(AccountForm*, bool)), this, SLOT(remove(AccountForm*, bool)));
                ui->stackedWidget->addWidget(accountForm);

                QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidgetAccount);
                item->setData(0, 1, accounts.at(i).alias.isEmpty() ? accounts.at(i).login: accounts.at(i).alias);
                item->setData(0, 2, (uint)ConnectionState::DISCONNECTED);
                item->setData(0, 4, QPixmap(":/icons/user.png"));
                item->setData(0, Qt::UserRole, QVariant::fromValue(accountForm));

                m_accountForms << accountForm;
                accountFormsToAutoConnect << accountForm;
                ui->treeWidgetAccount->addTopLevelItem(item);
            }
        }

        else
        {
            // Add Master
            AccountForm *accountFormMaster = new AccountForm(&m_engine, accounts.first());
            connect(accountFormMaster, SIGNAL(remove(AccountForm*, bool)), this, SLOT(remove(AccountForm*, bool)));
            ui->stackedWidget->addWidget(accountFormMaster);

            QTreeWidgetItem *parentItem = new QTreeWidgetItem(ui->treeWidgetAccount);
            parentItem->setData(0, 1, accounts.first().alias.isEmpty() ? accounts.first().login: accounts.first().alias);
            parentItem->setData(0, 2, (uint)ConnectionState::DISCONNECTED);
            parentItem->setData(0, 4, QPixmap(":/icons/user.png"));
            parentItem->setData(0, Qt::UserRole, QVariant::fromValue(accountFormMaster));

            m_accountForms << accountFormMaster;
            accountFormsToAutoConnect << accountFormMaster;

            QList<AccountForm *> accountFormsChilds;

            // Add Slaves
            for(int i = 1; i < accounts.size(); i++)
            {
                progressDlg.setLabelText(QString("Chargement du groupe de <b>%1</b> (%2/%3)...").arg(accounts.at(i).masterGroup).arg(i+1).arg(accounts.size()));
                progressDlg.setValue(i+1);
                qApp->processEvents();

                AccountForm *accountFormSlave = new AccountForm(&m_engine, accounts.at(i));
                connect(accountFormSlave, SIGNAL(remove(AccountForm*, bool)), this, SLOT(remove(AccountForm*, bool)));
                ui->stackedWidget->addWidget(accountFormSlave);

                QTreeWidgetItem *childItem = new QTreeWidgetItem();
                childItem->setData(0, 1, accounts.at(i).alias.isEmpty() ? accounts.at(i).login: accounts.at(i).alias);
                childItem->setData(0, 2, (uint)ConnectionState::DISCONNECTED);
                childItem->setData(0, 4, QPixmap(":/icons/user.png"));
                childItem->setData(0, Qt::UserRole, QVariant::fromValue(accountFormSlave));

                m_accountForms << accountFormSlave;
                accountFormsChilds << accountFormSlave;
                accountFormsToAutoConnect << accountFormSlave;
                parentItem->addChild(childItem);
            }

            accountFormMaster->setAccountFormChilds(accountFormsChilds);

            ui->treeWidgetAccount->addTopLevelItem(parentItem);
        }

        if(!ui->treeWidgetAccount->selectedItems().size() && ui->treeWidgetAccount->topLevelItemCount())
        {
            ui->treeWidgetAccount->topLevelItem(ui->treeWidgetAccount->topLevelItemCount()-1)->setSelected(true);
            ui->stackedWidget->setCurrentWidget(ui->treeWidgetAccount->topLevelItem(ui->treeWidgetAccount->topLevelItemCount()-1)->data(0, Qt::UserRole).value<AccountForm*>());
        }

        // Auto connect accounts
        foreach(AccountForm *accountForm, accountFormsToAutoConnect)
        {
            if(accountForm->getConnectionInfos().autoConnect)
                accountForm->autoConnect();
        }

        emit closeAccountManagerDialog();
    }
}

void MainWindow::updateBotInferface(SocketIO *sender)
{
    QList<QTreeWidgetItem*> items = getTreeWidgetItems();

    for(int i = 0; i < m_accountForms.size(); i++)
    {
        if(m_accountForms.at(i)->getSocket() == sender)
        {
            items[i]->setData(0, 1, m_engine.getData(sender).connectionData.connectionInfos.alias.isEmpty()? m_engine.getData(sender).connectionData.connectionInfos.login: m_engine.getData(sender).connectionData.connectionInfos.alias);
            items[i]->setData(0, 2, (uint)m_engine.getData(sender).connectionData.connectionState);
            items[i]->setData(0, 3, m_engine.getData(sender).generalData.botState);
            items[i]->setData(0, 4, m_engine.getData(sender).playerData.headPixmap);

            m_accountForms.at(i)->updateInterface();
            break;
        }
    }
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::DoubleClick:
    {
        if(!this->isVisible())
            show();
        else
            hide();
    }
        break;
    default:
        break;
    }
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionDocumentation_triggered()
{
    // TODO : Lancer une page web
    // qDebug() << ((AccountForm*)(ui->stackedWidget->widget(ui->stackedWidget->currentIndex())))->getConnectionInfos().login;
}

void MainWindow::on_actionAccountManager_triggered()
{
    AccountManagerDialog accountManagerDialog;
    connect(&accountManagerDialog, SIGNAL(loadAccount(const QList<ConnectionInfos>&)), this, SLOT(addAccount(const QList<ConnectionInfos>&)));
    connect(this, SIGNAL(closeAccountManagerDialog()), &accountManagerDialog, SLOT(closeAfterLoaded()));
    accountManagerDialog.setParent(this, Qt::Dialog);
    accountManagerDialog.exec();
}

void MainWindow::on_actionMinimize_triggered()
{
    hide();

    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
    trayIcon->showMessage("SweatedBox", ("SweatedBox est réduit. Pour l'afficher de nouveau cliquez sur l'icône."), icon, 2000);
}

void MainWindow::on_treeWidgetAccount_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->stackedWidget->setCurrentWidget(item->data(column, Qt::UserRole).value<AccountForm*>());
}

void MainWindow::on_treeWidgetAccount_itemActivated(QTreeWidgetItem *item, int column)
{
    ui->stackedWidget->setCurrentWidget(item->data(column, Qt::UserRole).value<AccountForm*>());
}

void MainWindow::on_treeWidgetAccount_itemEntered(QTreeWidgetItem *item, int column)
{
    ui->stackedWidget->setCurrentWidget(item->data(column, Qt::UserRole).value<AccountForm*>());
}

void MainWindow::on_treeWidgetAccount_itemPressed(QTreeWidgetItem *item, int column)
{
    ui->stackedWidget->setCurrentWidget(item->data(column, Qt::UserRole).value<AccountForm*>());
}

void MainWindow::on_treeWidgetAccount_itemCollapsed(QTreeWidgetItem *item)
{
    ui->treeWidgetAccount->setCurrentItem(item);
    ui->stackedWidget->setCurrentWidget(item->data(0, Qt::UserRole).value<AccountForm*>());
}

void MainWindow::on_treeWidgetAccount_itemExpanded(QTreeWidgetItem *item)
{
    ui->treeWidgetAccount->setCurrentItem(item);
    ui->stackedWidget->setCurrentWidget(item->data(0, Qt::UserRole).value<AccountForm*>());
}

QList<QTreeWidgetItem *> MainWindow::getTreeWidgetItems()
{
    QList<QTreeWidgetItem*> items;

    if(ui->treeWidgetAccount->topLevelItemCount())
    {
        for(int i = 0; i < ui->treeWidgetAccount->topLevelItemCount(); i++)
        {
            items << ui->treeWidgetAccount->topLevelItem(i);
            if(ui->treeWidgetAccount->topLevelItem(i)->childCount())
            {
                for(int j = 0; j < ui->treeWidgetAccount->topLevelItem(i)->childCount(); j++)
                {
                    items << ui->treeWidgetAccount->topLevelItem(i)->child(j);
                }
            }
        }
    }

    return items;
}
