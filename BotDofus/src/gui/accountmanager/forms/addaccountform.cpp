#include "addaccountform.h"
#include "ui_addaccountform.h"

AddAccountForm::AddAccountForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddAccountForm)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);
}

AddAccountForm::~AddAccountForm()
{
    delete ui;
}

void AddAccountForm::on_pushButtonAddAccount_clicked()
{
    if((!ui->lineEditAccount->text().isEmpty()) && !ui->lineEditPassword->text().isEmpty())
    {
        QSqlQuery query;

        if(ui->groupBoxOptions->isChecked() && ui->lineEditAccount->text().contains("%"))
        {
            if(ui->spinBox->value() > ui->spinBox_2->value())
                QMessageBox::critical(this,"Erreur","La valeur de la première itération doit être inférieur à celle de fin.");

            else
            {
                QString value = "VALUES";

                for(int i = ui->spinBox->value(); i <= ui->spinBox_2->value(); i++)
                {
                    QString login = ui->lineEditAccount->text();

                    value.append(QString("('%1','%2'),").arg(login.replace("%", QString::number(i))).arg(ui->lineEditPassword->text()));
                }

                value.remove(value.size()-1, 1);

                query.prepare(QString("INSERT INTO accounts (login, password) %1").arg(value));

                if(query.exec())
                    QMessageBox::information(this,"Sauvegarde","Les comptes ont été ajoutés !");
                else
                    qDebug() << query.lastError();
            }
        }

        else
        {
            query.prepare("SELECT login FROM accounts WHERE login = (:login)");
            query.bindValue(":login", ui->lineEditAccount->text());
            if (query.exec())
            {
               if (query.next())
                   QMessageBox::critical(this,"Sauvegarde","Le compte existe déjà !");

               else
               {
                   query.prepare("INSERT INTO accounts (login, password) VALUES (:login,:password)");
                   query.bindValue(":login", ui->lineEditAccount->text());
                   query.bindValue(":password", ui->lineEditPassword->text());

                   if(query.exec())
                       QMessageBox::information(this,"Sauvegarde","Le compte a été ajouté !");
               }
            }


        }

        ui->lineEditAccount->clear();
        ui->lineEditPassword->clear();

        emit updateListAccounts(); // initialization() in LoaderAccountForm
    }
}

void AddAccountForm::on_pushButtonRefreshAccountName_clicked()
{
    ui->lineEditAccountName->setText(getRandomString(10));
}

void AddAccountForm::on_pushButtonRefreshPassword_clicked()
{
    ui->lineEditPassword_2->setText(getRandomString(9));
}

void AddAccountForm::on_pushButtonRefreshEmail_clicked()
{
    ui->lineEditEmail->setText(getRandomString()+"@yahoo.com");
}

void AddAccountForm::on_pushButtonRefreshNickname_clicked()
{
    ui->lineEditNickname->setText(getRandomString(9));
}

QString AddAccountForm::getRandomString(int size)
{
    QString str;

    QString alphabet = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < size; i++)
    {
        int random =  (rand() % (alphabet.size()-1));
        str.append(alphabet.at(random));
    }

    return str;
}

void AddAccountForm::on_pushButtonLockAccountName_clicked(bool checked)
{
    if(checked)
        ui->pushButtonLockAccountName->setIcon(QIcon(":/icons/lock_open.ico"));
    else
        ui->pushButtonLockAccountName->setIcon(QIcon(":/icons/lock.ico"));

    ui->pushButtonRefreshAccountName->setEnabled(!checked);
}

void AddAccountForm::on_pushButtonLockPassword_clicked(bool checked)
{
    if(checked)
        ui->pushButtonLockPassword->setIcon(QIcon(":/icons/lock_open.ico"));
    else
        ui->pushButtonLockPassword->setIcon(QIcon(":/icons/lock.ico"));

    ui->pushButtonRefreshPassword->setEnabled(!checked);
}

void AddAccountForm::on_pushButtonLockEmail_clicked(bool checked)
{
    if(checked)
        ui->pushButtonLockEmail->setIcon(QIcon(":/icons/lock_open.ico"));
    else
        ui->pushButtonLockEmail->setIcon(QIcon(":/icons/lock.ico"));

    ui->pushButtonRefreshEmail->setEnabled(!checked);
}

void AddAccountForm::on_pushButtonLockNickname_clicked(bool checked)
{
    if(checked)
        ui->pushButtonLockNickname->setIcon(QIcon(":/icons/lock_open.ico"));
    else
        ui->pushButtonLockNickname->setIcon(QIcon(":/icons/lock.ico"));

    ui->pushButtonRefreshNickname->setEnabled(!checked);
}

void AddAccountForm::on_pushButtonRefreshGlobal_clicked()
{
    // TODO : Request webpage subscription account
    // Step progressbar 10 30 45 100
}

void AddAccountForm::on_lineEditAccountName_textChanged(const QString &arg1)
{
    QUrl url("www.dofus.com/fr/mmorpg/jouer");

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.105 Safari/537.36");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded; charset=UTF-8");

    QString param = "sAction=test&sLang=fr&sTestField=userlogin&sToken=fBRY5z1fnxDzxyLWw5TgOcxQjmGvLn3u&userlogin="+arg1;

    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    mgr->post(request, param.toUtf8());
}

void AddAccountForm::onfinish(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}
