#include "CommonBasicFrame.h"

CommonBasicFrame::CommonBasicFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void CommonBasicFrame::reset(SocketIO *sender)
{

}

bool CommonBasicFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::BASICPINGMESSAGE:
        break;

    case MessageEnum::BASICPONGMESSAGE:
        break;

    case MessageEnum::BASICSTATMESSAGE:
        break;

    case MessageEnum::BASICSTATWITHDATAMESSAGE:
        break;
    }

    return messageFound;
}
