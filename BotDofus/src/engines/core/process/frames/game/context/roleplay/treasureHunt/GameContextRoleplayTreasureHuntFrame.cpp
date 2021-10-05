#include "GameContextRoleplayTreasureHuntFrame.h"

GameContextRoleplayTreasureHuntFrame::GameContextRoleplayTreasureHuntFrame(QMap<SocketIO*, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameContextRoleplayTreasureHuntFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::TREASUREHUNTDIGREQUESTANSWERMESSAGE:
    {
        TreasureHuntDigRequestAnswerMessage message;
        message.deserialize(&reader);

        QString treasureHuntDigAnswerText;
        int wrongFlagCount;

//        if(thdramsg is TreasureHuntDigRequestAnswerFailedMessage)
//        {
//            wrongFlagCount = (thdramsg as TreasureHuntDigRequestAnswerFailedMessage).wrongFlagCount;
//        }

        switch ((TreasureHuntDigRequestEnum)message.result)
        {
        case TreasureHuntDigRequestEnum::TREASURE_HUNT_DIG_ERROR_IMPOSSIBLE:
            treasureHuntDigAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.fight.wrongMap");
            break;

        case TreasureHuntDigRequestEnum::TREASURE_HUNT_DIG_ERROR_UNDEFINED:
            treasureHuntDigAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.impossible_action");
            break;

        case TreasureHuntDigRequestEnum::TREASURE_HUNT_DIG_LOST:
            treasureHuntDigAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.huntFail");
            break;

        case TreasureHuntDigRequestEnum::TREASURE_HUNT_DIG_NEW_HINT:
            treasureHuntDigAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.stepSuccess");
            break;

        case TreasureHuntDigRequestEnum::TREASURE_HUNT_DIG_WRONG:
        {
            if(wrongFlagCount > 1)
                treasureHuntDigAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.digWrongFlags").arg(wrongFlagCount);

            else if(wrongFlagCount > 0)
                treasureHuntDigAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.digWrongFlag");

            else
                treasureHuntDigAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.digFail");
        }
            break;

        case TreasureHuntDigRequestEnum::TREASURE_HUNT_DIG_WRONG_AND_YOU_KNOW_IT:
            treasureHuntDigAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.noNewFlag");
            break;

        case TreasureHuntDigRequestEnum::TREASURE_HUNT_DIG_FINISHED:
        {
            if ((TreasureHuntTypeEnum)message.questType == TreasureHuntTypeEnum::TREASURE_HUNT_CLASSIC)
            {
                treasureHuntDigAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.huntSuccess");
            }
        }
            break;
        }

        if (!treasureHuntDigAnswerText.isNull() || !treasureHuntDigAnswerText.isEmpty())
        {
            action(sender) << treasureHuntDigAnswerText;
        }
    }
        break;

    case MessageEnum::TREASUREHUNTREQUESTANSWERMESSAGE:
    {
        TreasureHuntRequestAnswerMessage message;
        message.deserialize(&reader);

        QString treasureHuntRequestAnswerText;

        switch ((TreasureHuntRequestEnum)message.result)
        {
        case TreasureHuntRequestEnum::TREASURE_HUNT_ERROR_ALREADY_HAVE_QUEST:
            treasureHuntRequestAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.alreadyHaveQuest");
            break;

        case TreasureHuntRequestEnum::TREASURE_HUNT_ERROR_NO_QUEST_FOUND:
            treasureHuntRequestAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.noQuestFound");
            break;

        case TreasureHuntRequestEnum::TREASURE_HUNT_ERROR_UNDEFINED:
            treasureHuntRequestAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.impossible_action");
            break;

        case TreasureHuntRequestEnum::TREASURE_HUNT_ERROR_NOT_AVAILABLE:
            treasureHuntRequestAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.huntNotAvailable");
            break;

        case TreasureHuntRequestEnum::TREASURE_HUNT_ERROR_DAILY_LIMIT_EXCEEDED:
            treasureHuntRequestAnswerText = D2OManagerSingleton::get()->getI18N()->getText("ui.treasureHunt.huntLimitExceeded");
            break;
        }

        if (!treasureHuntRequestAnswerText.isNull() || !treasureHuntRequestAnswerText.isEmpty())
        {
            action(sender) << treasureHuntRequestAnswerText;
        }
    }
        break;
    }

    return messageFound;
}
