#include "GameContextRoleplayNpcFrame.h"

GameContextRoleplayNpcFrame::GameContextRoleplayNpcFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameContextRoleplayNpcFrame::reset(SocketIO *sender)
{

}

bool GameContextRoleplayNpcFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::NPCDIALOGCREATIONMESSAGE:
    {
        NpcDialogCreationMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].interactionData.interactionType == CurrentInteraction::NONE
                || m_botData[sender].interactionData.interactionId ==  INVALID)
        {
            LeaveDialogRequestMessage reply;
            sender->send(reply);

            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }

        else
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NPC;
            m_waitingReplies << sender;
        }
    }
        break;

    case MessageEnum::NPCDIALOGQUESTIONMESSAGE:
    {
        NpcDialogQuestionMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].interactionData.interactionType == CurrentInteraction::NONE
                || m_botData[sender].interactionData.interactionId ==  INVALID)
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            m_waitingReplies.removeOne(sender);

            LeaveDialogRequestMessage reply;
            sender->send(reply);

            emit scriptActionDone(sender);
        }

        else
        {
            m_botData[sender].interactionData.npcDialogs = message.visibleReplies;
            if (m_waitingReplies.contains(sender))
            {
                m_waitingReplies.removeOne(sender);
                emit scriptActionDone(sender);
            }
        }
    }
        break;
    }

    return messageFound;
}
