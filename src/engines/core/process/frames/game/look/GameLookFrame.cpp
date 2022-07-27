#include "GameLookFrame.h"

GameLookFrame::GameLookFrame(QMap<SocketIO*, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameLookFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ACCESSORYPREVIEWERRORMESSAGE:
    {
        AccessoryPreviewErrorMessage message;
        message.deserialize(&reader);

        QString apErrorMsg;

        switch((AccessoryPreviewErrorEnum)message.error)
        {
        case AccessoryPreviewErrorEnum::PREVIEW_BAD_ITEM:
            apErrorMsg = D2OManagerSingleton::get()->getI18N()->getText("ui.shop.preview.badItem");
            break;
        case AccessoryPreviewErrorEnum::PREVIEW_COOLDOWN:
            apErrorMsg = D2OManagerSingleton::get()->getI18N()->getText("ui.shop.preview.cooldown");
            break;
        case AccessoryPreviewErrorEnum::PREVIEW_ERROR:
            apErrorMsg = D2OManagerSingleton::get()->getI18N()->getText("ui.shop.preview.error");
            break;
        }

        if (!apErrorMsg.isNull() || !apErrorMsg.isEmpty())
        {
            error(sender) << apErrorMsg;
        }
    }
        break;
    }

    return messageFound;
}
