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
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {
        ui->groupBox->setEnabled(false);
    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        ui->groupBox->setEnabled(false);
    }
}

void SettingsForm::hasConnected()
{
    ui->labelLoader->setStyleSheet("color: rgba(85, 170, 0, 175);");
    ui->labelLoader->setText(QString(tr("The proxy server appears to be in place.")));
    m_sender->setProxy(m_proxy);

    ui->progressBarCheckProxy->hide();
}

void SettingsForm::hasDisconnected()
{
    ui->labelLoader->setStyleSheet("color: rgba(255, 0, 0);");
    ui->labelLoader->setText(QString(tr("The proxy server does not appear to be in place.")));

    ui->progressBarCheckProxy->hide();
}

void SettingsForm::on_checkBoxAutoReconnect_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked) // Unchecked
        m_engine->getConnectionManager().setReconnectionAuto(m_sender, false);

    else if(arg1 == Qt::Checked) // Checked
        m_engine->getConnectionManager().setReconnectionAuto(m_sender, true);
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

    QTcpSocket *socket = new QTcpSocket();
    socket->setProxy(proxyTemp);
    socket->connectToHost("34.252.21.81", 5555);

    QObject::connect(socket, SIGNAL(connected()), this, SLOT(hasConnected()));
    QObject::connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(hasDisconnected()));
}

void SettingsForm::on_groupBox_6_clicked(bool checked)
{
    if(!checked)
    {
        ProxyInfos proxy;
        proxy.adress = "";
        m_sender->setProxy(proxy);
    }

    ui->pushButtonCheckAndApplyProxy->setEnabled(checked);
    ui->labelLoader->clear();
}

void SettingsForm::on_comboBoxStatus_currentIndexChanged(int index)
{
    if(index == 0)
        m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_AVAILABLE);
    else if(index == 1)
        m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_AFK);
    else if(index == 2)
    {
        bool ok;
        QString text = QInputDialog::getText(this, tr("Away message"), tr("Away reason :"), QLineEdit::Normal, QString(), &ok);
        if (ok && !text.isEmpty())
            m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_AFK, text);
        else if(ok && text.isEmpty())
            m_engine->getStatsManager().setPlayerStatusUpdate(m_sender, PlayerStatusEnum::PLAYER_STATUS_AFK);
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
