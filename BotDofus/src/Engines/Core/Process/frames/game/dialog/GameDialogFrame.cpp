#include "GameDialogFrame.h"

GameDialogFrame::GameDialogFrame(QMap<SocketIO *, BotData> *connectionsData, InteractionManager *interactionManager):
    AbstractFrame(connectionsData),
    m_interactionManager(interactionManager)
{

}

bool GameDialogFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::LEAVEDIALOGMESSAGE:
    {
        if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
                && (m_botData[sender].generalData.botState == BotState::INACTIVE_STATE)
                && (m_botData[sender].interactionData.interactionId != INVALID))
        {
            QString name;
            foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::NPCS))
            {
                QSharedPointer<NpcData> npc = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, index));

                if (npc->getId() == m_botData[sender].interactionData.interactionId)
                    name = npc->getName();
            }

            if ((name != "Banquier") && (name != "Al Etsop") && (name != "Essiac d'Engrape"))
            {
                m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
                m_botData[sender].interactionData.interactionId = INVALID;
                m_botData[sender].interactionData.finishedAction = true;
                m_botData[sender].interactionData.actionID = INVALID;
                m_botData[sender].interactionData.npcDialogs.clear();
                emit scriptActionDone(sender);
            }

            else
            {
                m_interactionManager->finishedAction << sender;
                QTimer::singleShot(15000, this, SLOT(finishAction()));
                m_botData[sender].interactionData.finishedAction = false;
            }
        }

        else
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
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
