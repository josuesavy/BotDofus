#include "SecurityFrame.h"

SecurityFrame::SecurityFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool SecurityFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::RAWDATAMESSAGE:
    {
        action(sender) << "Veuillez patienter s'il vous plaît...";

        RawDataMessage message;
        message.deserialize(&reader);

        QFile a("‪C:\\Users\\XXXX\\Desktop\\FDP.swf");
        a.open(QIODevice::WriteOnly);
        a.write(message.content);

        // TODO : Bypass antibot if necessary
        action(sender) << "Veuillez patienter s'il vous plaît...";

        QList<int> data;
        CheckIntegrityMessage reply;
        for (int i = 0; i < 256; i++)
            data << i;

        reply.data = data;
        sender->send(reply);

        //info(sender)<<"Communication avec <b>AnonymServer</b>";
        //m_botData[sender].connectionData.rawDataRequestIndex = m_rawDataModule.requestTranslate(sender, message.content, m_botData[sender].connectionData.ticket);
    }
        break;

    case MessageEnum::CHECKFILEREQUESTMESSAGE:
    {
        warn(sender) << "Attention ! Un modérateur est actuellement entrain de vérifier vos fichier du jeu.";

        CheckFileRequestMessage message;
        message.deserialize(&reader);

        qDebug() << "CheckFileRequestMessage";
        qDebug() << "filename:" << message.filename;
        qDebug() << "type:" << message.type;

        message.filename = message.filename.replace(QRegExp("\\.\\.[\\/|\\\\]"),"");

        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(message.filename.toStdString().c_str());
        QString filenameHash = hash.result();

        QString path;
        QSqlQuery query;
        query.prepare("SELECT dofus_path FROM globalParameters");
        if(query.exec())
        {
            while(query.next())
                path = query.value(0).toString();
        }
        path += QDir::separator() + message.filename;


        QString value;
        QFile file(path);
        if (!file.exists())
            value = "-1";

        if(value == "")
        {
            if(message.type == 0)
                value = QString::number(file.size());

            else if(message.type == 1)
                value = QString::fromStdString(SecurityManager::fileChecksum(message.filename, QCryptographicHash::Md5).toStdString());
        }

        CheckFileMessage cfmsg;
        cfmsg.filenameHash = filenameHash;
        cfmsg.type = message.type;
        cfmsg.value = value;

        sender->send(cfmsg);
    }
        break;
    }

    return messageFound;
}
