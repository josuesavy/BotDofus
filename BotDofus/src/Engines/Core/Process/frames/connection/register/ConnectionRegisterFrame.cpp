#include "ConnectionRegisterFrame.h"

ConnectionRegisterFrame::ConnectionRegisterFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void ConnectionRegisterFrame::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
}

bool ConnectionRegisterFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::NICKNAMEACCEPTEDMESSAGE:
    {
        info(sender) << "Pseudo accepté avec succès.";
    }
        break;

    case MessageEnum::NICKNAMEREFUSEDMESSAGE:
    {
        NicknameRefusedMessage message;
        message.deserialize(&reader);

        switch ((NicknameErrorEnum)message.reason)
        {
        case NicknameErrorEnum::ALREADY_USED:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.alreadyUsed");
            break;

        case NicknameErrorEnum::INVALID_NICK:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.invalid");
            break;

        case NicknameErrorEnum::SAME_AS_LOGIN:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.equalsLogin");
            break;

        case NicknameErrorEnum::UNKNOWN_NICK_ERROR:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.unknown");
            break;

        case NicknameErrorEnum::TOO_SIMILAR_TO_LOGIN:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.similarToLogin");
            break;
        }

        error(sender) << "Pseudo refusé.";
        sender->disconnect();
    }
        break;

    case MessageEnum::NICKNAMEREGISTRATIONMESSAGE:
    {
        bool ok;
        QString text = QInputDialog::getText(nullptr, tr("Choix du pseudo de compte"), tr("Pseudo :"), QLineEdit::Normal, QString(), &ok);
        if (ok && !text.isEmpty())
        {
            NicknameChoiceRequestMessage answer;
            answer.nickname = text;
            sender->send(answer);
        }
        else
            sender->disconnect();
    }
        break;
    }

    return messageFound;
}
