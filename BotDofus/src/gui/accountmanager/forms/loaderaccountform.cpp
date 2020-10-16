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
    query.prepare("SELECT * FROM accounts");

    if(query.exec())
    {
        while(query.next())
        {
            QStringList infoAccount = {
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(7).toUInt() != 0? QDateTime::fromTime_t(query.value(7).toUInt()).toString("dd/MM/yyyy hh:mm:ss"): "",
                query.value(6).toBool()? "Oui": "Non"
            };
            ui->treeWidgetAccounts->addTopLevelItem(new QTreeWidgetItem(QStringList(infoAccount)));

            ConnectionInfos account;
            account.alias = query.value(1).toString();
            account.login = query.value(2).toString();
            account.password = query.value(3).toString();
            account.character = query.value(4).toString();
            account.serverId = query.value(5).toInt();
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
        ui->comboBoxMaster->addItem("Ne pas faire de groupe");
        ui->comboBoxMaster->setEnabled(true);

        for(int i = 0; i < ui->treeWidgetAccounts->selectedItems().size(); i++)
            ui->comboBoxMaster->addItem(ui->treeWidgetAccounts->selectedItems().at(i)->text(1), i);
    }
    else
    {
        ui->comboBoxMaster->clear();
        ui->comboBoxMaster->addItem("Ne pas faire de groupe");
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

        foreach(const QModelIndex &index, ui->treeWidgetAccounts->selectionModel()->selectedRows())
        {
            m_accounts[index.row()].connectionTo = (ConnectionTo)ui->comboBoxConnectionTo->currentIndex();
            m_accounts[index.row()].autoConnect = ui->checkBoxConnectionAuto->isChecked();

            QSqlQuery query;
            query.prepare("SELECT idaccounts FROM accounts WHERE login = (:login)");
            query.bindValue(":login", m_accounts[index.row()].login);

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
                            m_accounts[index.row()].needToCreateCharacter = true;
                            m_accounts[index.row()].characterCreated = false;

                            m_accounts[index.row()].creation.name = query.value(1).toString();
                            m_accounts[index.row()].creation.server = query.value(2).toInt();
                            m_accounts[index.row()].creation.breed = query.value(3).toInt();
                            m_accounts[index.row()].creation.sex = query.value(4).toBool();
                            m_accounts[index.row()].creation.head = query.value(5).toInt();
                            m_accounts[index.row()].creation.skipDidactiel = !query.value(7).toBool();

                            QList<int> colors;
                            foreach(QString color, query.value(6).toString().split("|"))
                            {
                                colors << color.toInt();
                            }
                            m_accounts[index.row()].creation.colors = colors;
                        }
                    }
                }
            }

            account<<m_accounts.at(index.row());
        }
        emit loadAccount(account); // Direction addAccount() MainWindow
    }
}

void LoaderAccountForm::on_pushButtonImportAccounts_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Selectionner un fichier");

    QFile file(path);
    if (file.open(QIODevice::ReadOnly) && file.size())
    {
        QString data = file.readAll();
        QStringList lines = data.split('\n');

        QString request = "INSERT INTO accounts (alias, login, password) VALUES";

        foreach(QString line, lines)
        {
            QStringList fields = line.split(':');

            request+= QString("('%1','%2','%3'),").arg(fields.at(0)).arg(fields.at(1)).arg(fields.at(2));
        }

        request.remove(request.size()-1, 1);

        QSqlQuery query;
        query.prepare(request);

        if(query.exec())
            QMessageBox::information(this,"Importation","Importation des comptes effectués !");
        else
            QMessageBox::critical(this,"Importation","Impossible d'importer les comptes.");

        file.close();
    }

    initialization();
}

void LoaderAccountForm::on_pushButtonExportAccounts_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "Selectionner un dossier");

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

        QMessageBox::information(this,"Exportation","Exportation des comptes effectuée !");
    }
}

void LoaderAccountForm::on_pushButtonDelete_clicked()
{
    if(ui->treeWidgetAccounts->selectedItems().count() != 0)
    {
        int answ = QMessageBox::warning(this, "Confirmation", "Etes-vous sûr de vouloir effectuer la suppression.", QMessageBox::Yes | QMessageBox::No);
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
        QMessageBox::critical(this,"Erreur","Veuillez sélectionné un compte dans la liste");
}

void LoaderAccountForm::on_pushButtonLoad_clicked()
{
    if(ui->treeWidgetAccounts->selectionModel()->selectedRows().size())
    {
        QList<ConnectionInfos> account;

        foreach(const QModelIndex &index, ui->treeWidgetAccounts->selectionModel()->selectedRows())
        {
            m_accounts[index.row()].connectionTo = (ConnectionTo)ui->comboBoxConnectionTo->currentIndex();
            m_accounts[index.row()].autoConnect = ui->checkBoxConnectionAuto->isChecked();
            m_accounts[index.row()].masterGroup = "";

            QSqlQuery query;

            if(ui->comboBoxMaster->currentIndex())
            {
                query.prepare("SELECT character FROM accounts WHERE login=(:login)");
                query.bindValue(":login", ui->comboBoxMaster->currentText());
                if (query.exec())
                {
                    if (query.next())
                    {
                        QString character = query.value(0).toString();

                        if(!character.isEmpty())
                            m_accounts[index.row()].masterGroup = query.value(0).toString();
                        else
                            QMessageBox::critical(this,"Erreur","Oops, une erreur s'est produite. Veuillez réessayez ultérieurement.");
                    }
                }
            }

            query.prepare("SELECT idaccounts FROM accounts WHERE login = (:login)");
            query.bindValue(":login", m_accounts[index.row()].login);

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
                            m_accounts[index.row()].needToCreateCharacter = true;
                            m_accounts[index.row()].characterCreated = false;

                            m_accounts[index.row()].creation.name = query.value(1).toString();
                            m_accounts[index.row()].creation.server = query.value(2).toInt();
                            m_accounts[index.row()].creation.breed = query.value(3).toInt();
                            m_accounts[index.row()].creation.sex = query.value(4).toBool();
                            m_accounts[index.row()].creation.head = query.value(5).toInt();
                            m_accounts[index.row()].creation.skipDidactiel = !query.value(7).toBool();

                            QList<int> colors;
                            foreach(QString color, query.value(6).toString().split("|"))
                            {
                                colors << color.toInt();
                            }
                            m_accounts[index.row()].creation.colors = colors;
                        }
                    }
                }
            }

            account<<m_accounts[index.row()];
        }

        if(!account.first().masterGroup.isEmpty())
        {
            int indexMaster = 0;
            for(int i = 0; i < account.size(); i++)
            {
                if(account.at(i).masterGroup == account.at(i).character)
                    indexMaster = i;
            }

            account.swapItemsAt(indexMaster, 0);
        }

        emit loadAccount(account); // Direction addAccount() MainWindow
    }

    else
        QMessageBox::critical(this,"Erreur","Veuillez sélectionnez un compte dans la liste.");
}

void LoaderAccountForm::on_treeWidgetAccounts_itemChanged(QTreeWidgetItem *item, int column)
{
    if(column == 0)
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
