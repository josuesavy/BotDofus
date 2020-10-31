#include "FloodModule.h"

bool operator<(const FloodRequest &left, const FloodRequest &right)
{
    int a = left.estimatedTime - (left.elapsedTime.elapsed()/1000);
    int b = right.estimatedTime - (right.elapsedTime.elapsed()/1000);

    if (a < b)
        return false;
    else
        return true;
}

bool operator!=(const FloodRequest &left, const FloodRequest &right)
{
    if (left.channel == right.channel)
        if (left.elapsedTime == right.elapsedTime)
            if (left.estimatedTime == right.estimatedTime)
                if (left.sender == right.sender)
                    return false;
    return true;
}

bool operator==(const FloodRequest &left, const FloodRequest &right)
{
    if (left.channel == right.channel)
        if (left.elapsedTime == right.elapsedTime)
            if (left.estimatedTime == right.estimatedTime)
                if (left.sender == right.sender)
                    return true;
    return false;
}

FloodModule::FloodModule(QMap<SocketIO*, BotData> *connectionsData) :
    AbstractModule(ModuleType::FLOOD, connectionsData)
{
}

FloodModule::~FloodModule()
{
}

void FloodModule::reset(SocketIO *sender)
{
    //m_botData[sender].floodData.cleverBot.clear();
}

bool FloodModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHATSERVERWITHOBJECTMESSAGE:
    {
        ChatServerWithObjectMessage message;
        message.deserialize(&reader);

        LogMessage chat;
        chat.channel = (Channel)message.channel;
        chat.timeStamp = QDateTime::currentDateTime().toTime_t();

        QString contentModified = message.content;
        foreach(QSharedPointer<ObjectItem> object, message.objects)
        {
            QSharedPointer<ItemData> itemData = D2OManagerSingleton::get()->getItem(object->objectGID);
            if(contentModified.contains("\uFFFC")) // Object replacement character
            {
                int index = contentModified.indexOf("\uFFFC");
                contentModified.replace(index,QString("\uFFFC").length(), "<b>["+itemData->getName()+"]</b>");
            }
        }

        chat.output = "<b>"+message.senderName+"</b> : "+contentModified;
        m_botData[sender].generalData.logMessages<<chat;
    }
        break;

    case MessageEnum::CHATSERVERMESSAGE:
    {
        ChatServerMessage message;
        message.deserialize(&reader);

        LogMessage chat;
        chat.channel = (Channel)message.channel;
        chat.timeStamp = QDateTime::currentDateTime().toTime_t();
        if(message.channel == Channel::CHANNELPRIVATE)
            chat.output = "de <b>"+message.senderName+"</b> : "+message.content;
        else
            chat.output = "<b>"+message.senderName+"</b> : "+message.content;

        m_botData[sender].generalData.logMessages<<chat;
    }
        break;

    case MessageEnum::CHATSERVERCOPYMESSAGE:
    {
        ChatServerCopyMessage message;
        message.deserialize(&reader);

        LogMessage chat;
        chat.channel = (Channel)message.channel;
        chat.timeStamp = QDateTime::currentDateTime().toTime_t();
        chat.output = "à <b>"+message.receiverName+"</b> : "+message.content+"";

        m_botData[sender].generalData.logMessages<<chat;
    }
        break;

    case MessageEnum::CHATERRORMESSAGE:
    {
        ChatErrorMessage message;
        message.deserialize(&reader);

        switch((ChatErrorEnum)message.reason)
        {
        case ChatErrorEnum::CHAT_ERROR_INTERIOR_MONOLOGUE:
        case ChatErrorEnum::CHAT_ERROR_INVALID_MAP:
        case ChatErrorEnum::CHAT_ERROR_NO_GUILD:
        case ChatErrorEnum::CHAT_ERROR_NO_PARTY:
        case ChatErrorEnum::CHAT_ERROR_RECEIVER_NOT_FOUND:
        case ChatErrorEnum::CHAT_ERROR_NO_PARTY_ARENA:
        case ChatErrorEnum::CHAT_ERROR_NO_TEAM:
        case ChatErrorEnum::CHAT_ERROR_NO_CHANNEL_COMMUNITY:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText(QString("ui.chat.error.%1").arg(message.reason));
            break;

        case ChatErrorEnum::CHAT_ERROR_ALLIANCE:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.chat.error.0");
            break;
        }
    }
        break;

    case MessageEnum::GAMEROLEPLAYSHOWACTORMESSAGE:
    {
        GameRolePlayShowActorMessage message;
        message.deserialize(&reader);

        if (message.informations->contextualId  > 0)
        {
            QSharedPointer<GameRolePlayCharacterInformations> rolePlay = qSharedPointerCast<GameRolePlayCharacterInformations>(message.informations);

            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].entityId = rolePlay->contextualId;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].cellId = rolePlay->disposition->cellId;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].level = rolePlay->alignmentInfos.characterPower - rolePlay->contextualId;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].direction = rolePlay->disposition->direction;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].name = rolePlay->name;

            if (m_botData[sender].floodData.channelList.contains(CHANNELPRIVATE))
            {
                if (m_botData[sender].generalData.botState == INACTIVE_STATE &&
                        (rolePlay->alignmentInfos.characterPower - rolePlay->contextualId) >= m_botData[sender].floodData.levelMin &&
                        (rolePlay->alignmentInfos.characterPower - rolePlay->contextualId) <= m_botData[sender].floodData.levelMax)
                {
                    QStringList splited = m_botData[sender].floodData.floodMessage.split("##", QString::SkipEmptyParts);
                    for (int i = 0; i < splited.size(); i++)
                    {
                        if (splited[i] == "NAME")
                            splited.replace(i, rolePlay->name);
                    }

                    QString randomPart = randomizeFloodMessage();
                    sendChatMessage(sender, splited.join(" ")+randomPart, rolePlay->name);
                }


                else if (m_botData[sender].generalData.botState != INACTIVE_STATE)
                    qDebug()<<"ERREUR - FloodModule ne peut lancer le flood car le bot est occupé";
            }
        }
    }
        break;

    }

    return messageFound;
}

