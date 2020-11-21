#include "GameContextFrame.h"

GameContextFrame::GameContextFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameContextFrame::reset(SocketIO *sender)
{

}

bool GameContextFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::GAMECAUTIOUSMAPMOVEMENTMESSAGE:
    {
        GameCautiousMapMovementMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
        {
            if (m_botData[sender].mapData.botId == message.actorId)
            {
                action(sender)<< "Vous êtes dans l'obligation de marcher";
                m_botData[sender].mapData.confirmationRequest.elapsedTime.start();
                m_botData[sender].mapData.requestedPath.timer.start();
                m_botData[sender].mapData.confirmationRequest.timer->setSingleShot(true);
                m_botData[sender].mapData.confirmationRequest.timer->setInterval(m_botData[sender].mapData.confirmationRequest.estimatedTime);
                connect(m_botData[sender].mapData.confirmationRequest.timer.data(), SIGNAL(timeout()), this, SLOT(processConfirmation()));
                m_botData[sender].mapData.confirmationRequest.timer->start();

                if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE && m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == getType())
                    emit scriptActionDone(sender);
            }
        }
    }
        break;

    case MessageEnum::GAMECONTEXTCREATEMESSAGE:
    {
        GameContextCreateMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.gameContext = (GameContextEnum)message.context;
    }
        break;

    case MessageEnum::GAMECONTEXTREFRESHENTITYLOOKMESSAGE:
    {
        GameContextRefreshEntityLookMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.playersOnMap[message.id].look = message.look;
    }
        break;

    case MessageEnum::GAMECONTEXTREMOVEELEMENTMESSAGE:
    {
        GameContextRemoveElementMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.playersOnMap.remove(message.id);
        m_botData[sender].mapData.npcsOnMap.remove(message.id);
        m_botData[sender].mapData.monsterGroupsOnMap.remove(message.id);
        m_botData[sender].mapData.merchantsOnMap.remove(message.id);
        m_botData[sender].mapData.npcsQuestOnMap.remove(message.id);

        MapRunningFightListRequestMessage answer;
        sender->send(answer);
    }
        break;

    case MessageEnum::GAMEENTITIESDISPOSITIONMESSAGE:
    {
        GameEntitiesDispositionMessage message;
        message.deserialize(&reader);

        foreach(QSharedPointer<IdentifiedEntityDispositionInformations> entity, message.dispositions)
            m_botData[sender].fightData.fighters[entity->id].cellId = entity->cellId;

        updateFightDisposition(sender);
    }
        break;

    case MessageEnum::GAMEENTITYDISPOSITIONERRORMESSAGE:
    {
        qDebug() << "FightModule - Cette position n'est pas accessible.";
    }
        break;

    case MessageEnum::GAMEMAPMOVEMENTMESSAGE:
    {
        GameMapMovementMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].generalData.botState == FIGHTING_STATE)
        {
            m_botData[sender].fightData.fighters[message.actorId].cellId = message.keyMovements.last();
        }

        if (m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
        {
            if (m_botData[sender].mapData.botId == message.actorId)
            {
                m_botData[sender].mapData.confirmationRequest.elapsedTime.start();
                m_botData[sender].mapData.requestedPath.timer.start();
                m_botData[sender].mapData.confirmationRequest.timer->setSingleShot(true);
                m_botData[sender].mapData.confirmationRequest.timer->setInterval(m_botData[sender].mapData.confirmationRequest.estimatedTime);
                connect(m_botData[sender].mapData.confirmationRequest.timer.data(), SIGNAL(timeout()), this, SLOT(processConfirmation()));
                m_botData[sender].mapData.confirmationRequest.timer->start();

                if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE && m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == getType())
                    emit scriptActionDone(sender);
            }

            if(m_botData[sender].mapData.playersOnMap.contains(message.actorId))
            {
                m_botData[sender].mapData.playersOnMap[message.actorId].cellId = message.keyMovements.last();
                m_botData[sender].mapData.playersOnMap[message.actorId].keyMovements = message.keyMovements;
            }

            else if(m_botData[sender].mapData.monsterGroupsOnMap.contains(message.actorId))
            {
                m_botData[sender].mapData.monsterGroupsOnMap[message.actorId].cellID = message.keyMovements.last();
                m_botData[sender].mapData.monsterGroupsOnMap[message.actorId].keyMovements = message.keyMovements;
            }
        }
    }
        break;

    case MessageEnum::GAMEMAPNOMOVEMENTMESSAGE:
    {
        if(m_botData[sender].generalData.botState == FIGHTING_STATE)
            processTurn(sender);

        if (m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
        {
            //qDebug() << "timer isNull?:" <<m_botData[sender].mapData.confirmationRequest.timer.isNull();

            m_botData[sender].mapData.confirmationRequest.timer->disconnect(); // QObject::disconnect: Unexpected null parameter (>=2 accounts)
            m_botData[sender].mapData.confirmationRequest.timer.clear();

            if(m_botData[sender].generalData.botState == MOVING_STATE)
                m_botData[sender].generalData.botState = INACTIVE_STATE;

            emit couldNotMove(sender);
        }
    }
        break;
    }

    return messageFound;
}
