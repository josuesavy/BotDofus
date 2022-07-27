#include "ServerBasicFrame.h"

ServerBasicFrame::ServerBasicFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool ServerBasicFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::SYSTEMMESSAGEDISPLAYMESSAGE:
    {
        SystemMessageDisplayMessage message;
        message.deserialize(&reader);

        QSharedPointer<InfoMessageData> infoData = qSharedPointerCast<InfoMessageData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INFOMESSAGES, 40000 + message.msgId));

        error(sender) << ParamsDecoder::applyParams(infoData->getText(), message.parameters);
    }
        break;
    }

    return messageFound;
}
