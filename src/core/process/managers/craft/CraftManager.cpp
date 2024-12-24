#include "CraftManager.h"

CraftManager::CraftManager(QMap<SocketIO*, BotData> *connectionsData, MapManager *mapManager):
    AbstractManager(ManagerType::CRAFT, connectionsData),
    m_mapManager(mapManager)
{
    QObject::connect(m_mapManager, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(useCraftingBench(SocketIO*)));
    QObject::connect(m_mapManager, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(couldNotMove(SocketIO*)));

    foreach(int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::RECIPES))
    {
        QSharedPointer<RecipeData> recipe = qSharedPointerCast<RecipeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::RECIPES, index));
        m_recipesName[recipe->getResultName()] = recipe->getResultId();

        RecipeInfos infos;
        infos.quantity = -1;
        infos.jobId = recipe->getJobId();
        infos.joblevel = recipe->getResultLevel();
        infos.name = recipe->getResultName();
        infos.skillId = recipe->getSkillId();
        infos.recipeId = recipe->getResultId();

        for (int i = 0; i < recipe->getIngredientIds().size(); i++)
            infos.ingredients[recipe->getIngredientIds()[i]] = recipe->getQuantities()[i];

        m_recipes[recipe->getResultId()] = infos;
    }
}

void CraftManager::reset(SocketIO *sender)
{
    m_botData[sender].craftData.recipeQuantities.clear();
    m_botData[sender].craftData.recipeStack.clear();
    m_botData[sender].craftData.isCrafting = false;
    m_botData[sender].craftData.step = 0;
}

