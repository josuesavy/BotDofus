#include "ProcessEngine.h"

ProcessEngine::ProcessEngine():
    basicNoOperationMsgCounter(0)
{
    connect(m_modules[ModuleType::CONNECTION], SIGNAL(connectionAdded(SocketIO*)), this, SLOT(connectToSocket(SocketIO*)));
    connect(m_modules[ModuleType::CONNECTION], SIGNAL(botDisconnected(SocketIO*)), this, SLOT(resetModules(SocketIO*)));


    QMapIterator<ModuleType, AbstractModule*> module(m_modules);
    while (module.hasNext())
    {
        module.next();
        connect(module.value(), SIGNAL(requestUpdate(SocketIO*)), this, SLOT(processUpdateRequest(SocketIO*)));
    }
}

void ProcessEngine::resetModules(SocketIO *sender)
{
    foreach(AbstractModule *module, m_modules.values())
        module->reset(sender);

    processUpdateRequest(sender);
}

void ProcessEngine::processUpdateRequest(SocketIO *sender)
{
    if(m_botData.contains(sender))
    {
        if(m_botData[sender].generalData.logMessages.size() <= 250)
        {
            m_botData[sender].generalData.logMessageCount = m_botData[sender].generalData.logMessages.size();
        }

        while(m_botData[sender].generalData.logMessages.size() > 250)
        {
            m_botData[sender].generalData.logMessages.removeFirst();
            m_botData[sender].generalData.logMessageCount = m_botData[sender].generalData.logMessageCount - 1;
        }

        emit informationsUpdated(sender);
    }
}

void ProcessEngine::connectToSocket(SocketIO* sender)
{
    connect(sender, SIGNAL(dataReceived(QList<MessageInfos>)), this, SLOT(processData(QList<MessageInfos>)));
}

void ProcessEngine::processData(QList<MessageInfos> messages)
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());

    foreach (const MessageInfos &data, messages)
        processMessage(data, sender);

    processUpdateRequest(sender);
}

QByteArray ProcessEngine::fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm)
{
    QFile f(fileName);
    if (f.open(QFile::ReadOnly))
    {
        QCryptographicHash hash(hashAlgorithm);
        if (hash.addData(&f))
            return hash.result();
    }
    return QByteArray();
}

bool ProcessEngine::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = false;
    QMapIterator<ModuleType, AbstractModule*> module(m_modules);
    while (module.hasNext())
    {
        module.next();
        if(module.value()->processMessage(data, sender))
            messageFound = true;
    }

    Reader reader(data.messageData);

    switch (data.messageType)
    {
    case MessageEnum::TEXTINFORMATIONMESSAGE:
    {
        TextInformationMessage message;
        message.deserialize(&reader);

        QSharedPointer<InfoMessageData> infoData = qSharedPointerCast<InfoMessageData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INFOMESSAGES, message.msgType*10000 + message.msgId));
        QString output = infoData->getText();
        output = ParamsDecoder::applyParams(output, message.parameters);

        qDebug()<<"TextInformationMessage -"<<output<<" Params -"<<message.parameters;

        switch((TextInformationTypeEnum)infoData->getTypeId())
        {
        case TextInformationTypeEnum::TEXT_ENTITY_TALK:
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_ERROR:
            error(sender)<<output.replace("\n"," ");
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_FIGHT:
            action(sender)<<output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_FIGHT_LOG:
            log(sender, CHANNELFIGHTLOG) << output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_MESSAGE:
            action(sender)<<output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_POPUP:
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_PVP:
            log(sender, CHANNELALLIANCE) << output;
            break;

        case TextInformationTypeEnum::TEXT_LIVING_OBJECT:
            log(sender, CHANNELPRIVATE) << output;
            break;
        }
    }
        break;

    case MessageEnum::NOTIFICATIONBYSERVERMESSAGE:
    {
        NotificationByServerMessage message;
        message.deserialize(&reader);

        QList<QString> a;
        foreach(QString param, message.parameters)
            a.append(param);

        QSharedPointer<NotificationData> notif = qSharedPointerCast<NotificationData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NOTIFICATIONS, message.id));
        QString title = D2OManagerSingleton::get()->getI18N()->getText(notif->getTitleId());
        QString text = D2OManagerSingleton::get()->getI18N()->getText(notif->getMessageId());

        for(int i = 0; i < a.size(); i++)
            text.replace(text.indexOf("%"), 1, a[i-1]);

        warn(sender) << "<b>" << title << "</b>" << text;
    }
        break;

    case MessageEnum::BASICTIMEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SERVERSETTINGSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SERVEROPTIONALFEATURESMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::BASICNOOPERATIONMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::BASICACKMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::PRISMSLISTMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SERVERSESSIONCONSTANTSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::ACCOUNTCAPABILITIESMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::ENABLEDCHANNELSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SPELLLISTMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SHORTCUTBARCONTENTMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SETCHARACTERRESTRICTIONSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::FRIENDWARNONCONNECTIONSTATEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::FRIENDWARNONLEVELGAINSTATEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::SPOUSESTATUSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::ACHIEVEMENTLISTMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::CHARACTERCAPABILITIESMESSAGE:
        messageFound = true;
        break;

    case MessageEnum::ALMANACHCALENDARDATEMESSAGE:
        messageFound = true;
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
                value = QString::fromStdString(fileChecksum(message.filename, QCryptographicHash::Md5).toStdString());
        }

        CheckFileMessage cfmsg;
        cfmsg.filenameHash = filenameHash;
        cfmsg.type = message.type;
        cfmsg.value = value;

        sender->send(cfmsg);
    }
        break;
    }

    if (!messageFound)
        qDebug()<<"MESSAGE PROCESS - Aucun support du message -"<<MessageUtils::getName(data.messageType)<<"- ID :"<<(int)data.messageType<<"\n";

    return messageFound;
}
