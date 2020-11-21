#include "FarmModule.h"

FarmModule::FarmModule(QMap<SocketIO *, BotData> *connectionsData, MapModule *mapModule) :
    AbstractFrame(ModuleType::FARM, connectionsData),
    m_mapModule(mapModule)
{
    QObject::connect(m_mapModule, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(activateSkill(SocketIO*)));

//    foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::ITEMS))
//    {
//        QSharedPointer<ItemData> item = D2OManagerSingleton::get()->getItem(index);

//        UsableItem u;
//        u.id = item->getId();
//        u.usable = item->getUsable();
//        m_items[item->getName()] = u;
//    }
}

void FarmModule::reset(SocketIO *sender)
{
    m_botData[sender].farmData.moved = false;
    m_botData[sender].farmData.farming = false;
}

bool FarmModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default:
        messageFound = false;
        break;

    case MessageEnum::JOBLEVELUPMESSAGE:
    {
        JobLevelUpMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].statisticsData.countTotalGetNewLevelJobs.contains(message.jobsDescription->jobId))
            m_botData[sender].statisticsData.countTotalGetNewLevelJobs[message.jobsDescription->jobId] += 1;
        else
            m_botData[sender].statisticsData.countTotalGetNewLevelJobs.insert(message.jobsDescription->jobId, 1);

        action(sender) << "Votre métier" << qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, message.jobsDescription->jobId))->getName() << "passe niveau" << message.newLevel;
        m_botData[sender].craftData.jobs[message.jobsDescription->jobId].jobLevel = message.newLevel;
    }
        break;

    case MessageEnum::JOBEXPERIENCEMULTIUPDATEMESSAGE:
    {
        JobExperienceMultiUpdateMessage message;
        message.deserialize(&reader);

        foreach(const JobExperience &e, message.experiencesUpdate)
            m_botData[sender].craftData.jobs[e.jobId] = e;
    }
        break;

    case MessageEnum::JOBEXPERIENCEUPDATEMESSAGE:
    {
        JobExperienceUpdateMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].statisticsData.countTotalExperienceJobs.contains(message.experiencesUpdate.jobId))
            m_botData[sender].statisticsData.countTotalExperienceJobs[message.experiencesUpdate.jobId] += message.experiencesUpdate.jobXP;
        else
            m_botData[sender].statisticsData.countTotalExperienceJobs.insert(message.experiencesUpdate.jobId, message.experiencesUpdate.jobXP);

        m_botData[sender].craftData.jobs[message.experiencesUpdate.jobId] = message.experiencesUpdate;
    }
        break;

    case MessageEnum::INTERACTIVEELEMENTUPDATEDMESSAGE:
    {
        InteractiveElementUpdatedMessage message;
        message.deserialize(&reader);

        if(message.interactiveElement->onCurrentMap)
        {
            for (int i = 0; i < m_botData[sender].mapData.interactivesOnMap.size(); i++)
            {
                if (m_botData[sender].mapData.interactivesOnMap[i].elementId == message.interactiveElement->elementId)
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

                    m_botData[sender].mapData.interactivesOnMap.replace(i, mainElementInfos);
                }
            }
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
                QTimer::singleShot(500, this, [this, sender] () { farmAction(sender); });
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

        if (m_botData[sender].farmData.farming)
        {
            m_botData[sender].statisticsData.countTotalGatherLost += 1;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            qDebug() << "Le bot n'a pas pu récolter la ressources d'id" << message.elemId;


            if (m_botData[sender].farmData.interactiveElementsList.size())
                QTimer::singleShot(500, this, [this, sender] () { farmAction(sender); });

            else
            {
                m_botData[sender].farmData.farmTimer->disconnect();
                m_botData[sender].farmData.farmTimer.clear();

                m_botData[sender].farmData.farming = false;
                emit scriptActionDone(sender);
            }
        }
    }
        break;

    case MessageEnum::STATEDELEMENTUPDATEDMESSAGE:
        break;
    }

    return messageFound;
}