bool CraftManager::processCraft(SocketIO *sender)
{
    processCraftQuantities(sender);
    m_botData[sender].craftData.step = 0;

    if (m_botData[sender].craftData.recipeQuantities.isEmpty() || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
        return false;

    processCrafting(sender);
    return true;
}

void CraftManager::processCrafting(SocketIO *sender)
{
    processCraftQuantities(sender);

    if (m_botData[sender].craftData.craftList.isEmpty() || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
    {
        m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
        m_botData[sender].craftData.recipeQuantities.clear();
        m_botData[sender].craftData.recipeStack.clear();
        m_botData[sender].craftData.isCrafting = false;
        m_botData[sender].craftData.step = 0;

        emit scriptActionDone(sender);
        return;
    }

    foreach (RecipeInfos r, m_botData[sender].craftData.craftList)
    {
        if (m_botData[sender].craftData.recipeQuantities[r.recipeId])
        {
            foreach (InteractiveElementInfos ie, m_botData[sender].mapData.interactivesOnMap)
            {
                foreach (InteractiveSkillInfos is, ie.enabledSkills)
                {
                    if(is.ID == r.skillId)
                    {
                        m_botData[sender].craftData.isCrafting = true;
                        m_botData[sender].generalData.botState = BotState::CRAFTING_STATE;

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

                        QElapsedTimer mesure;
                        mesure.start();
                        NearestPathInfos nearestPath;
                        Pathfinding pathfinding;
                        nearestPath = pathfinding.findNearestPath(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId, m_botData[sender].mapData.map.getInteractiveElementCellID(ie.elementId), m_botData[sender].mapData.map.getMapId(), false, true, cells);
                        qDebug()<<"Temps pour trouver le chemin (ms):"<<mesure.elapsed()<<"(near "<<m_botData[sender].mapData.map.getInteractiveElementCellID(ie.elementId)<<")";

                        m_botData[sender].craftData.toCraft = r;
                        m_botData[sender].craftData.craftingBench = ie;
                        m_botData[sender].craftData.craftingBenchSkill = is;

                        if (nearestPath.path.last() == m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId)
                            useCraftingBench(sender);
                        else
                            m_botData[sender].farmData.moved = m_mapManager->changeToNearestCell(sender, m_botData[sender].mapData.map.getInteractiveElementCellID(ie.elementId));

                        return;
                    }
                }
            }
        }
    }

    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
    m_botData[sender].craftData.recipeQuantities.clear();
    m_botData[sender].craftData.recipeStack.clear();
    m_botData[sender].craftData.isCrafting = false;
    m_botData[sender].craftData.step = 0;

    emit scriptActionDone(sender);
    return;
}

void CraftManager::useCraftingBench(SocketIO *sender)
{
    // TODO: Hugo FIX
    if(m_botData[sender].scriptData.activeModule == ManagerType::CRAFT && !m_botData[sender].farmData.farming)
    {
        InteractiveElementInfos ie = m_botData[sender].craftData.craftingBench;
        InteractiveSkillInfos is = m_botData[sender].craftData.craftingBenchSkill;

        InteractiveUseRequestMessage message;
        message.elemId = ie.elementId;
        message.skillInstanceUid = is.UID;

        sender->send(message);
    }
}

void CraftManager::couldNotMove(SocketIO *sender)
{
    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
    m_botData[sender].craftData.recipeQuantities.clear();
    m_botData[sender].craftData.recipeStack.clear();
    m_botData[sender].craftData.isCrafting = false;
    m_botData[sender].craftData.step = 0;

    emit scriptActionDone(sender);
}

void CraftManager::processCraftQuantities(SocketIO *sender)
{
    m_botData[sender].craftData.recipeQuantities.clear();
    QList<RecipeInfos> updatedRecipes = m_botData[sender].craftData.craftList;
    QList<InventoryObject> inventoryContent = m_botData[sender].playerData.inventoryContent;

    foreach (RecipeInfos r, updatedRecipes)
    {
        int i = 0;
        while (canCraftItem(sender, inventoryContent, r))
        {
            removeFromInventory(inventoryContent, r);
            i++;
        }

        if (!i)
            continue;
        else if ((r.quantity == -1) || (i < r.quantity))
            m_botData[sender].craftData.recipeQuantities[r.recipeId] = i;
        else if (i > r.quantity)
            m_botData[sender].craftData.recipeQuantities[r.recipeId] = r.quantity;
    }
}

bool CraftManager::canCraftItem(SocketIO *sender, QList<InventoryObject> inventory, RecipeInfos recipe)
{
    if (m_botData[sender].craftData.jobs[recipe.jobId].jobLevel < recipe.joblevel)
        return false;

    QMap<uint, uint> objects;
    foreach (InventoryObject o, inventory)
        objects[o.GID] = o.quantity;

    bool ok = true;
    foreach (uint id, recipe.ingredients.keys())
        if (objects[id] < recipe.ingredients[id])
            ok = false;

    return false;
}

void CraftManager::removeFromInventory(QList<InventoryObject> &inventory, RecipeInfos recipe)
{
    foreach (uint id, recipe.ingredients.keys())
        for (QList<InventoryObject>::iterator i = inventory.begin(); i != inventory.end(); i++)
            if ((*i).GID == id)
                (*i).quantity -= recipe.ingredients[id];
}

void CraftManager::addCraftComponent(SocketIO *sender, QSharedPointer<ObjectItem> o)
{
    m_botData[sender].craftData.recipeStack[o->objectGID] = o->quantity;
}

bool CraftManager::compareRecipes(QMap<uint, uint> left, QMap<uint, uint> right)
{
    foreach (int i, left.keys())
        if (left[i] != right[i])
            return false;

    foreach (int i, right.keys())
        if (right[i] != left[i])
            return false;

    return true;
}

QList<uint> CraftManager::getCraftList(SocketIO *sender) const
{
    QList<uint> craftId;
    foreach (RecipeInfos infos, m_botData[sender].craftData.craftList)
        craftId << infos.recipeId;

    return craftId;
}

QMap<QString, uint> CraftManager::getRecipesName() const
{
    return m_recipesName;
}

void CraftManager::addItemToCraftList(SocketIO *sender, QString craft)
{
    m_botData[sender].craftData.craftList << m_recipes[m_recipesName[craft]];
    processCraftQuantities(sender);
}

void CraftManager::removeItemOfCraftList(SocketIO *sender, uint index)
{
    m_botData[sender].craftData.craftList.removeAt(index);
    processCraftQuantities(sender);
}

void CraftManager::updateQuantity(SocketIO *sender, uint index, int quantity)
{
    m_botData[sender].craftData.craftList[index].quantity = quantity;
    processCraftQuantities(sender);
}
