#include "HandshakeFrame.h"

HandshakeFrame::HandshakeFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool HandshakeFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::PROTOCOLREQUIRED:
    {
        ProtocolRequired message;
        message.deserialize(&reader);

//        if(message.currentVersion < message.requiredVersion)
//        {
//            QString str = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.protocolError");
//            str.replace("%1", QString::number(message.currentVersion));
//            str.replace("%2", QString::number(message.requiredVersion));
//            error(sender) << str;
//        }
    }
        break;
    }

    return messageFound;
}
