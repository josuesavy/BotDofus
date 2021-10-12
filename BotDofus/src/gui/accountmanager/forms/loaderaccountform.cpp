#include "loaderaccountform.h"
#include "ui_loaderaccountform.h"

LoaderAccountForm::LoaderAccountForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoaderAccountForm)
{
    ui->setupUi(this);

    initialization();

    ui->treeWidgetAccounts->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->treeWidgetAccounts->header()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->treeWidgetAccounts->header()->setSectionResizeMode(2, QHeaderView::Stretch);

    if(ui->treeWidgetAccounts->topLevelItemCount() > 0)
        ui->pushButtonLoad->setEnabled(true);

    ui->comboBoxMaster->setEnabled(false);
}

LoaderAccountForm::~LoaderAccountForm()
{
    delete ui;
}


void LoaderAccountForm::initialization()
{
    ui->treeWidgetAccounts->clear();
    m_accounts.clear();

    QSqlQuery query;
    query.prepare("SELECT DISTINCT * FROM accounts");

    if(query.exec())
    {
        while(query.next())
        {
            QStringList infoAccount = {
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(7).toUInt() != 0? QDateTime::fromTime_t(query.value(7).toUInt()).toString("dd/MM/yyyy hh:mm:ss"): "",
                query.value(6).toBool()? "Yes": "No"
            };
            ui->treeWidgetAccounts->addTopLevelItem(new QTreeWidgetItem(QStringList(infoAccount)));

            ConnectionInfos account;
            account.alias = query.value(1).toString();
            account.login = query.value(2).toString();
            account.password = query.value(3).toString();
            account.character = query.value(4).toString();
            account.serverId = query.value(5).toInt() == 0? INVALID: query.value(5).toInt();
            account.isBanned = query.value(6).toBool();
            account.lastConnection = query.value(7).toLongLong();

            m_accounts<<account;
        }
    }
}

void LoaderAccountForm::on_treeWidgetAccounts_itemSelectionChanged()
{
    if(ui->treeWidgetAccounts->selectedItems().size() > 1 && ui->treeWidgetAccounts->selectedItems().size() <= 8)
    {
        ui->comboBoxMaster->clear();
        ui->comboBoxMaster->addItem("Do not make a group");
        ui->comboBoxMaster->setEnabled(true);

        for(int i = 0; i < ui->treeWidgetAccounts->selectedItems().size(); i++)
            ui->comboBoxMaster->addItem(ui->treeWidgetAccounts->selectedItems().at(i)->text(1), i);
    }
    else
    {
        ui->comboBoxMaster->clear();
        ui->comboBoxMaster->addItem("Do not make a group");
        ui->comboBoxMaster->setEnabled(false);
    }
}

void LoaderAccountForm::on_treeWidgetAccounts_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    Qt::ItemFlags flags = item->flags();
    if(column == 0)
    {
        item->setFlags(flags | Qt::ItemIsEditable);
        ui->treeWidgetAccounts->editItem(item, column);
    }

    else
    {
        QList<ConnectionInfos> account;

        for (int i = 0; i < m_accounts.size(); i++)
        {
            if (m_accounts[i].login == item->text(1))
            {
                m_accounts[i].connectionTo = (ConnectionTo)ui->comboBoxConnectionTo->currentIndex();
                m_accounts[i].autoConnect = ui->checkBoxConnectionAuto->isChecked();

                QSqlQuery query;
                query.prepare("SELECT idaccounts FROM accounts WHERE login = (:login)");
                query.bindValue(":login", m_accounts[i].login);

                if (query.exec())
                {
                    if (query.next())
                    {
                        int idAccount = query.value(0).toInt();

                        query.prepare("SELECT * FROM creation WHERE idaccounts = (:idaccounts)");
                        query.bindValue(":idaccounts", idAccount);

                        if (query.exec())
                        {
                            if (query.next())
                            {
                                m_accounts[i].needToCreateCharacter = true;
                                m_accounts[i].characterCreated = false;

                                m_accounts[i].creation.name = query.value(1).toString();
                                m_accounts[i].creation.server = query.value(2).toInt();
                                m_accounts[i].creation.breed = query.value(3).toInt();
                                m_accounts[i].creation.sex = query.value(4).toBool();
                                m_accounts[i].creation.head = query.value(5).toInt();
                                m_accounts[i].creation.skipDidactiel = !query.value(7).toBool();

                                QList<int> colors;
                                foreach(QString color, query.value(6).toString().split("|"))
                                {
                                    colors << color.toInt();
                                }
                                m_accounts[i].creation.colors = colors;
                            }
                        }
                    }
                }

                account<<m_accounts.at(i);
            }
        }
        emit loadAccount(account); // Direction addAccount() MainWindow
    }
}

