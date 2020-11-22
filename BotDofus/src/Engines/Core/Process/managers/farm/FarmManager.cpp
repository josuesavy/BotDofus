#include "FarmManager.h"

FarmManager::FarmManager(QMap<SocketIO *, BotData> *connectionsData, MapManager *mapManager):
    AbstractManager(ModuleType::FARM, connectionsData),
    m_mapManager(mapManager)
{

}

bool FarmManager::processFarm(SocketIO *sender)
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

void FarmManager::farmAction(SocketIO *sender)
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
        m_botData[sender].farmData.moved = m_mapManager->changeToNearestCell(sender, m_botData[sender].farmData.currentElement.position);
}

void FarmManager::activateSkill(SocketIO *sender)
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

bool FarmManager::canFarmResource(InteractiveElementInfos element)
{
    if (element.enabledSkills.isEmpty())
        return false;

    return true;
}

bool FarmManager::editResourcesList(SocketIO *sender, uint id, bool add)
{
    if (add)
        m_botData[sender].farmData.elementsId << id;
    else
        m_botData[sender].farmData.elementsId.removeOne(id);

    if (m_botData[sender].farmData.elementsId.isEmpty())
        return true;

    return false;
}

bool FarmManager::resourcesListIsEmpty(SocketIO *sender)
{
    if (m_botData[sender].farmData.elementsId.isEmpty())
        return true;

    return false;
}

void FarmManager::clearAutoDeleteList(SocketIO *sender)
{
    m_botData[sender].farmData.resourcesToDelete.clear();
}

void FarmManager::removeResourceToDelete(SocketIO *sender, QString name)
{
    m_botData[sender].farmData.resourcesToDelete.removeOne(getItemId(name));
}

void FarmManager::addResourceToDelete(SocketIO *sender, QString name)
{
    m_botData[sender].farmData.resourcesToDelete << getItemId(name);
}

uint FarmManager::getItemId(QString name)
{
    return m_items[name].id;
}

QString FarmManager::getJobName(uint jobId)
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

bool FarmManager::isItemUsable(QString name)
{
    return m_items[name].usable;
}
