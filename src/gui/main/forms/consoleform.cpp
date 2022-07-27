#include "consoleform.h"
#include "ui_consoleform.h"

ConsoleForm::ConsoleForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConsoleForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;
}

ConsoleForm::~ConsoleForm()
{
    delete ui;
}

SocketIO *ConsoleForm::getSocket()
{
    return m_sender;
}

QString ConsoleForm::getTime(uint timeStamp)
{
    QString date = "";

    QTime time = QDateTime::fromTime_t(timeStamp).time();
    int hours = time.hour();
    int minutes = time.minute();
    int seconds = time.second();

    if (hours < 10)
        date += "0"+QString::number(hours);
    else
        date += QString::number(hours);

    date += ":";

    if (minutes < 10)
        date += "0"+QString::number(minutes);
    else
        date += QString::number(minutes);

    date += ":";

    if (seconds < 10)
        date += "0"+QString::number(seconds);
    else
        date += QString::number(seconds);

    return date;
}

ConnectionInfos ConsoleForm::getConnectionInfos() const
{
    return m_infos;
}

const BotData &ConsoleForm::getData() const
{
    return m_engine->getData(m_sender);
}

void ConsoleForm::updateInterface()
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ui->comboBoxCanal->setEnabled(true);
        ui->lineEditConsole->setEnabled(true);
        ui->pushButtonSmiley->setEnabled(true);
        ui->pushButtonSend->setEnabled(true);
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        ui->comboBoxCanal->setEnabled(false);
        ui->lineEditConsole->setEnabled(false);
        ui->pushButtonSmiley->setEnabled(false);
        ui->pushButtonSend->setEnabled(false);

        if(ui->comboBoxCanal->currentIndex() != 0)
            ui->comboBoxCanal->setCurrentIndex(0);
    }

    if (infos.generalData.logMessageCount != m_logMessageCount)
    {
        for(int i = m_logMessageCount; i < infos.generalData.logMessageCount; i++)
        {
            QString htmlOutput = toHtml(infos.generalData.logMessages[i].output);

            switch (infos.generalData.logMessages[i].channel)
            {
            default:
                ui->textBrowserConsole->append("<font color=red> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - La chaine demandée n'existe pas</font>");
                break;

            case CHANNELDEBUG:
                ui->textBrowserConsole->append("<font color="+QString(DEBUG_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Debug) "+htmlOutput+"</font>");
                break;

            case CHANNELGLOBAL:
                ui->textBrowserConsole->append("<font color="+QString(GLOBAL_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELTEAM:
                ui->textBrowserConsole->append("<font color="+QString(TEAM_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Equipe) "+htmlOutput+"</font>");
                break;

            case CHANNELGUILD:
                ui->textBrowserConsole->append("<font color="+QString(GUILD_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Guilde) "+htmlOutput+"</font>");
                break;

            case CHANNELALLIANCE:
                ui->textBrowserConsole->append("<font color="+QString(ALLIANCE_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Alliance) "+htmlOutput+"</font>");
                break;

            case CHANNELPARTY:
                ui->textBrowserConsole->append("<font color="+QString(PARTY_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Groupe) "+htmlOutput+"</font>");
                break;

            case CHANNELSALES:
                ui->textBrowserConsole->append("<font color="+QString(SALES_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Commerce) "+htmlOutput+"</font>");
                break;

            case CHANNELSEEK:
                ui->textBrowserConsole->append("<font color="+QString(SEEK_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Recrutement) "+htmlOutput+"</font>");
                break;

            case CHANNELNOOB:
                ui->textBrowserConsole->append("<font color="+QString(NOOB_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELADMIN:
                ui->textBrowserConsole->append("<font color="+QString(ADMIN_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] - "+htmlOutput+"</font>");
                break;

            case CHANNELADS:
                ui->textBrowserConsole->append("<font color="+QString(ADS_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Communauté FR) "+htmlOutput+"</font>");
                break;

            case CHANNELARENA:
                ui->textBrowserConsole->append("<font color="+QString(ARENA_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] (Kolizéum) "+htmlOutput+"</font>");
                break;

            case CHANNELPRIVATE:
                ui->textBrowserConsole->append("<font color="+QString(PRIVATE_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELINFO:
                ui->textBrowserConsole->append("<font color="+QString(INFO_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELFIGHTLOG:
                ui->textBrowserConsole->append("<font color="+QString(FIGHT_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELALERT:
                ui->textBrowserConsole->append("<font color="+QString(ERROR_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELACTION:
                ui->textBrowserConsole->append("<font color="+QString(ACTION_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELWARN:
                ui->textBrowserConsole->append("<font color="+QString(WARN_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELCOMMUNITY:
                ui->textBrowserConsole->append("<font color="+QString(COMMUNITY_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;

            case CHANNELPROMOTION:
                ui->textBrowserConsole->append("<font color="+QString(PROMOTION_COLOR)+"> ["+getTime(infos.generalData.logMessages[i].timeStamp)+"] "+htmlOutput+"</font>");
                break;
            }
        }

        m_logMessageCount = infos.generalData.logMessageCount;
    }
}

void ConsoleForm::on_lineEditConsole_returnPressed()
{
    ui->pushButtonSend->click();
}

void ConsoleForm::on_pushButtonSmiley_clicked()
{
    SmileysDialog smileysDialog;
    smileysDialog.setParent(this, Qt::Dialog);
    QList<QString> smileysHappyList;
    QList<QString> smileysSadList;
    QList<QString> smileysOtherList;

    QList<int> listID = D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::SMILEYS);
    for(int i = 0; i < listID.size(); i++)
    {
        QSharedPointer<SmileyData> smileyData = qSharedPointerCast<SmileyData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SMILEYS, listID.at(i)));
        if(smileyData)
        {
            if(smileyData->getForPlayers() && smileyData->getOrder() && !smileyData->getReferenceId())
            {
                if(smileyData->getCategoryId() == 1)
                    smileysOtherList.append(QString("%1|%2|%3").arg(smileyData->getGfxId()).arg(smileyData->getId()).arg(smileyData->getOrder()));

                if(smileyData->getCategoryId() == 2)
                    smileysHappyList.append(QString("%1|%2|%3").arg(smileyData->getGfxId()).arg(smileyData->getId()).arg(smileyData->getOrder()));

                if(smileyData->getCategoryId() == 3)
                    smileysSadList.append(QString("%1|%2|%3").arg(smileyData->getGfxId()).arg(smileyData->getId()).arg(smileyData->getOrder()));
            }
        }
    }

    smileysDialog.setSmileysHappy(smileysHappyList);
    smileysDialog.setSmileysSad(smileysSadList);
    smileysDialog.setSmileysOther(smileysOtherList);
    if(smileysDialog.exec() == QDialog::Accepted)
    {
        qDebug() << smileysDialog.smiley.toInt();
        m_engine->getFloodManager().sendChatSmiley(m_sender, smileysDialog.smiley.toInt());
    }
}

void ConsoleForm::on_pushButtonSend_clicked()
{
    if (!ui->lineEditConsole->text().isEmpty())
    {
        Channel channel;

        switch (ui->comboBoxCanal->currentIndex())
        {
        case 0:
            channel = CHANNELGLOBAL;
            break;
        case 1:
            channel = CHANNELTEAM;
            break;
        case 2:
            channel = CHANNELGUILD;
            break;
        case 3:
            channel = CHANNELALLIANCE;
            break;
        case 4:
            channel = CHANNELPARTY;
            break;
        case 5:
            channel = CHANNELPRIVATE;
            break;
        case 6:
            channel = CHANNELARENA;
            break;
        case 7:
            channel = CHANNELCOMMUNITY;
            break;
        case 8:
            channel = CHANNELSALES;
            break;
        case 9:
            channel = CHANNELSEEK;
            break;
        }

        QString content = ui->lineEditConsole->text();
        //QRegExp pattern("%[a-z]+%");

        if(channel == Channel::CHANNELPRIVATE)
            m_engine->getFloodManager().sendChatMessage(m_sender, content.remove(content.split(" ").at(0)+" "), content.split(" ").at(0));
        else
            m_engine->getFloodManager().sendChatMessage(m_sender, content, channel);

        ui->lineEditConsole->setText("");
    }
}

void ConsoleForm::on_comboBoxCanal_currentIndexChanged(int index)
{
    if((Channel)index == Channel::CHANNELPRIVATE)
        ui->lineEditConsole->setPlaceholderText("Player_Name [message]");
    else
        ui->lineEditConsole->setPlaceholderText("");
}
