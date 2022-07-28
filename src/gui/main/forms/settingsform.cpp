#include "settingsform.h"
#include "ui_settingsform.h"

SettingsForm::SettingsForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;

    currentIndexSelected = 0;

    ui->tabWidgetOptions->setCurrentIndex(0);
    ui->pushButtonCheckAndApplyProxy->setEnabled(false);
    ui->progressBarCheckProxy->hide();
}

SettingsForm::~SettingsForm()
{
    delete ui;
}

SocketIO *SettingsForm::getSocket()
{
    return m_sender;
}

ConnectionInfos SettingsForm::getConnectionInfos() const
{
    return m_infos;
}

const BotData &SettingsForm::getData() const
{
    return m_engine->getData(m_sender);
}

void SettingsForm::updateInterface()
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ui->groupBox->setEnabled(true);

        switch ((PlayerStatusEnum)infos.playerData.playerStatus)
        {
        case PlayerStatusEnum::PLAYER_STATUS_AVAILABLE:
            ui->comboBoxStatus->setCurrentIndex(0);
            break;

        case PlayerStatusEnum::PLAYER_STATUS_IDLE:
            ui->comboBoxStatus->setCurrentIndex(1);
            break;

        case PlayerStatusEnum::PLAYER_STATUS_AFK:
            ui->comboBoxStatus->setCurrentIndex(2);
            break;

        case PlayerStatusEnum::PLAYER_STATUS_PRIVATE:
            ui->comboBoxStatus->setCurrentIndex(3);
            break;

        case PlayerStatusEnum::PLAYER_STATUS_SOLO:
            ui->comboBoxStatus->setCurrentIndex(4);
            break;

        default:
            ui->comboBoxStatus->setCurrentIndex(INVALID);
            break;
        }
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {
        ui->groupBox->setEnabled(false);
        ui->comboBoxStatus->setCurrentIndex(INVALID);
    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        ui->groupBox->setEnabled(false);
        ui->comboBoxStatus->setCurrentIndex(INVALID);
    }
}

void SettingsForm::hasConnected()
{
    ui->labelLoader->setStyleSheet("color: rgba(85, 170, 0, 175);");
    ui->labelLoader->setText(QString(tr("The proxy server appears to be in place.")));
    m_sender->setProxy(m_proxy);
    m_socket.disconnectFromHost();

    ui->progressBarCheckProxy->hide();
}

void SettingsForm::hasDisconnected(QAbstractSocket::SocketError socketError)
{
    ui->labelLoader->setStyleSheet("color: rgba(255, 0, 0, 175);");
    ui->labelLoader->setText(QString(tr("The proxy server does not appear to be in place.\nError: %1")).arg(m_socket.errorString()));

    ui->progressBarCheckProxy->hide();
}

void SettingsForm::on_checkBoxAutoReconnect_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked) // Unchecked
        m_engine->getConnectionManager().setReconnectionAuto(m_sender, false);

    else if(arg1 == Qt::Checked) // Checked
        m_engine->getConnectionManager().setReconnectionAuto(m_sender, true);
}

void SettingsForm::on_checkBoPreventInactivityDisconnects_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked) // Unchecked
        m_engine->getConnectionManager().setPreventInactivityDisconnects(m_sender, false);

    else if(arg1 == Qt::Checked) // Checked
        m_engine->getConnectionManager().setPreventInactivityDisconnects(m_sender, true);
}

void SettingsForm::on_checkBoxAutoAcceptAchievement_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked) // Unchecked
        m_engine->getStatsManager().setAutomaticallyAcceptAchievement(m_sender, false);

    else if(arg1 == Qt::Checked) // Checked
        m_engine->getStatsManager().setAutomaticallyAcceptAchievement(m_sender, true);
}

void SettingsForm::on_pushButtonCheckAndApplyProxy_clicked()
{
    // Website proxy SOCKS5 : http://spys.one/en/socks-proxy-list/

    if (m_socket.state() == QAbstractSocket::HostLookupState || m_socket.state() == QAbstractSocket::ConnectingState || m_socket.state() == QAbstractSocket::ConnectedState)
    {
        m_socket.abort();
    }

    ui->labelLoader->clear();
    ui->progressBarCheckProxy->show();

    m_proxy.adress = ui->lineEditHostProxy->text();
    m_proxy.port = ui->spinBoxPortProxy->value();
    m_proxy.username = ui->lineEditAccountProxy->text();
    m_proxy.password = ui->lineEditPasswordProxy->text();
    m_proxy.type = QNetworkProxy::Socks5Proxy;

    QNetworkProxy proxyTemp;
    proxyTemp.setType(m_proxy.type);
    proxyTemp.setHostName(m_proxy.adress);
    proxyTemp.setPort(m_proxy.port);
    proxyTemp.setUser(m_proxy.username);
    proxyTemp.setPassword(m_proxy.password);

    m_socket.setProxy(proxyTemp);
    m_socket.connectToHost(MAIN_SERVER_IP, 5555);

    QObject::connect(&m_socket, SIGNAL(connected()), this, SLOT(hasConnected()));
    QObject::connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(hasDisconnected(QAbstractSocket::SocketError)));
}

void SettingsForm::on_groupBox_6_clicked(bool checked)
{
    if(!checked)
    {
        ProxyInfos proxy;
        proxy.adress.clear();
        m_sender->setProxy(proxy);

        m_sender->disconnect();
    }

    ui->pushButtonCheckAndApplyProxy->setEnabled(checked);
    ui->labelLoader->clear();
}

void SettingsForm::on_comboBoxStatus_currentIndexChanged(int index)
{
    if(index == 0)
        m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_AVAILABLE);
    else if(index == 1)
        m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_IDLE);
    else if(index == 2)
    {
        bool ok;
        QString text = QInputDialog::getText(this, tr("Away message"), tr("Away reason :"), QLineEdit::Normal, QString(), &ok);
        if (ok && !text.isEmpty())
            m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_AFK, text);
        else if(ok && text.isEmpty())
            m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_IDLE);
        else
            ui->comboBoxStatus->setCurrentIndex(currentIndexSelected);
    }
    else if(index == 3)
    {
        m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_PRIVATE);
    }
    else if(index == 4)
        m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_SOLO);

    currentIndexSelected = index;
}

