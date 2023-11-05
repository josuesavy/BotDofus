#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidgetAccount->setItemDelegate(new QTreeWidgetItemDelegate(this));
    ui->pushButtonQuickAccess->setMenu(ui->menuEdit);
    ui->pushButtonQuickAccess->setStyleSheet("QPushButton::menu-indicator{width:0px;}");

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

    delete ui;
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
        int answ = QMessageBox::warning(this, "Warning", "Are you sur you wan to close SweatedBox?\nThere is one or more bots currently online.", QMessageBox::Yes | QMessageBox::No);
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
        QMessageBox::critical(NULL,"Error","The account is already loaded into memory");

    else
    {
        QProgressDialog progressDlg(this);
        progressDlg.setWindowModality(Qt::WindowModal);
        progressDlg.setMinimumWidth(350);
        progressDlg.setWindowTitle("Loading accounts");
        progressDlg.setCancelButton(nullptr);
        progressDlg.setAutoClose(true);
        progressDlg.setMaximum(accounts.size());
        progressDlg.setAttribute(Qt::WA_DeleteOnClose, true);
        progressDlg.show();

        QList<AccountForm*> accountFormsToAutoConnect;

        if (!accounts.isEmpty())
        {
            if(accounts.first().masterGroup.isEmpty())
            {
                for(int i = 0; i < accounts.size(); i++)
                {
                    progressDlg.setLabelText(QString("Loading the <b>%1</b> account...").arg(accounts.at(i).alias.isEmpty() ? accounts.at(i).login: accounts.at(i).alias));
                    progressDlg.setValue(i+1);
                    qApp->processEvents();

                    // Add Account
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
                if (!accounts.isEmpty())
                {
                    ConnectionInfos _loc_ = accounts.first();
                    for (int i = 0; i < accounts.size(); i++)
                    {
                        if (accounts.at(i).serverId == _loc_.serverId)
                        {
                            _loc_ = accounts.at(i);
                        }
                        else
                        {
                            QMessageBox::critical(this,"Error",QString("The <b>%1</b> account is on a different server.").arg(accounts.at(i).alias.isEmpty() ? accounts.at(i).login: accounts.at(i).alias));
                            progressDlg.close();
                            return;
                        }
                    }

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
                        progressDlg.setLabelText(QString("Loading <b>%1's</b> group (%2/%3)...").arg(accounts.at(i).masterGroup).arg(i+1).arg(accounts.size()));
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
            }
        }

        if(!ui->treeWidgetAccount->selectedItems().size() && ui->treeWidgetAccount->topLevelItemCount())
        {
            ui->treeWidgetAccount->topLevelItem(ui->treeWidgetAccount->topLevelItemCount()-1)->setSelected(true);
            ui->stackedWidget->setCurrentWidget(ui->treeWidgetAccount->topLevelItem(ui->treeWidgetAccount->topLevelItemCount()-1)->data(0, Qt::UserRole).value<AccountForm*>());
        }

        // Auto connect accounts if requested
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

            //m_accountForms.at(i)->updateInterface();
            ui->treeWidgetAccount->selectedItems().at(0)->data(0, Qt::UserRole).value<AccountForm*>()->updateInterface();

            break;
        }
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
    accountManagerDialog = new AccountManagerDialog(this);
    connect(accountManagerDialog, SIGNAL(loadAccount(const QList<ConnectionInfos>&)), this, SLOT(addAccount(const QList<ConnectionInfos>&)));
    connect(this, SIGNAL(closeAccountManagerDialog()), accountManagerDialog, SLOT(closeAfterLoaded()));
    accountManagerDialog->setParent(this, Qt::Dialog);
    accountManagerDialog->open();
}

void MainWindow::on_treeWidgetAccount_itemClicked(QTreeWidgetItem *item, int column)
{
    AccountForm *accountForm = item->data(column, Qt::UserRole).value<AccountForm*>();
    ui->stackedWidget->setCurrentWidget(accountForm);
    accountForm->updateInterface();
}

void MainWindow::on_treeWidgetAccount_itemActivated(QTreeWidgetItem *item, int column)
{
    AccountForm *accountForm = item->data(column, Qt::UserRole).value<AccountForm*>();
    ui->stackedWidget->setCurrentWidget(accountForm);
    accountForm->updateInterface();
}

void MainWindow::on_treeWidgetAccount_itemEntered(QTreeWidgetItem *item, int column)
{
    AccountForm *accountForm = item->data(column, Qt::UserRole).value<AccountForm*>();
    ui->stackedWidget->setCurrentWidget(accountForm);
    accountForm->updateInterface();
}

void MainWindow::on_treeWidgetAccount_itemPressed(QTreeWidgetItem *item, int column)
{
    AccountForm *accountForm = item->data(column, Qt::UserRole).value<AccountForm*>();
    ui->stackedWidget->setCurrentWidget(accountForm);
    accountForm->updateInterface();
}

void MainWindow::on_treeWidgetAccount_itemCollapsed(QTreeWidgetItem *item)
{
    ui->treeWidgetAccount->setCurrentItem(item);

    AccountForm *accountForm = item->data(0, Qt::UserRole).value<AccountForm*>();
    ui->stackedWidget->setCurrentWidget(accountForm);
    accountForm->updateInterface();
}

void MainWindow::on_treeWidgetAccount_itemExpanded(QTreeWidgetItem *item)
{
    ui->treeWidgetAccount->setCurrentItem(item);

    AccountForm *accountForm = item->data(0, Qt::UserRole).value<AccountForm*>();
    ui->stackedWidget->setCurrentWidget(accountForm);
    accountForm->updateInterface();
}

void MainWindow::on_treeWidgetAccount_itemSelectionChanged()
{
    if (!ui->treeWidgetAccount->selectedItems().isEmpty())
    {
        QTreeWidgetItem *item = ui->treeWidgetAccount->selectedItems().first();
        ui->treeWidgetAccount->setCurrentItem(item);

        AccountForm *accountForm = item->data(0, Qt::UserRole).value<AccountForm*>();
        ui->stackedWidget->setCurrentWidget(accountForm);
        accountForm->updateInterface();
    }
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


void MainWindow::on_actionConnectAllLoadedAccounts_triggered()
{
    foreach(AccountForm *accountForm, m_accountForms)
    {
        if (!accountForm->getSocket()->isActive())
        {
            accountForm->getEngine()->getConnectionManager().connect(accountForm->getSocket());
        }
    }
}


void MainWindow::on_actionDisconnectAllLoadedAccounts_triggered()
{
    foreach(AccountForm *accountForm, m_accountForms)
    {
        if (accountForm->getSocket()->isActive())
        {
            accountForm->getEngine()->getConnectionManager().disconnect(accountForm->getSocket());
        }
    }
}


void MainWindow::on_actionUnloadAllLoadedAccounts_triggered()
{
    foreach(AccountForm *accountForm, m_accountForms)
    {
        if (accountForm->getSocket()->isActive())
        {
            accountForm->getEngine()->getConnectionManager().disconnect(accountForm->getSocket());
        }

        bool hasChilds = accountForm->getAccountFormChilds().size() > 0;
        remove(accountForm, hasChilds);
    }
}


void MainWindow::on_actionLoadScriptAllLoadedAccounts_triggered()
{
    if (!m_accountForms.isEmpty())
    {
        QString path = QFileDialog::getOpenFileName(nullptr, "Select a file");

        foreach(AccountForm *accountForm, m_accountForms)
        {
            if (accountForm->getSocket()->isActive())
            {
                accountForm->loadScript(path);
            }
        }
    }
}


void MainWindow::on_actionRunScriptAllLoadedAccounts_triggered()
{
    foreach(AccountForm *accountForm, m_accountForms)
    {
        if (accountForm->getSocket()->isActive() && !accountForm->getData().scriptData.isActive)
        {
            accountForm->on_actionRunScript_triggered();
        }
    }
}


void MainWindow::on_actionStopScriptAllLoadedAccounts_triggered()
{
    foreach(AccountForm *accountForm, m_accountForms)
    {
        if (accountForm->getSocket()->isActive() && accountForm->getData().scriptData.isActive)
        {
            accountForm->on_actionRunScript_triggered();
        }
    }
}