void FloodModule::sendChatMessage(SocketIO *sender, const QString &messageContent, const Channel &channel)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ChatClientMultiMessage message;
        message.content = messageContent;
        message.channel = channel;

        sender->send(message);
    }
}

void FloodModule::setFloodLevels(SocketIO *sender, int min, int max)
{
    if (min >= 1 && max <= 200)
    {
        m_botData[sender].floodData.levelMin = min;
        m_botData[sender].floodData.levelMax = max;
    }
}

void FloodModule::sendChatMessage(SocketIO *sender, const QString &messageContent, const QString &receiver)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ChatClientPrivateMessage message;
        message.content = messageContent.toUtf8();
        message.receiver = receiver;
        sender->send(message);
    }
}

void FloodModule::sendChatSmiley(SocketIO *sender, uint smileyId)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ChatSmileyRequestMessage csrmsg;
        csrmsg.smileyId = smileyId;
        sender->send(csrmsg);
    }
}

void FloodModule::initFlood(SocketIO *sender, const QList<Channel> &channels)
{
    m_botData[sender].floodData.channelList.clear();
    foreach (Channel channel, channels)
    {
        if (!m_botData[sender].floodData.channelList.contains(channel))
            m_botData[sender].floodData.channelList<<channel;

        FloodRequest temp;
        temp.sender = sender;
        temp.channel = channel;
        temp.elapsedTime.start();

        switch (channel)
        {
        default:
            qDebug()<<"ERREUR - FloodModule ne connait pas cette channel"<<channel;
            break;

        case CHANNELSALES:
            temp.estimatedTime = 120000;
            break;

        case CHANNELSEEK:
            temp.estimatedTime = 60000;
            break;

        case CHANNELGLOBAL:
            temp.estimatedTime = 35000;
            break;

        case CHANNELPRIVATE:
        {
            if (!m_botData[sender].floodData.channelList.contains(channel))
                m_botData[sender].floodData.channelList<<channel;
        }
            break;
        }

        m_floodRequests<<temp;
        m_botData[sender].floodData.timer.start();
        QTimer::singleShot(temp.estimatedTime, this, SLOT(processFloodWaiting()));
        QTimer::singleShot(m_botData[sender].floodData.changeTimer*60000, this, SLOT(changeFloodMessage()));
    }
}

void FloodModule::processFloodWaiting()
{
    int toTest = m_floodRequests[0].estimatedTime - m_floodRequests[0].elapsedTime.elapsed();
    int selected = 0;
    for (int i = 0; i < m_floodRequests.size(); i++)
    {
        if ((m_floodRequests[i].estimatedTime - m_floodRequests[i].elapsedTime.elapsed()) < toTest)
        {
            selected = i;
            toTest =  m_floodRequests[i].estimatedTime - m_floodRequests[i].elapsedTime.elapsed();
        }
    }

    FloodRequest temp = m_floodRequests[selected];

    if (m_botData[temp.sender].floodData.channelList.contains(temp.channel))
    {
        QString randomPart = randomizeFloodMessage();
        sendChatMessage(temp.sender, m_botData[temp.sender].floodData.floodMessage+randomPart, temp.channel);

        m_floodRequests[0].elapsedTime.restart();
        QTimer::singleShot(temp.estimatedTime, this, SLOT(processFloodWaiting()));
    }

    else
        m_floodRequests.removeFirst();
}

