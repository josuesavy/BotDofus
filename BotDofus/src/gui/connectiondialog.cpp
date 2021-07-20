#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);

    m_dbManager = new DBManager();
    m_dbManager->setPath(USER_DATA_PATH);
    m_dbManager->initialization();

    init();
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
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

                    if (m_dbManager->isInitialized())
                    {
                        if (m_dbManager->addField("Configuration", "dofus_location", arg1.toUtf8()) && m_dbManager->addField("Configuration", "dofus_d2o_location", D2O.toUtf8()) && m_dbManager->addField("Configuration", "dofus_d2p_location", D2P.toUtf8()) && m_dbManager->addField("Configuration", "dofus_i18n_location", I18N.toUtf8()))
                        {
                            // ServerHandlerSingleton::get()->init();
                            D2OManagerSingleton::get()->init(D2O, I18N);
                            D2PManagerSingleton::get()->init(D2P);
                            PathfindingMap::initialize();

                            // Pour l'emplacement valide
                            ui->labelCheck->setStyleSheet("color: rgba(85, 170, 0, 175);");
                            ui->labelCheck->setText(QString(tr("Valid Dofus location.")));
                            ui->lineEditPathDofus->setEnabled(false);
                            ui->pushButtonConnect->setEnabled(true);
                            ui->pushButtonConnect->setFocus(Qt::FocusReason::MouseFocusReason);
                            ui->labelStatus->setText(tr("Waiting for connection..."));
                            ui->progressBar->setValue(40);
                            qApp->processEvents();
                        }
                        else
                            qDebug() << "There is one configuration not added!";
                    }
                    else
                        qDebug() << "Database not initialized!";
                }

                else
                {
                    // Pour l'emplacement non valide
                    ui->labelCheck->setStyleSheet("color: rgba(255, 0, 0);");
                    ui->labelCheck->setText(QString(tr("Invalid dofus location.")));
                    ui->lineEditPathDofus->setEnabled(true);
                    ui->pushButtonConnect->setEnabled(false);
                    ui->labelStatus->setText(tr("Initializing game data..."));
                    ui->progressBar->setValue(10);
                    qApp->processEvents();
                }
            }

            else
            {
                // Pour l'emplacement non valide
                ui->labelCheck->setStyleSheet("color: rgba(255, 0, 0);");
                ui->labelCheck->setText(QString(tr("Invalid dofus location.")));
                ui->lineEditPathDofus->setEnabled(true);
                ui->pushButtonConnect->setEnabled(false);
                ui->labelStatus->setText(tr("Initializing game data..."));
                ui->progressBar->setValue(10);
                qApp->processEvents();
            }
        }

        else
        {
            // Pour l'emplacement non valide
            ui->labelCheck->setStyleSheet("color: rgba(255, 0, 0);");
            ui->labelCheck->setText(QString(tr("Invalid dofus location.")));
            ui->lineEditPathDofus->setEnabled(true);
            ui->pushButtonConnect->setEnabled(false);
            ui->labelStatus->setText(tr("Initializing game data..."));
            ui->progressBar->setValue(10);
            qApp->processEvents();
        }
    }
}

void ConnectionDialog::on_pushButtonConnect_clicked()
{
    ui->labelStatus->setText(tr("Connection to server in progress..."));
    ui->progressBar->setValue(60);
    qApp->processEvents();
    // TODO : Etablir la connexion au serveur..

    ui->labelStatus->setText(tr("Connection to account in progress..."));
    ui->progressBar->setValue(80);
    qApp->processEvents();
    // TODO : Etablir la connexion au compte SweatedBox..

    ui->labelStatus->setText(tr("Launch SweatedBox..."));
    ui->progressBar->setValue(100);
    qApp->processEvents();

    MainWindow *mainwindow = new MainWindow(m_dbManager);
    mainwindow->show();
    close();
}

void ConnectionDialog::init()
{
    QByteArray dofus_location = m_dbManager->getField("Configuration", "dofus_location");
    if (!dofus_location.isEmpty())
        m_path = QString::fromUtf8(dofus_location);

    QByteArray dofus_d2o_location = m_dbManager->getField("Configuration", "dofus_d2o_location");
    if (!dofus_d2o_location.isEmpty())
        D2O = QString::fromUtf8(dofus_d2o_location);

    QByteArray dofus_d2p_location = m_dbManager->getField("Configuration", "dofus_d2p_location");
    if (!dofus_d2p_location.isEmpty())
        D2P = QString::fromUtf8(dofus_d2p_location);

    QByteArray dofus_i18n_location = m_dbManager->getField("Configuration", "dofus_i18n_location");
    if (!dofus_i18n_location.isEmpty())
        I18N = QString::fromUtf8(dofus_i18n_location);

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
