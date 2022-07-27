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

        QString protocol_build = "1.0.3-702b86a";

        qDebug() << "Server version is" << message.version << ". Client version is" << protocol_build << ".";
        if (message.version.isEmpty() || protocol_build.isEmpty())
            qDebug() << "A protocol version is empty or null. What happened?";

        QString clientHash = protocol_build.split("-").at(1);
        if (clientHash.isEmpty())
            qDebug() << "The client protocol version is malformed:" << protocol_build;

        QString serverHash = message.version.split("-").at(1);
        if (clientHash.isEmpty())
            qDebug() << "The server protocol version is malformed:" << message.version;

        if (clientHash != serverHash)
            qDebug() << "Protocol mismatch between the client and the server.";
    }
        break;
    }

    return messageFound;
}
