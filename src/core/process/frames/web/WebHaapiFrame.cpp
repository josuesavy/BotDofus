#include "WebHaapiFrame.h"

WebHaapiFrame::WebHaapiFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool WebHaapiFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::HAAPISESSIONMESSAGE:
    {
        HaapiSessionMessage message;
        message.deserialize(&reader);

        m_botData[sender].connectionData.haapiSessionKey = message.key;

        HaapiApiKeyRequestMessage answer;
        sender->send(answer);
    }
        break;

    case MessageEnum::HAAPIAPIKEYMESSAGE:
    {
        HaapiApiKeyMessage message;
        message.deserialize(&reader);

        m_botData[sender].connectionData.haapiApiKey = message.token;
    }
        break;
    }

    return messageFound;
}
