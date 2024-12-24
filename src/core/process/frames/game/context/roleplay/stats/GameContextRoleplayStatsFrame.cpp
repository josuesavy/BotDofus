#include "GameContextRoleplayStatsFrame.h"

GameContextRoleplayStatsFrame::GameContextRoleplayStatsFrame(QMap<SocketIO *, BotData> *connectionsData, StatsManager *statsManager):
    AbstractFrame(connectionsData),
    m_statsManager(statsManager)
{

}

bool GameContextRoleplayStatsFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::STATSUPGRADERESULTMESSAGE:
    {
        StatsUpgradeResultMessage message;
        message.deserialize(&reader);

        switch((StatsUpgradeResultEnum)message.result)
        {
        case StatsUpgradeResultEnum::SUCCESS:
            info(sender) << "Caractéristique augmentée avec succés.";
            break;
        case StatsUpgradeResultEnum::NONE:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.statboostFailed.text");
            break;
        case StatsUpgradeResultEnum::GUEST:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.fight.guestAccount");
            break;
        case StatsUpgradeResultEnum::IN_FIGHT:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.error.cantDoInFight");
            break;
        case StatsUpgradeResultEnum::NOT_ENOUGH_POINT:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.statboostFailed.notEnoughPoint");
            break;
        }

        m_statsManager->updateRequiredStats(sender);
    }
        break;
    }

    return messageFound;
}
