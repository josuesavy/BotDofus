#include "GamePrismFrame.h"

GamePrismFrame::GamePrismFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GamePrismFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::PRISMSETTINGSERRORMESSAGE:
    {
        PrismSettingsErrorMessage message;
        message.deserialize(&reader);

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.error.cantModifiedPrismVulnerabiltyHour");
    }
        break;
    }

    return messageFound;
}