bool FarmModule::processFarm(SocketIO *sender)
{
    m_botData[sender].farmData.interactiveElementsList.clear();
    m_botData[sender].farmData.currentElement.skillInstanceUid = INVALID;

    // Check gather's list not empty
    if (m_botData[sender].farmData.elementsId.isEmpty())
        return false;

    foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
    {
        if (m_botData[sender].farmData.elementsId.contains(e.elementTypeId) &&  !e.enabledSkills.isEmpty())
        {
            InteractiveElementAction ie;
            ie.ie = e;
            ie.skillInstanceUid = e.enabledSkills.first().UID;
            ie.position = m_botData[sender].mapData.map.getInteractiveElementCellID(e.elementId);

            m_botData[sender].farmData.interactiveElementsList << ie;
        }
    }

    int n;
    int i;
    for (n=0; n < m_botData[sender].farmData.interactiveElementsList.count(); n++)
    {
        for (i=n+1; i < m_botData[sender].farmData.interactiveElementsList.count(); i++)
        {
            uint valorN = m_botData[sender].farmData.interactiveElementsList.at(n).position;
            uint valorI = m_botData[sender].farmData.interactiveElementsList.at(i).position;
            if (valorN > valorI)
            {
                m_botData[sender].farmData.interactiveElementsList.move(i, n);
                n=0;
            }
        }
    }

    if (m_botData[sender].farmData.farming == true || m_botData[sender].farmData.interactiveElementsList.isEmpty() || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
        return false;

    m_botData[sender].farmData.farming = true;
    farmAction(sender);
    return true;
}

void FarmModule::farmAction(SocketIO *sender)
{
    // Exit the function if the character is not available
    if (!m_botData[sender].farmData.farming || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
        return;

    // Get the interactive to use
    m_botData[sender].farmData.currentElement = m_botData[sender].farmData.interactiveElementsList.takeFirst();

    // Define monster's cell for not walkable
    QList<uint> cells;
    foreach (MonsterGroup g, m_botData[sender].mapData.monsterGroupsOnMap)
        cells << g.cellID;

    // Define player's cell for not walkable
    foreach (EntityInfos p, m_botData[sender].mapData.playersOnMap)
        cells << p.cellId;

    // Define npc's cell for not walkable
    foreach(NpcInfos n, m_botData[sender].mapData.npcsOnMap)
        cells << n.cellId;

    // Define merchant's cell for not walkable
    foreach(MerchantInfos m, m_botData[sender].mapData.merchantsOnMap)
        cells << m.cellId;

    // Search a path
    NearestPathInfos nearestPathInfos;
    Pathfinding path;
    nearestPathInfos = path.findNearestPath(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId, m_botData[sender].farmData.currentElement.position, m_botData[sender].mapData.map.getMapId(), false, true, cells);

    // Go to farm
    if (nearestPathInfos.path.last() == m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId)
        activateSkill(sender);
    else
        m_botData[sender].farmData.moved = m_mapModule->changeToNearestCell(sender, m_botData[sender].farmData.currentElement.position);
}

void FarmModule::activateSkill(SocketIO *sender)
{
    // Check
    if (m_botData[sender].farmData.currentElement.skillInstanceUid == INVALID || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || !m_botData[sender].farmData.farming)
        return;

    // Process..
    InteractiveUseRequestMessage r;
    r.elemId = m_botData[sender].farmData.currentElement.ie.elementId;
    r.skillInstanceUid = m_botData[sender].farmData.currentElement.skillInstanceUid;
    sender->send(r);

    // Update
    m_botData[sender].generalData.botState = BotState::FARMING_STATE;
    m_botData[sender].farmData.currentElement.skillInstanceUid = INVALID;
}

bool FarmModule::canFarmResource(InteractiveElementInfos element)
{
    if (element.enabledSkills.isEmpty())
        return false;

    return true;
}

bool FarmModule::editResourcesList(SocketIO *sender, uint id, bool add)
{
    if (add)
        m_botData[sender].farmData.elementsId << id;
    else
        m_botData[sender].farmData.elementsId.removeOne(id);

    if (m_botData[sender].farmData.elementsId.isEmpty())
        return true;

    return false;
}

bool FarmModule::resourcesListIsEmpty(SocketIO *sender)
{
    if (m_botData[sender].farmData.elementsId.isEmpty())
        return true;

    return false;
}

void FarmModule::clearAutoDeleteList(SocketIO *sender)
{
    m_botData[sender].farmData.resourcesToDelete.clear();
}

void FarmModule::removeResourceToDelete(SocketIO *sender, QString name)
{
    m_botData[sender].farmData.resourcesToDelete.removeOne(getItemId(name));
}

void FarmModule::addResourceToDelete(SocketIO *sender, QString name)
{
    m_botData[sender].farmData.resourcesToDelete << getItemId(name);
}

uint FarmModule::getItemId(QString name)
{
    return m_items[name].id;
}

QString FarmModule::getJobName(uint jobId)
{
    foreach (const int &id, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::JOBS))
    {
        if (jobId == qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, id))->getId())
        {
            return qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, id))->getName();
        }
    }

    return QString();
}

bool FarmModule::isItemUsable(QString name)
{
    return m_items[name].usable;
}
