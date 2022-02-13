#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(USER_DATA_PATH);

    if(m_db.open())
    {
        qDebug() << "Connected Successfully to DB !";

        QSqlQuery query;
        QString request = "CREATE TABLE IF NOT EXISTS accounts ("
                          "idaccounts	INTEGER,"
                          "alias	TEXT,"
                          "login	NUMERIC,"
                          "password	TEXT,"
                          "character	TEXT,"
                          "serverid	INTEGER,"
                          "isbanned	INTEGER,"
                          "lastconnection	INTEGER,"
                          "PRIMARY KEY(idaccounts))";

        query.prepare(request);
        if (!query.exec())
        {
            qDebug() << "'account' database was not created!";
        }


        request = "CREATE TABLE IF NOT EXISTS globalParameters ("
                  "d2o	TEXT,"
                  "d2p	TEXT,"
                  "i18n	TEXT,"
                  "dofus_path	TEXT)";

        query.prepare(request);
        if (!query.exec())
        {
            qDebug() << "'globalParameters' database was not created!";
        }


        request = "CREATE TABLE IF NOT EXISTS creation ("
                  "idcreation	INTEGER,"
                  "name	TEXT,"
                  "server	INTEGER,"
                  "breed	INTEGER,"
                  "sex	INTEGER,"
                  "head	INTEGER,"
                  "colors	TEXT,"
                  "didactiel	INTEGER,"
                  "idaccounts	INTEGER NOT NULL,"
                  "PRIMARY KEY(idcreation AUTOINCREMENT))";

        query.prepare(request);
        if (!query.exec())
        {
            qDebug() << "'creation' database was not created!";
        }

    }
    else
        qDebug()<<"The"<<USER_DATA_PATH<<" file cannot be opened / created";

    init();
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
}

void ConnectionDialog::on_pushButtonBrowser_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this);
    if (!path.isEmpty())
    {
        m_path = path;
        ui->lineEditPathDofus->setText(path);
    }
}

void ConnectionDialog::on_lineEditPathDofus_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->labelCheck->setStyleSheet(QString());
        ui->labelCheck->setText(QString(tr("Select '<b>Dofus</b>' folder")));
    }
    else
    {
        QDir dir(arg1 + "/data/common");
        if (dir.exists())
        {
            dir.setPath(arg1 + "/content/");
            if (dir.exists())
            {
                dir.setPath(arg1 + "/data/i18n");
                if (dir.exists())
                {
                    D2O = m_path + "/data/common";
                    D2P = m_path + "/content";
                    I18N = m_path + QString("/data/i18n/i18n_%1.d2i").arg("fr");

                    QSqlQuery query;
                    query.prepare("INSERT INTO globalParameters (d2o , d2p , i18n, dofus_path) SELECT :d2o , :d2p , :i18n, :dofus_path WHERE NOT EXISTS (SELECT dofus_path FROM globalParameters WHERE d2o = :d2o AND d2p = :d2p AND i18n = :i18n)");
                    query.bindValue(":d2o", D2O);
                    query.bindValue(":d2p", D2P);
                    query.bindValue(":i18n", I18N);
                    query.bindValue(":dofus_path", arg1);
                    if(query.exec())
                    {
                        ui->labelStatus->setText(tr("Initializing game datas..."));
                        ui->progressBar->setValue(20);

                        // ServerHandlerSingleton::get()->init();
                        D2OManagerSingleton::get()->init(D2O, I18N);
                        D2PManagerSingleton::get()->init(D2P);
                        PathfindingMap::initialize();
                    }

                    // Pour l'emplacement valide
                    ui->labelCheck->setStyleSheet("color: rgba(85, 170, 0, 175);");
                    ui->labelCheck->setText(QString(tr("Valid Dofus location.")));
                    ui->lineEditPathDofus->setEnabled(false);
                    ui->pushButtonConnect->setEnabled(true);
                    ui->pushButtonConnect->setFocus(Qt::FocusReason::MouseFocusReason);
                    ui->labelStatus->setText(tr("Waiting for credentials..."));
                    ui->progressBar->setValue(40);
                }

                else
                {
                    // Pour l'emplacement non valide
                    ui->labelCheck->setStyleSheet("color: rgba(255, 0, 0);");
                    ui->labelCheck->setText(QString(tr("Invalid dofus location.")));
                    ui->lineEditPathDofus->setEnabled(true);
                    ui->pushButtonConnect->setEnabled(false);
                    ui->labelStatus->setText(tr("Waiting for dofus location..."));
                    ui->progressBar->setValue(10);
                }
            }

            else
            {
                // Pour l'emplacement non valide
                ui->labelCheck->setStyleSheet("color: rgba(255, 0, 0);");
                ui->labelCheck->setText(QString(tr("Invalid dofus location.")));
                ui->lineEditPathDofus->setEnabled(true);
                ui->pushButtonConnect->setEnabled(false);
                ui->labelStatus->setText(tr("Waiting for dofus location..."));
                ui->progressBar->setValue(10);
            }
        }

        else
        {
            // Pour l'emplacement non valide
            ui->labelCheck->setStyleSheet("color: rgba(255, 0, 0);");
            ui->labelCheck->setText(QString(tr("Invalid dofus location.")));
            ui->lineEditPathDofus->setEnabled(true);
            ui->pushButtonConnect->setEnabled(false);
            ui->labelStatus->setText(tr("Waiting for dofus location..."));
            ui->progressBar->setValue(10);
        }
    }
}

void ConnectionDialog::on_pushButtonConnect_clicked()
{
    ui->labelStatus->setText(tr("Connection to server in progress..."));
    ui->progressBar->setValue(60);
    // TODO : Etablir la connexion au serveur..

    ui->labelStatus->setText(tr("Connection to account in progress..."));
    ui->progressBar->setValue(80);
    // TODO : Etablir la connexion au compte SweatedBox..

    ui->labelStatus->setText(tr("Launch SweatedBox..."));
    ui->progressBar->setValue(100);

    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    close();
}

void ConnectionDialog::init()
{
    QSqlQuery query;
    query.prepare("SELECT dofus_path, d2o , d2p , i18n FROM globalParameters");

    if(query.exec())
    {
        while(query.next())
        {
            m_path = query.value(0).toString();
            D2O = query.value(1).toString();
            D2P = query.value(2).toString();
            I18N = query.value(3).toString();
        }
    }

    if(!m_path.isEmpty())
        ui->lineEditPathDofus->setText(m_path);

    if(ui->lineEditPathDofus->text().isEmpty())
    {
        ui->labelCheck->setText(QString(tr("Select '<b>Dofus</b>' folder")));
        ui->pushButtonConnect->setEnabled(false);
        ui->labelStatus->setText(tr("Initializing game data..."));
        ui->progressBar->setValue(10);
    }
}