void FloodModule::endFlood(SocketIO *sender)
{
    m_botData[sender].floodData.channelList.clear();
    m_botData[sender].floodData.floodMessage.clear();
}

void FloodModule::addFloodChannel(SocketIO *sender, const Channel &channel)
{
    if (!m_botData[sender].floodData.channelList.contains(channel))
        m_botData[sender].floodData.channelList<<channel;

    FloodRequest temp;
    temp.sender = sender;
    temp.channel = channel;
    temp.elapsedTime.start();

    switch (channel)
    {
    default:
        throw "ERREUR - FloodModule ne connait pas cette channel";
        break;

    case CHANNELSALES:
        temp.estimatedTime = 120000;
        break;

    case CHANNELSEEK:
        temp.estimatedTime = 60000;
        break;

    case CHANNELGLOBAL:
        temp.estimatedTime = 35000;
        break;

    case CHANNELPRIVATE:
    {
        if (!m_botData[sender].floodData.channelList.contains(channel))
            m_botData[sender].floodData.channelList<<channel;
    }
        break;
    }

    m_floodRequests<<temp;
    QTimer::singleShot(temp.estimatedTime, this, SLOT(processFloodWaiting()));
}

void FloodModule::removeFloodChannel(SocketIO *sender, const Channel &channel)
{
    m_botData[sender].floodData.channelList.removeOne(channel);
}

void FloodModule::modifyFloodMessage(SocketIO *sender, const QString &message)
{
    if (!m_botData[sender].floodData.isUsingFile)
        m_botData[sender].floodData.floodMessage = message;
}

QString FloodModule::randomizeFloodMessage()
{
    QList<QString> list;
    list<<"#"<<"\""<<"'"<<"@"<<"$"<<"%"<<"/"<<".";

    return " "+list[rand() % list.size()]+list[rand() % list.size()];
}

void FloodModule::setIsUsingFile(SocketIO* sender, const bool isUsingFile)
{
    m_botData[sender].floodData.isUsingFile = isUsingFile;

    if (!isUsingFile)
    {
        m_botData[sender].floodData.changeTimer = 0;
        m_botData[sender].floodData.messageIndex = -1;
        m_botData[sender].floodData.messageFile.clear();
        m_botData[sender].floodData.floodMessage.clear();
    }
}

bool FloodModule::loadTimerFromFile(SocketIO* sender, const uint timer)
{
    if (!timer || !m_botData[sender].floodData.isUsingFile)
        return false;

    m_botData[sender].floodData.changeTimer = timer;
    return true;
}

bool FloodModule::loadMessagesFromFile(SocketIO* sender, const QStringList messages)
{
    if (messages.isEmpty())
        return false;

    foreach (QString str, messages)
    {
        QString s = str;
        s.simplified();
        s.replace(" ", "");

        if (s.isEmpty())
            return false;
    }

    m_botData[sender].floodData.messageIndex++;
    m_botData[sender].floodData.messageFile = messages;
    m_botData[sender].floodData.floodMessage = messages.first();
    return true;
}

void FloodModule::changeFloodMessage()
{
    QMap<SocketIO*, uint> time;
    foreach (SocketIO* sender, m_botData.keys())
    {
        qDebug() << m_botData[sender].floodData.changeTimer*60000 - m_botData[sender].floodData.timer.elapsed();
        time[sender] = m_botData[sender].floodData.changeTimer - m_botData[sender].floodData.timer.elapsed();
    }

    int a = 99999;
    SocketIO* selected;
    foreach (int val, time.values())
    {
        if (val < a)
        {
            a = val;
            selected = time.key(val);
        }
    }

    if (m_botData[selected].floodData.isUsingFile && !m_botData[selected].floodData.messageFile.isEmpty())
    {
        m_botData[selected].floodData.messageIndex++;
        m_botData[selected].floodData.floodMessage = m_botData[selected].floodData.messageFile[m_botData[selected].floodData.messageIndex % m_botData[selected].floodData.messageFile.size()];
        QTimer::singleShot(m_botData[selected].floodData.changeTimer*60000, this, SLOT(changeFloodMessage()));
        m_botData[selected].floodData.timer.restart();
    }

}

void FloodModule::setFileContent(SocketIO *sender, QByteArray content)
{
    m_botData[sender].floodData.fileContent = content;
}

QByteArray FloodModule::getFileContent(SocketIO *sender)
{
    return m_botData[sender].floodData.fileContent;
}

bool FloodModule::getIsUsingFile(SocketIO *sender)
{
    return m_botData[sender].floodData.isUsingFile;
}
