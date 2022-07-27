#include "GameTinselFrame.h"

GameTinselFrame::GameTinselFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameTinselFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ORNAMENTSELECTERRORMESSAGE:
    {
        OrnamentSelectErrorMessage message;
        message.deserialize(&reader);

        qDebug() << "[GameTinselFrame] ornament selection error";
    }
        break;
    }

    return messageFound;
}