void LoaderAccountForm::on_pushButtonImportAccounts_clicked()
{
    QString path = QFileDialog::getOpenFileName(this);

    QFile file(path);
    if (file.open(QIODevice::ReadOnly) && file.size())
    {
        QString data = file.readAll();
        QStringList lines = data.split('\n');

        QString request = "INSERT INTO accounts (alias, login, password) SELECT t.alias, t.login, t.password FROM ";
        QString value = "(";

        foreach(QString line, lines)
        {
            if (!line.isEmpty())
            {
                QStringList fields = line.split(':');

                value += QString("SELECT '%1' AS alias, '%2' AS login, '%3' AS password UNION ALL ").arg(fields.at(0)).arg(fields.at(1)).arg(fields.at(2));
            }
        }

        value.remove(value.size() -11, 11);
        value += ") AS t WHERE NOT EXISTS (SELECT alias, login, password FROM accounts a WHERE a.login = t.login)";

        request += value;

        QSqlQuery query;
        query.prepare(request);

        if(query.exec())
            QMessageBox::information(this,"Import","Importing successful accounts!");
        else
            QMessageBox::critical(this,"Error", query.lastError().text());

        file.close();
    }

    initialization();
}

void LoaderAccountForm::on_pushButtonExportAccounts_clicked()
{
    QString path = QFileDialog::getSaveFileName(this);

    QFile file(path);
    if (file.open(QIODevice::WriteOnly))
    {
        QString data;

        QSqlQuery query;
        query.prepare("SELECT alias,login,password FROM accounts");
        if(query.exec())
        {
            while(query.next())
                data.append(QString("%1:%2:%3\n").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()));
        }

        QTextStream textStream(&file);
        textStream << data;

        file.close();

        QMessageBox::information(this,"Export","Export of completed accounts!");
    }
}

void LoaderAccountForm::on_pushButtonDelete_clicked()
{
    if(ui->treeWidgetAccounts->selectedItems().count() != 0)
    {
        int answ = QMessageBox::warning(this, "Confirm", "Are you sure you want to delete.", QMessageBox::Yes | QMessageBox::No);
        if(answ == QMessageBox::Yes)
        {
            QSqlQuery query;

            foreach (const QModelIndex &indexModel, ui->treeWidgetAccounts->selectionModel()->selectedIndexes())
            {
                query.prepare("SELECT login FROM accounts WHERE login = (:login)");
                query.bindValue(":login", m_accounts[indexModel.row()].login);
                if (query.exec())
                {
                   if (query.next())
                   {
                       query.prepare("DELETE FROM accounts WHERE login = :login");
                       query.bindValue(":login", m_accounts[indexModel.row()].login);
                       query.exec();
                   }
                }
            }

            initialization();

            emit updateListAccounts(); // initialization() in CharacterCreatorForm
        }

        if(ui->treeWidgetAccounts->topLevelItemCount() == 0)
            ui->pushButtonLoad->setEnabled(false);
    }
    else
        QMessageBox::critical(this,"Error","Please select a account in the list");
}

