#include "ProcessEngine.h"

ProcessEngine::ProcessEngine()
{
    connect(m_managers[ModuleType::CONNECTION], SIGNAL(connectionAdded(SocketIO*)), this, SLOT(connectToSocket(SocketIO*)));
    connect(m_managers[ModuleType::CONNECTION], SIGNAL(botDisconnected(SocketIO*)), this, SLOT(resetModules(SocketIO*)));

    foreach (AbstractFrame *frame, m_frames)
    {
        connect(frame, SIGNAL(requestUpdate(SocketIO*)), this, SLOT(processUpdateRequest(SocketIO*)));
    }
}

void ProcessEngine::resetModules(SocketIO *sender)
{
    foreach(AbstractFrame *frame, m_frames)
        frame->reset(sender);

    processUpdateRequest(sender);
}

void ProcessEngine::processUpdateRequest(SocketIO *sender)
{
    if(m_botData.contains(sender))
    {
        if(m_botData[sender].generalData.logMessages.size() <= 250)
        {
            m_botData[sender].generalData.logMessageCount = m_botData[sender].generalData.logMessages.size();
        }

        while(m_botData[sender].generalData.logMessages.size() > 250)
        {
            m_botData[sender].generalData.logMessages.removeFirst();
            m_botData[sender].generalData.logMessageCount = m_botData[sender].generalData.logMessageCount - 1;
        }

        emit informationsUpdated(sender);
    }
}

void ProcessEngine::connectToSocket(SocketIO* sender)
{
    connect(sender, SIGNAL(dataReceived(QList<MessageInfos>)), this, SLOT(processData(QList<MessageInfos>)));
}

void ProcessEngine::processData(QList<MessageInfos> messages)
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());

    foreach (const MessageInfos &data, messages)
    {
        processMessage(data, sender);
    }

    processUpdateRequest(sender);
}

bool ProcessEngine::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = false;

    foreach (AbstractFrame *frame, m_frames)
    {
        if(frame->processMessage(data, sender))
        {
            messageFound = true;
        }
    }

    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;
    }

    if (!messageFound)
        qDebug()<<"MESSAGE PROCESS - Aucun support du message -"<<MessageUtils::getName(data.messageType)<<"- ID :"<<(int)data.messageType<<"\n";

    return messageFound;
}
