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

        if(ui->groupBoxOptions->isChecked())
        {
            if (ui->lineEditAccount->text().contains("%"))
            {
                int begin = ui->spinBox->value();
                int end = ui->spinBox_2->value();
                QString login = ui->lineEditAccount->text();
                QString password = ui->lineEditPassword->text();

                if(begin > end)
                    QMessageBox::critical(this,"Error","The value of the first iteration must be less than that of the second.");

                else
                {
                    QString request = "INSERT INTO accounts (login, password) SELECT t.login, t.password FROM ";
                    QString value = "(";

                    for(int i = begin; i <= end; i++)
                    {
                        QString loginTemp = login;
                        value.append(QString("SELECT '%1' AS login, '%2' AS password UNION ALL ").arg(loginTemp.replace("%", QString::number(i))).arg(password));
                    }

                    value.remove(value.size() -11, 11);
                    value += ") AS t WHERE NOT EXISTS (SELECT login, password FROM accounts a WHERE a.login = t.login)";

                    request += value;

                    query.prepare(request);

                    if(query.exec())
                    {
                        QMessageBox::information(this,"Save","The accounts has been added!");

                        ui->lineEditAccount->clear();
                        ui->lineEditPassword->clear();
                    }
                    else
                        QMessageBox::critical(this,"Erreur", query.lastError().text());
                }
            }

            else
                QMessageBox::critical(this,"Error", "The character '<b>% </b>' is not defined in the account name.");
        }

        else
        {
            query.prepare("INSERT INTO accounts (login, password) SELECT :login, :password WHERE NOT EXISTS (SELECT login, password FROM accounts WHERE login = :login)");
            query.bindValue(":login", ui->lineEditAccount->text());
            query.bindValue(":password", ui->lineEditPassword->text());

            if(query.exec())
            {
                QMessageBox::information(this,"Save","The account has been added!");

                ui->lineEditAccount->clear();
                ui->lineEditPassword->clear();
            }
            else
                QMessageBox::critical(this,"Error", query.lastError().text());
        }

        emit updateListAccounts(); // initialization() in LoaderAccountForm
    }

    else
        QMessageBox::critical(this,"Error", "Please fill in the login fields.");
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