void LoaderAccountForm::on_pushButtonLoad_clicked()
{
    if(ui->treeWidgetAccounts->selectionModel()->selectedRows().size())
    {
        QList<ConnectionInfos> accounts;

        foreach (QTreeWidgetItem *item, ui->treeWidgetAccounts->selectedItems())
        {
            for (int i = 0; i < m_accounts.size(); i++)
            {
                if (m_accounts[i].login == item->text(1))
                {
                    m_accounts[i].connectionTo = (ConnectionTo)ui->comboBoxConnectionTo->currentIndex();
                    m_accounts[i].autoConnect = ui->checkBoxConnectionAuto->isChecked();
                    m_accounts[i].masterGroup = QString();

                    QSqlQuery query;

                    if(ui->comboBoxMaster->currentIndex() > 0)
                    {
                        query.prepare("SELECT login, character FROM accounts WHERE login=(:login)");
                        query.bindValue(":login", ui->comboBoxMaster->currentText());
                        if (query.exec())
                        {
                            if (query.next())
                            {
                                QString character = query.value(1).toString();

                                if(!character.isEmpty())
                                {
                                    m_accounts[i].masterGroup = character;
                                }
                                else
                                {
                                    QMessageBox::critical(this,"Error",QString("No characters registered on the <b>%1</b> account").arg(query.value(0).toString()));
                                    return;
                                }
                            }
                        }
                    }

                    query.prepare("SELECT idaccounts FROM accounts WHERE login = (:login)");
                    query.bindValue(":login", m_accounts[i].login);

                    if (query.exec())
                    {
                        if (query.next())
                        {
                            int idAccount = query.value(0).toInt();

                            query.prepare("SELECT * FROM creation WHERE idaccounts = (:idaccounts)");
                            query.bindValue(":idaccounts", idAccount);

                            if (query.exec())
                            {
                                if (query.next())
                                {
                                    m_accounts[i].needToCreateCharacter = true;
                                    m_accounts[i].characterCreated = false;

                                    m_accounts[i].creation.name = query.value(1).toString();
                                    m_accounts[i].creation.server = query.value(2).toInt();
                                    m_accounts[i].creation.breed = query.value(3).toInt();
                                    m_accounts[i].creation.sex = query.value(4).toBool();
                                    m_accounts[i].creation.head = query.value(5).toInt();
                                    m_accounts[i].creation.skipDidactiel = !query.value(7).toBool();

                                    QList<int> colors;
                                    foreach(QString color, query.value(6).toString().split("|"))
                                    {
                                        colors << color.toInt();
                                    }
                                    m_accounts[i].creation.colors = colors;
                                }
                            }
                        }
                    }

                    accounts<<m_accounts[i];
                }
            }
        }

        if (!accounts.isEmpty())
        {
            if(!accounts.first().masterGroup.isEmpty())
            {
                int indexMaster = 0;
                for(int i = 0; i < accounts.size(); i++)
                {
                    if(accounts.at(i).masterGroup == accounts.at(i).character)
                        indexMaster = i;
                }

                accounts.swapItemsAt(indexMaster, 0);
            }
        }

        emit loadAccount(accounts); // Direction addAccount() MainWindow
    }

    else
        QMessageBox::critical(this,"Error","Please select a account in the list");
}

void LoaderAccountForm::on_treeWidgetAccounts_itemChanged(QTreeWidgetItem *item, int column)
{
    if(column == 0)
    {
        if (!ui->treeWidgetAccounts->selectedItems().isEmpty())
        {
            if(ui->treeWidgetAccounts->selectedItems().first() == item)
            {
                QSqlQuery query;
                query.prepare("UPDATE accounts SET alias=:alias WHERE login=:login");
                query.bindValue(":alias", item->text(0));
                query.bindValue(":login", item->text(1));
                query.exec();
            }
        }
    }
}
