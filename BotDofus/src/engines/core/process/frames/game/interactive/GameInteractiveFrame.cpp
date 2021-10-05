#include "GameInteractiveFrame.h"

GameInteractiveFrame::GameInteractiveFrame(QMap<SocketIO *, BotData> *connectionsData, InteractionManager *interactionManager, FarmManager *farmManager):
    AbstractFrame(connectionsData),
    m_interactionManager(interactionManager),
    m_farmManager(farmManager)
{

}

bool GameInteractiveFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::INTERACTIVEELEMENTUPDATEDMESSAGE:
    {
        InteractiveElementUpdatedMessage message;
        message.deserialize(&reader);

        if(message.interactiveElement->onCurrentMap)
        {
            InteractiveElementInfos mainElementInfos;
            mainElementInfos.elementId = message.interactiveElement->elementId;
            mainElementInfos.elementTypeId = message.interactiveElement->elementTypeId;

            // Enable skills
            foreach(QSharedPointer<InteractiveElementSkill> skill, message.interactiveElement->enabledSkills)
            {
                InteractiveSkillInfos enabledInfos;
                enabledInfos.ID = skill->skillId;
                enabledInfos.UID = skill->skillInstanceUid;
                mainElementInfos.enabledSkills<<enabledInfos;
            }

            // Disable skills
            foreach (QSharedPointer<InteractiveElementSkill> skill, message.interactiveElement->disabledSkills)
            {
                InteractiveSkillInfos disabledInfos;
                disabledInfos.ID = skill->skillId;
                disabledInfos.UID = skill->skillInstanceUid;
                mainElementInfos.disabledSkills<<disabledInfos;
            }

            for (int i = 0; i < m_botData[sender].mapData.interactivesOnMap.size(); i++)
            {
                if (m_botData[sender].mapData.interactivesOnMap[i].elementId == message.interactiveElement->elementId)
                {
                    m_botData[sender].mapData.interactivesOnMap.replace(i, mainElementInfos);
                }
            }

            for (int i = 0; i < m_botData[sender].mapData.doorsOnMap.size(); i++)
            {
                if (m_botData[sender].mapData.doorsOnMap[i].interactiveElementInfos.elementId == message.interactiveElement->elementId)
                {
                    InteractiveElementDoorInfos interactiveElementDoorInfos;
                    interactiveElementDoorInfos.interactiveElementInfos = mainElementInfos;
                    interactiveElementDoorInfos.cellId = m_botData[sender].mapData.doorsOnMap[i].cellId;
                    m_botData[sender].mapData.doorsOnMap.replace(i, interactiveElementDoorInfos);
                }
            }
        }
    }
        break;

    case MessageEnum::INTERACTIVEUSEDMESSAGE:
    {
        if (m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();

            m_interactionManager->m_confirmAction << sender;
            QTimer::singleShot(1000, m_interactionManager, SLOT(confirmAction()));
        }
    }
        break;

    case MessageEnum::INTERACTIVEUSEENDEDMESSAGE:
    {
        if (m_botData[sender].farmData.farming)
        {
            m_botData[sender].statisticsData.countTotalGatherWon += 1;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            if (m_botData[sender].farmData.interactiveElementsList.size())
            {
                QTimer::singleShot(500, this, [this, sender] () { m_farmManager->farmAction(sender); });
                //farmAction(sender);
            }
            else
            {
                m_botData[sender].farmData.farming = false;
                emit scriptActionDone(sender);
            }
        }
    }
        break;

    case MessageEnum::INTERACTIVEUSEERRORMESSAGE:
    {
        InteractiveUseErrorMessage message;
        message.deserialize(&reader);

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.impossible_action");

        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE && m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].craftData.recipeQuantities.clear();
            m_botData[sender].craftData.recipeStack.clear();
            m_botData[sender].craftData.isCrafting = false;
            m_botData[sender].craftData.step = 0;

            emit scriptActionDone(sender);
        }

        if (m_botData[sender].farmData.farming)
        {
            m_botData[sender].statisticsData.countTotalGatherLost += 1;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            qDebug() << "The character could not harvest the id resources" << message.elemId;


            if (m_botData[sender].farmData.interactiveElementsList.size())
                QTimer::singleShot(500, this, [this, sender] () { m_farmManager->farmAction(sender); });

            else
            {
                m_botData[sender].farmData.farmTimer->disconnect();
                m_botData[sender].farmData.farmTimer.clear();

                m_botData[sender].farmData.farming = false;
                emit scriptActionDone(sender);
            }
        }

        if (m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
        {
            error(sender) << "Interaction Module - Le bot n'a pas pu interagir avec l'élément spécifié (npc, zaap(i), item).";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }
    }
        break;

    case MessageEnum::STATEDELEMENTUPDATEDMESSAGE:
    {
        StatedElementUpdatedMessage message;
        message.deserialize(&reader);

        for (int i = 0; i < m_botData[sender].mapData.statedElementsOnMap.size(); i++)
        {
            if (message.statedElement.elementId == m_botData[sender].mapData.statedElementsOnMap[i].elementId)
            {
                StatedElementsInfos statedElementsInfos;
                statedElementsInfos.elementId = message.statedElement.elementId;
                statedElementsInfos.elementCellId = message.statedElement.elementCellId;
                statedElementsInfos.elementState = message.statedElement.elementState;

                m_botData[sender].mapData.statedElementsOnMap.replace(i, statedElementsInfos);
            }
        }
    }
        break;
    }

    return messageFound;
}
