#include "mapform.h"
#include "ui_mapform.h"

MapForm::MapForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapForm)
{
    ui->setupUi(this);

    // Liste d'initialisations
    m_engine = engine;
    m_infos = infos;
    m_sender = sender;

    displayCellIds(false);
    cellClicked(false);

    qmlRegisterType<MapForm>("MapViewerCellEnum", 1, 0, "MapForm");

    ui->quickWidget->rootContext()->setContextProperty("mapForm", this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/qml/Map.qml")));
}

MapForm::~MapForm()
{
    delete ui;
}

SocketIO *MapForm::getSocket()
{
    return m_sender;
}

ConnectionInfos MapForm::getConnectionInfos() const
{
    return m_infos;
}

const BotData &MapForm::getData() const
{
    return m_engine->getData(m_sender);
}

void MapForm::changeCell(uint cell)
{
    m_engine->getMapManager().changeCell(m_sender, cell);
}

void MapForm::changeToNearestCell(uint cell)
{
    m_engine->getMapManager().changeToNearestCell(m_sender, cell);
}

void MapForm::useInteractive(uint cell)
{
    foreach (InteractiveDisplayInfos interactive, interactiveDisplayInfosList)
    {
        if(interactive.cellId == cell && interactive.name.isEmpty())
        {
            m_engine->getInteractionManager().processUse(m_sender, interactive.id);
            break;
        }
    }
}

void MapForm::showInfos(uint cell)
{
    QString txt;

    foreach (InteractiveDisplayInfos interactive, interactiveDisplayInfosList)
    {
        if(interactive.cellId == cell)
            txt += QString("%1 (ID: %2, CellId: %3)").arg(interactive.name).arg(interactive.id).arg(interactive.cellId);
    }

    foreach (MonsterGroup monsters, monsterGroupList)
    {
        if(monsters.cellID == cell)
        {
            if(!txt.isEmpty())
                txt += "\n";

            txt += QString("<b><center>Level %1<center></b>").arg(monsters.level);

            foreach(Monster monster, monsters.monsters)
            {
                QSharedPointer<MonsterData> m = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, monster.id));
                txt += QString("<center>%1 (%2)</center>\n").arg(m->getName()).arg(monster.level);
            }

            txt.remove(txt.length()-2, 3); //remove last '\n'
        }
    }

    foreach (EntityInfos entity, entityInfosList)
    {
        if(entity.cellId == cell)
        {
            if(!txt.isEmpty())
                txt += "\n";

            txt += QString("%1 (Lvl. %2)").arg(entity.name).arg(entity.level);
        }
    }

    foreach (MerchantInfos merchant, merchantInfosList)
    {
        if (merchant.cellId == cell)
        {
            if (!txt.isEmpty())
                txt += "\n";

            txt += QString("%1 (Merchant)").arg(merchant.name);
        }
    }

    foreach (NpcInfos npc, npcInfosList)
    {
        if(npc.cellId == cell)
        {
            if(!txt.isEmpty())
                txt += "\n";

            QSharedPointer<NpcData> npcData = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npc.npcId));
            txt += QString("%1").arg(npcData->getName());
        }
    }

    foreach (NpcQuestInfos npcQuest, npcQuestInfosList)
    {
        if(npcQuest.cellId == cell)
        {
            if(!txt.isEmpty())
                txt += "\n";

            QSharedPointer<NpcData> npcData = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npcQuest.npcId));
            txt += QString("%1 (Quest)").arg(npcData->getName());
        }
    }

    if(!txt.isEmpty())
        QToolTip::showText(QCursor::pos(), txt);
    else
        QToolTip::hideText();
}

void MapForm::updateInterface()
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        QList<uint> playersOnMap;
        QList<uint> merchantsOnMap;
        QList<uint> monstersOnMap;

        foreach(const EntityInfos &entity, infos.mapData.playersOnMap.values())
            playersOnMap<<entity.cellId;

        foreach (const MerchantInfos &merchant, infos.mapData.merchantsOnMap.values())
            merchantsOnMap<<merchant.cellId;

        foreach(const MonsterGroup &monster, infos.mapData.monsterGroupsOnMap.values())
            monstersOnMap<<monster.cellID;

        if(m_mapId != infos.mapData.map.getMapId() || m_playersOnMap.size() != infos.mapData.playersOnMap.size() || m_merchantsOnMap.size() != infos.mapData.merchantsOnMap.size() || m_monstersOnMap.size() != infos.mapData.monsterGroupsOnMap.size() ||  m_playersOnMap != playersOnMap || m_monstersOnMap != monstersOnMap)
            updateMap();
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {

    }
}

