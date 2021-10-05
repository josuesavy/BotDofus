#include "ConnectionSearchFrame.h"

ConnectionSearchFrame::ConnectionSearchFrame(QMap<SocketIO*, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool ConnectionSearchFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ACQUAINTANCESEARCHERRORMESSAGE:
    {
        AcquaintanceSearchErrorMessage message;
        message.deserialize(&reader);

        QString reasonSearchError = "ui.sersel.searchError.";

        switch (message.reason)
        {
        case 1:
            reasonSearchError += "unavailable";
            break;
        case 2:
            reasonSearchError += "no_result";
            break;
        case 3:
            reasonSearchError += "flood";
            break;
        case 0:
        default:
            reasonSearchError += "unknown";
            break;
        }

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText(reasonSearchError);
    }
        break;
    }

    return messageFound;
}
