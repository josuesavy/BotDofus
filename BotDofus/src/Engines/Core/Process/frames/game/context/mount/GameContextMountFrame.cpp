#include "GameContextMountFrame.h"

GameContextMountFrame::GameContextMountFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameContextMountFrame::reset(SocketIO *sender)
{

}

bool GameContextMountFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::MOUNTRIDINGMESSAGE:
    {
        MountRidingMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.isRiding = message.isRiding;
    }
        break;

    case MessageEnum::MOUNTSETMESSAGE:
    {
        MountSetMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.isRiding = true;

        QStringList effects;
        for (int i = 0; i < message.mountData->effectList.size(); i++)
            effects.append(QString::number(message.mountData->effectList[i]->value) + QString(" ") +  qSharedPointerCast<CharacteristicData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::CHARACTERISTICS, qSharedPointerCast<EffectData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::EFFECTS, message.mountData->effectList[i]->actionId))->getCharacteristic()))->getName());

        m_botData[sender].playerData.mountData.levelRatio = message.mountData->level == 100 ? 100 : (message.mountData->experience / message.mountData->experienceForNextLevel) * 100.0;
        m_botData[sender].playerData.mountData.breed = qSharedPointerCast<MountData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MOUNTS, message.mountData->model))->getName();
        m_botData[sender].playerData.mountData.energyMax = message.mountData->energyMax - 1;
        m_botData[sender].playerData.mountData.energy = message.mountData->energy;
        m_botData[sender].playerData.mountData.level = message.mountData->level;
        m_botData[sender].playerData.mountData.name = message.mountData->name;
        m_botData[sender].playerData.mountData.effects = effects;
    }
        break;

    case MessageEnum::MOUNTXPRATIOMESSAGE:
    {
        MountXpRatioMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.mountData.xpRatio = message.ratio;
    }
        break;
    }

    return messageFound;
}