void MapForm::updateMap()
{
    const BotData &infos = getData();

    if (infos.mapData.map.isInit())
    {
        if(infos.generalData.botState == FIGHTING_STATE)
        {
            int selfCellId = infos.fightData.fighters[infos.mapData.botId].cellId;

            m_defenderOnMap.clear();
            m_challengerOnMap.clear();

            QMapIterator<double, FightEntityInfos> fighter(infos.fightData.fighters);
            while (fighter.hasNext())
            {
                fighter.next();
                if(infos.fightData.fightType == FightTypeEnum::FIGHT_TYPE_AGRESSION)
                {
                    if(fighter.value().teamId == TeamEnum::TEAM_DEFENDER && fighter.value().isAlive)
                        m_challengerOnMap << fighter.value().cellId;

                    if(fighter.value().teamId == TeamEnum::TEAM_CHALLENGER && fighter.value().isAlive)
                        m_defenderOnMap << fighter.value().cellId;
                }

                else
                {
                    if(fighter.value().teamId == TeamEnum::TEAM_DEFENDER && fighter.value().isAlive)
                        m_defenderOnMap << fighter.value().cellId;

                    if(fighter.value().teamId == TeamEnum::TEAM_CHALLENGER && fighter.value().isAlive)
                        m_challengerOnMap << fighter.value().cellId;
                }
            }

            QList<CellData> mapCells = infos.mapData.map.getCellData();
            QList<int> collisions;
            QList<int> entities;

            for(int i = 0; i < 560; i++)
            {
                if(mapCells[i].isWalkable())
                    collisions << ((uint)MapViewerCellEnum::NOTHING);

                else if(mapCells[i].isLos())
                    collisions << ((uint)MapViewerCellEnum::COLLISION_WITH_SIGHT);

                else
                    collisions << ((uint)MapViewerCellEnum::COLLISION_NO_SIGHT);


                if(m_defenderOnMap.contains(i))
                    entities << ((uint)MapViewerCellEnum::MONSTER);

                else if(m_challengerOnMap.contains(i))
                {
                    if(i == selfCellId)
                        entities << ((uint)MapViewerCellEnum::BOT);

                    else
                        entities << ((uint)MapViewerCellEnum::PLAYER);
                }

                else
                    entities << MapViewerCellEnum::NOTHING;
            }

            entityTypes(entities);
            collisionTypes(collisions);
        }

        else
        {
            int selfCellId = infos.mapData.playersOnMap[infos.mapData.botId].cellId;

            m_playersOnMap.clear();
            m_npcsOnMap.clear();
            m_merchantsOnMap.clear();
            m_monstersOnMap.clear();

            foreach(const EntityInfos &entity, infos.mapData.playersOnMap)
                m_playersOnMap << entity.cellId;

            foreach(const NpcInfos &npc, infos.mapData.npcsOnMap)
                m_npcsOnMap << npc.cellId;

            foreach (const NpcQuestInfos &npc, infos.mapData.npcsQuestOnMap)
                m_npcsOnMap << npc.cellId;

            foreach(const MerchantInfos &merchant, infos.mapData.merchantsOnMap)
                m_merchantsOnMap << merchant.cellId;

            foreach(const MonsterGroup &monster, infos.mapData.monsterGroupsOnMap)
                m_monstersOnMap<<monster.cellID;

            QMap<int, int> interactivesCellId;
            for(int i = 0; i < infos.mapData.interactivesOnMap.size(); i++)
            {
                //if (infos.mapData.interactivesOnMap[i].elementTypeId > INVALID)
                //{
                    interactivesCellId[infos.mapData.map.getInteractiveElementCellID(infos.mapData.interactivesOnMap[i].elementId)] = i;
                //}
            }


            QList<CellData> mapCells = infos.mapData.map.getCellData();
            QList<int> collisions;
            QList<int> interactives;
            QList<int> entities;

            for(int i = 0; i < 560; i++)
            {
                if(mapCells[i].isWalkable())
                    collisions<<((uint)MapViewerCellEnum::NOTHING);

                else if(mapCells[i].isLos())
                    collisions<<((uint)MapViewerCellEnum::COLLISION_WITH_SIGHT);

                else
                    collisions<<((uint)MapViewerCellEnum::COLLISION_NO_SIGHT);


                if(m_monstersOnMap.contains(i))
                    entities<<((uint)MapViewerCellEnum::MONSTER);

                else if(m_playersOnMap.contains(i))
                {
                    if(i == selfCellId)
                        entities<<((uint)MapViewerCellEnum::BOT);

                    else
                        entities<<((uint)MapViewerCellEnum::PLAYER);
                }

                else if(m_npcsOnMap.contains(i))
                    entities<<((uint)MapViewerCellEnum::NPC);

                else if(m_merchantsOnMap.contains(i))
                    entities<<((uint)MapViewerCellEnum::MERCHANT);

                else
                    entities<<MapViewerCellEnum::NOTHING;


                if(interactivesCellId.keys().contains(i))
                {
                    if(FarmManager::canFarmResource(infos.mapData.interactivesOnMap[interactivesCellId[i]]))
                        interactives<<((uint)MapViewerCellEnum::USABLE);

                    else
                        interactives<<((uint)MapViewerCellEnum::INTERACTIVE);
                }

                else
                    interactives<<MapViewerCellEnum::NOTHING;
            }

            entityTypes(entities);
            interactiveTypes(interactives);
            collisionTypes(collisions);

            interactiveDisplayInfosList.clear();
            monsterGroupList.clear();
            entityInfosList.clear();
            merchantInfosList.clear();
            npcInfosList.clear();
            npcQuestInfosList.clear();

            foreach (InteractiveDisplayInfos interactive, infos.interactionData.interactives)
            {
                InteractiveDisplayInfos in;
                in.id = interactive.id;
                in.cellId = interactive.cellId;
                in.name = interactive.name;
                interactiveDisplayInfosList<<in;
            }

            foreach (MonsterGroup monster, infos.mapData.monsterGroupsOnMap.values())
                monsterGroupList << monster;

            foreach (EntityInfos player, infos.mapData.playersOnMap.values())
                entityInfosList << player;

            foreach (MerchantInfos merchant, infos.mapData.merchantsOnMap.values())
                merchantInfosList << merchant;

            foreach (NpcInfos npc, infos.mapData.npcsOnMap.values())
                npcInfosList << npc;

            foreach (NpcQuestInfos npc, infos.mapData.npcsQuestOnMap.values())
                npcQuestInfosList << npc;
        }

        // Display Map's ID
        ui->labelMapID->setText(QString("MapID : %1").arg(infos.mapData.map.getMapId()));

        //m_interactiveModel->update(inl);
    }
}

void MapForm::resizeEvent(QResizeEvent *event)
{
    // size: 698x495

//    float aspectRatio = ui->widget_3->width() / ui->widget_3->height();
//    ui->widget_3->resize(ui->widget_3->height()*aspectRatio, ui->widget_3->height());
}

void MapForm::on_checkBoxDisplayCellIds_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
        displayCellIds(true);
    else
        displayCellIds(false);
}

void MapForm::on_pushButtonTop_clicked()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE && !getData().scriptData.isActive)
        m_engine->getMapManager().changeMap(m_sender, MapSide::TOP);
}

void MapForm::on_pushButtonLeft_clicked()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE && !getData().scriptData.isActive)
        m_engine->getMapManager().changeMap(m_sender, MapSide::LEFT);
}

void MapForm::on_pushButtonRight_clicked()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE && !getData().scriptData.isActive)
        m_engine->getMapManager().changeMap(m_sender, MapSide::RIGHT);
}

void MapForm::on_pushButtonBottom_clicked()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE && !getData().scriptData.isActive)
        m_engine->getMapManager().changeMap(m_sender, MapSide::BOTTOM);
}
