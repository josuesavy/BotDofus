#include "SecureFrame.h"

SecureFrame::SecureFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool SecureFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::TRUSTSTATUSMESSAGE:
    {
        TrustStatusMessage message;
        message.deserialize(&reader);

        m_botData[sender].connectionData.certifiedAccount = message.certified;

        CharactersListRequestMessage answer;
        sender->send(answer);
    }
        break;
    }

    return messageFound;
}
