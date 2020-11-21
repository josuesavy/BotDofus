#include "AlmanachFrame.h"

AlmanachFrame::AlmanachFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void AlmanachFrame::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
}

bool AlmanachFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ALMANACHCALENDARDATEMESSAGE:
    {
        AlmanachCalendarDateMessage message;
        message.deserialize(&reader);

        QSharedPointer<AlmanaxCalendarData> almanaxData = qSharedPointerCast<AlmanaxCalendarData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ALMANAXCALENDARS, message.date));
        QSharedPointer<NpcData> npcData = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, almanaxData->getNpcId()));

        action(sender) << "[Almanax]" << D2OManagerSingleton::get()->getI18N()->getText(almanaxData->getDescId());
        action(sender) << "[Almanax]" << D2OManagerSingleton::get()->getI18N()->getText("ui.almanax.offeringTo").arg(npcData->getName());
    }
        break;
    }

    return messageFound;
}
