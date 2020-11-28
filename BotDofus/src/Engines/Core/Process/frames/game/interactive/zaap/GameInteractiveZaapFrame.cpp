#include "GameInteractiveZaapFrame.h"

GameInteractiveZaapFrame::GameInteractiveZaapFrame(QMap<SocketIO *, BotData> *connectionsData, InteractionManager *interactionManager):
    AbstractFrame(connectionsData),
    m_interactionManager(interactionManager)
{

}

bool GameInteractiveZaapFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::TELEPORTDESTINATIONSMESSAGE:
    {
        TeleportDestinationsMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].generalData.botState == BotState::INACTIVE_STATE)
        {
            foreach(TeleportDestination tpdest, message.destinations)
            {
                if (tpdest.mapId != m_botData[sender].interactionData.interactionId)
                {
                    error(sender) << "Interaction Module - Le bot n'a pas pu utiliser le zaap car la destination est inconnue.";
                    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
                    m_botData[sender].interactionData.interactionId = INVALID;
                    m_botData[sender].interactionData.finishedAction = true;
                    m_botData[sender].interactionData.actionID = INVALID;
                    m_botData[sender].interactionData.npcDialogs.clear();
                    emit scriptActionDone(sender);
                }

                else
                {
                    TeleportRequestMessage reply;
                    reply.sourceType = message.type;
                    reply.mapId = m_botData[sender].interactionData.interactionId;

                    m_interactionManager->finishedAction << sender;
                    QTimer::singleShot(15000, this, SLOT(finishAction()));
                    m_botData[sender].interactionData.finishedAction = false;

                    sender->send(reply);
                }
            }
        }

        else
        {
            error(sender) << "Interaction Module - Le bot n'a pas pu utiliser le zaap car la destination est inconnue.";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }
    }
        break;

    case MessageEnum::ZAAPDESTINATIONSMESSAGE:
    {
        ZaapDestinationsMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].generalData.botState == BotState::INACTIVE_STATE)
        {
            foreach(TeleportDestination tpdest, message.destinations)
            {
                if (tpdest.mapId != m_botData[sender].interactionData.interactionId)
                {
                    error(sender) << "Interaction Module - Le bot n'a pas pu utiliser le zaap car la destination est inconnue.";
                    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
                    m_botData[sender].interactionData.interactionId = INVALID;
                    m_botData[sender].interactionData.finishedAction = true;
                    m_botData[sender].interactionData.actionID = INVALID;
                    m_botData[sender].interactionData.npcDialogs.clear();
                    emit scriptActionDone(sender);
                }

                else
                {
                    TeleportRequestMessage reply;
                    reply.sourceType = message.type;
                    reply.mapId = m_botData[sender].interactionData.interactionId;

                    m_interactionManager->finishedAction << sender;
                    QTimer::singleShot(15000, this, SLOT(finishAction()));
                    m_botData[sender].interactionData.finishedAction = false;

                    sender->send(reply);
                }
            }
        }

        else
        {
            error(sender) << "Interaction Module - Le bot n'a pas pu utiliser le zaap car la destination est inconnue.";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }
    }
        break;
    }

    return messageFound;
}
