#include "GameContextRoleplayDeathFrame.h"

GameContextRoleplayDeathFrame::GameContextRoleplayDeathFrame(QMap<SocketIO *, BotData> *connectionsData, StatsManager *statsManager):
    AbstractFrame(ModuleType::CONNECTION, connectionsData),
    m_statsManager(statsManager)
{

}

void GameContextRoleplayDeathFrame::reset(SocketIO *sender)
{

}

bool GameContextRoleplayDeathFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE:
    {
        GameRolePlayPlayerLifeStatusMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.lifeStatus = (PlayerLifeStatusEnum)message.state;

        if(m_botData[sender].playerData.lifeStatus == PlayerLifeStatusEnum::STATUS_TOMBSTONE)
            m_statsManager->freeSoul(sender);

        else if(m_botData[sender].playerData.isRequestingFreeSoul &&
                m_botData[sender].playerData.hasSentRequestFreeSoul)
        {
            m_botData[sender].playerData.isRequestingFreeSoul = false;
            m_botData[sender].playerData.hasSentRequestFreeSoul = false;
        }

        if(m_botData[sender].scriptData.activeModule == getType())
            emit scriptActionDone(sender);
    }
        break;
    }

    return messageFound;
}
