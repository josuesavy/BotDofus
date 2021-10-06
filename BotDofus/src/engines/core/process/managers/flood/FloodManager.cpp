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

FloodManager::~FloodManager()
{

}

void FloodManager::reset(SocketIO *sender)
{
    m_botData[sender].floodData.floodList.clear();
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

void FloodManager::startFlood(SocketIO *sender)
{
    foreach (FloodRequest floodRequest, m_floodRequests)
    {
        floodRequest.elapsedTime.start();
    }
}

void FloodManager::processFloodWaiting()
{
    // Get the flood that has the smallest time value to send
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

    foreach (FloodMessage flood, m_botData[temp.sender].floodData.floodList)
    {
        if (flood.message == temp.message && flood.channel == temp.channel)
        {
            QString randomPart = randomizeFloodMessage();
            sendChatMessage(temp.sender, flood.message+randomPart, temp.channel);

            m_floodRequests[0].elapsedTime.restart();
            QTimer::singleShot(temp.estimatedTime, this, SLOT(processFloodWaiting()));
        }
        else
            m_floodRequests.removeFirst();
    }
}

void FloodManager::endFlood(SocketIO *sender)
{
    m_floodRequests.clear();
}

void FloodManager::addFloodChannel(SocketIO *sender, const FloodMessage &flood)
{
    bool found = false;
    foreach (FloodMessage floodMessage, m_botData[sender].floodData.floodList)
    {
        if (floodMessage.message == flood.message && flood.channel == floodMessage.channel && floodMessage.timer == flood.timer)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        m_botData[sender].floodData.floodList<<flood;
    }

    FloodRequest temp;
    temp.sender = sender;
    temp.channel = flood.channel;
    temp.message = flood.message;
    temp.elapsedTime.start();

    switch (flood.channel)
    {
    default:
        throw "ERROR - FloodManager don't know this channel";
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
        bool found = false;
        foreach (FloodMessage floodMessage, m_botData[sender].floodData.floodList)
        {
            if (floodMessage.message == flood.message && flood.channel == floodMessage.channel && floodMessage.timer == flood.timer)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            m_botData[sender].floodData.floodList<<flood;
        }
    }
        break;
    }

    m_floodRequests<<temp;
    QTimer::singleShot(temp.estimatedTime, this, SLOT(processFloodWaiting()));
}

void FloodManager::removeFloodChannel(SocketIO *sender, const FloodMessage &flood)
{
    int index = INVALID;
    foreach (FloodMessage floodMessage, m_botData[sender].floodData.floodList)
    {
        index++;
        if (floodMessage.message == flood.message && flood.channel == floodMessage.channel && floodMessage.timer == flood.timer)
        {
            break;
        }
    }

    if (index > INVALID)
    {
        m_botData[sender].floodData.floodList.removeAt(index);
    }
}

QString FloodManager::randomizeFloodMessage()
{
    QList<QString> list;
    list<<"#"<<"\""<<"'"<<"@"<<"$"<<"%"<<"/"<<".";

    return " "+list[rand() % list.size()]+list[rand() % list.size()];
}
