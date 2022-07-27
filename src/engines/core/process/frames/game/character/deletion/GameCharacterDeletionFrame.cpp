#include "GameCharacterDeletionFrame.h"

GameCharacterDeletionFrame::GameCharacterDeletionFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameCharacterDeletionFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHARACTERDELETIONERRORMESSAGE:
    {
        CharacterDeletionErrorMessage message;
        message.deserialize(&reader);

        QString reason = "ui.charSel.deletionError";

        switch ((CharacterDeletionErrorEnum)message.reason)
        {
        case CharacterDeletionErrorEnum::DEL_ERR_NO_REASON:
            reason += "TooManyDeletion";
            break;
        case CharacterDeletionErrorEnum::DEL_ERR_RESTRICED_ZONE:
            reason += "WrongAnswer";
            break;
        case CharacterDeletionErrorEnum::DEL_ERR_BAD_SECRET_ANSWER:
            reason += "UnsecureMode";
            break;
        }

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText(reason);
    }
        break;
    }

    return messageFound;
}
