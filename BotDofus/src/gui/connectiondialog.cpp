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
        qDebug() << "Connected Successfully to DB !";
    else
        qDebug()<<"Le fichier"<<USER_DATA_PATH<<"ne peut pas etre ouvert/créé";

    init();
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::on_pushButtonBrowser_clicked()
{
    QString path = QFileDialog::getExistingDirectory(nullptr, "Selectionner un répertoire");
    m_path = path;
    ui->lineEditPathDofus->setText(path);
}

void ConnectionDialog::on_lineEditPathDofus_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->labelCheck->setStyleSheet("");
        ui->labelCheck->setText(QString(tr("Sélectionnez le dossier '<b>Dofus</b>'")));
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
                        // ServerHandlerSingleton::get()->init();
                        D2OManagerSingleton::get()->init(D2O, I18N);
                        D2PManagerSingleton::get()->init(D2P);
                        PathfindingMap::initialize();
                    }

                    // Pour l'emplacement valide
                    ui->labelCheck->setStyleSheet("color: rgba(85, 170, 0, 175);");
                    ui->labelCheck->setText(QString(tr("Emplacement Dofus valide.")));
                    ui->lineEditPathDofus->setEnabled(false);
                    ui->pushButtonConnect->setEnabled(true);
                    ui->pushButtonConnect->setFocus(Qt::FocusReason::MouseFocusReason);
                    ui->labelStatus->setText(tr("En attente de connexion..."));
                    ui->progressBar->setValue(40);
                    qApp->processEvents();
                }

                else
                {
                    // Pour l'emplacement non valide
                    ui->labelCheck->setStyleSheet("color: rgba(255, 0, 0);");
                    ui->labelCheck->setText(QString(tr("Emplacement Dofus non valide")));
                    ui->lineEditPathDofus->setEnabled(true);
                    ui->pushButtonConnect->setEnabled(false);
                    ui->labelStatus->setText(tr("Initialisation des données du jeu..."));
                    ui->progressBar->setValue(10);
                    qApp->processEvents();
                }
            }

            else
            {
                // Pour l'emplacement non valide
                ui->labelCheck->setStyleSheet("color: rgba(255, 0, 0);");
                ui->labelCheck->setText(QString(tr("Emplacement Dofus non valide")));
                ui->lineEditPathDofus->setEnabled(true);
                ui->pushButtonConnect->setEnabled(false);
                ui->labelStatus->setText(tr("Initialisation des données du jeu..."));
                ui->progressBar->setValue(10);
                qApp->processEvents();
            }
        }

        else
        {
            // Pour l'emplacement non valide
            ui->labelCheck->setStyleSheet("color: rgba(255, 0, 0);");
            ui->labelCheck->setText(QString(tr("Emplacement Dofus non valide")));
            ui->lineEditPathDofus->setEnabled(true);
            ui->pushButtonConnect->setEnabled(false);
            ui->labelStatus->setText(tr("Initialisation des données du jeu..."));
            ui->progressBar->setValue(10);
            qApp->processEvents();
        }
    }
}

void ConnectionDialog::on_pushButtonConnect_clicked()
{
    ui->labelStatus->setText(tr("Connexion au serveur..."));
    ui->progressBar->setValue(60);
    qApp->processEvents();
    // TODO : Etablir la connexion au serveur..

    ui->labelStatus->setText(tr("Connexion au compte en cours..."));
    ui->progressBar->setValue(80);
    qApp->processEvents();
    // TODO : Etablir la connexion au compte SweatedBox..

    ui->labelStatus->setText(tr("Lancement de SweatedBox..."));
    ui->progressBar->setValue(100);
    qApp->processEvents();

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
        ui->labelCheck->setText(QString(tr("Sélectionnez le dossier '<b>Dofus</b>'")));
        ui->pushButtonConnect->setEnabled(false);
        ui->labelStatus->setText(tr("Initialisation des données du jeu..."));
        ui->progressBar->setValue(10);
    }
}
