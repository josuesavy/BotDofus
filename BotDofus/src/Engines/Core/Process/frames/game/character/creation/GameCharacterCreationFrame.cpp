#include "GameCharacterCreationFrame.h"

GameCharacterCreationFrame::GameCharacterCreationFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameCharacterCreationFrame::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
}

bool GameCharacterCreationFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHARACTERCREATIONRESULTMESSAGE:
    {
        CharacterCreationResultMessage message;
        message.deserialize(&reader);

        if(message.result > 0)
        {
            switch((CharacterCreationResultEnum)message.result)
            {
            case CharacterCreationResultEnum::ERR_INVALID_NAME:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.invalidName");
                break;
            case CharacterCreationResultEnum::ERR_NAME_ALREADY_EXISTS:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.nameAlreadyExist");
                break;
            case CharacterCreationResultEnum::ERR_NOT_ALLOWED:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.notSubscriber");
                break;
            case CharacterCreationResultEnum::ERR_TOO_MANY_CHARACTERS:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.tooManyCharacters");
                break;
            case CharacterCreationResultEnum::ERR_NO_REASON:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.noReason");
                break;
            case CharacterCreationResultEnum::ERR_RESTRICED_ZONE:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.charSel.deletionErrorUnsecureMode");
                break;
            case CharacterCreationResultEnum::ERR_INCONSISTENT_COMMUNITY:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.wrongCommunity");
                break;
            }

            m_botData[sender].connectionData.connectionInfos.characterCreated = false;
            m_botData[sender].connectionData.connectionInfos.needToCreateCharacter = false;

            sender->disconnect();
        }

        else
        {
            info(sender) << "Personnage créer !";
            m_botData[sender].connectionData.connectionInfos.characterCreated = true;
            m_botData[sender].connectionData.connectionInfos.needToCreateCharacter = false;
        }

        QSqlQuery query;
        query.prepare("SELECT idaccounts FROM accounts WHERE login = (:login)");
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);

        if (query.exec())
        {
            if (query.next())
            {
                int idAccount = query.value(0).toInt();

                query.prepare("DELETE FROM creation WHERE idaccounts = :idaccounts");
                query.bindValue(":idaccounts", idAccount);
                query.exec();
            }
        }
    }
        break;

    case MessageEnum::CHARACTERNAMESUGGESTIONSUCCESSMESSAGE:
    {
        CharacterNameSuggestionSuccessMessage message;
        message.deserialize(&reader);

        action(sender) << "Création du personnage "+message.suggestion+"..";

        CharacterCreationRequestMessage ccrmsg;
        ccrmsg.name = message.suggestion;
        ccrmsg.breed = m_botData[sender].connectionData.connectionInfos.creation.breed;
        ccrmsg.sex = m_botData[sender].connectionData.connectionInfos.creation.sex;
        ccrmsg.colors = m_botData[sender].connectionData.connectionInfos.creation.colors;
        ccrmsg.cosmeticId = m_botData[sender].connectionData.connectionInfos.creation.head;

        sender->send(ccrmsg);
    }
        break;
    }

    return messageFound;
}
