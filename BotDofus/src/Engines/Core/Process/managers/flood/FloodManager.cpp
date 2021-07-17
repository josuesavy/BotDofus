#include "FloodManager.h"

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

FloodManager::FloodManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::FLOOD, connectionsData)
{

}

void FloodManager::reset(SocketIO *sender)
{

}

void FloodManager::sendChatMessage(SocketIO *sender, const QString &messageContent, const Channel &channel)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ChatClientMultiMessage message;
        message.content = messageContent;
        message.channel = channel;

        sender->send(message);
    }
}

void FloodManager::setFloodLevels(SocketIO *sender, int min, int max)
{
    if (min >= 1 && max <= 200)
    {
        m_botData[sender].floodData.levelMin = min;
        m_botData[sender].floodData.levelMax = max;
    }
}

void FloodManager::sendChatMessage(SocketIO *sender, const QString &messageContent, const QString &receiver)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        QSharedPointer<PlayerSearchCharacterNameInformation> playerSearchCharacterNameInformation = QSharedPointer<PlayerSearchCharacterNameInformation>(new PlayerSearchCharacterNameInformation);
        playerSearchCharacterNameInformation->name = receiver;

        ChatClientPrivateMessage message;
        message.content = messageContent.toUtf8();
        message.receiver = playerSearchCharacterNameInformation;
        sender->send(message);
    }
}

void FloodManager::sendChatSmiley(SocketIO *sender, uint smileyId)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        ChatSmileyRequestMessage csrmsg;
        csrmsg.smileyId = smileyId;
        sender->send(csrmsg);
    }
}

void FloodManager::initFlood(SocketIO *sender, const QList<Channel> &channels)
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
            qDebug()<<"ERREUR - FloodManager ne connait pas cette channel"<<channel;
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

void FloodManager::processFloodWaiting()
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

void FloodManager::endFlood(SocketIO *sender)
{
    m_botData[sender].floodData.channelList.clear();
    m_botData[sender].floodData.floodMessage.clear();
}

void FloodManager::addFloodChannel(SocketIO *sender, const Channel &channel)
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
        throw "ERREUR - FloodManager ne connait pas cette channel";
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

void FloodManager::removeFloodChannel(SocketIO *sender, const Channel &channel)
{
    m_botData[sender].floodData.channelList.removeOne(channel);
}

void FloodManager::modifyFloodMessage(SocketIO *sender, const QString &message)
{
    if (!m_botData[sender].floodData.isUsingFile)
        m_botData[sender].floodData.floodMessage = message;
}

QString FloodManager::randomizeFloodMessage()
{
    QList<QString> list;
    list<<"#"<<"\""<<"'"<<"@"<<"$"<<"%"<<"/"<<".";

    return " "+list[rand() % list.size()]+list[rand() % list.size()];
}

void FloodManager::setIsUsingFile(SocketIO* sender, const bool isUsingFile)
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

bool FloodManager::loadTimerFromFile(SocketIO* sender, const uint timer)
{
    if (!timer || !m_botData[sender].floodData.isUsingFile)
        return false;

    m_botData[sender].floodData.changeTimer = timer;
    return true;
}

bool FloodManager::loadMessagesFromFile(SocketIO* sender, const QStringList messages)
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

void FloodManager::changeFloodMessage()
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

void FloodManager::setFileContent(SocketIO *sender, QByteArray content)
{
    m_botData[sender].floodData.fileContent = content;
}

QByteArray FloodManager::getFileContent(SocketIO *sender)
{
    return m_botData[sender].floodData.fileContent;
}

bool FloodManager::getIsUsingFile(SocketIO *sender)
{
    return m_botData[sender].floodData.isUsingFile;
}
