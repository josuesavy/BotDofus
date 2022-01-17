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

    ui->labelMapID->installEventFilter(this);
    displayCellIds(false);
    cellClicked(false);

    qmlRegisterType<MapForm>("MapViewerCellEnum", 1, 0, "MapForm");

    ui->quickWidget->rootContext()->setContextProperty("mapForm", this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/qml/Map.qml")));

    initCells();
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

bool MapForm::eventFilter(QObject *object, QEvent *event)
{
    if( event->type() == QEvent::ContextMenu && object == ui->labelMapID)
    {
        QGuiApplication::clipboard()->setText(ui->labelMapID->text().split(':').last().replace(" ", ""));
    }

    return QWidget::eventFilter(object, event);
}

void MapForm::initCells()
{
    tileWidth = ui->quickWidget->width()/14*13.5/14;
    tileHeight = ui->quickWidget->height()/20*19/20;

    int startX = 0;
    int startY = 0;
    int cell = 0;
    for (int a = 0; a < 20; a++)
    {
        for (int b = 0; b < 14; b++)
        {
            QPointF p = cellCoords(cell);
            cellPos[cell] = QPointF((p.x() * tileWidth + (fmod(p.y(), 2) == 1 ? tileWidth / 2 : 0))+tileWidth/2+10, (p.y() * tileHeight / 2)+tileHeight/2+9 );
            cell++;
        }
        startX++;

        for (int b = 0; b < 14; b++)
        {
            QPointF p = cellCoords(cell);
            cellPos[cell] = QPointF((p.x() * tileWidth + (fmod(p.y(), 2) == 1 ? tileWidth / 2 : 0))+tileWidth/2+10, (p.y() * tileHeight / 2)+tileHeight/2+9 );
            cell++;
        }
        startY--;
    }
}

QPointF MapForm::cellCoords(int cellId)
{
    return QPointF(cellId % 14, qFloor(cellId / 14));
}

void MapForm::changeCell(uint cell)
{
    m_engine->getMapManager().changeCell(m_sender, cell);
}

void MapForm::changeToNearestCell(uint cell)
{
    m_engine->getMapManager().changeToNearestCell(m_sender, cell);
}

void MapForm::useInteractive(int cell)
{
    foreach (InteractiveDisplayInfos interactive, interactiveDisplayInfosList)
    {
        if(interactive.cellId == cell)
        {
            m_engine->getInteractionManager().processUse(m_sender, interactive.id);
            break;
        }
    }
}

void MapForm::useDoorInteractive(int cell)
{
    foreach (InteractiveDisplayInfos interactive, interactiveDisplayInfosList)
    {
        if(interactive.cellId == cell)
        {
            m_engine->getInteractionManager().processUseDoor(m_sender, interactive.id);
            break;
        }
    }
}

void MapForm::showInfos(int cell)
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

        if(m_mapId != infos.mapData.map.getMapId())
            updateFullMap();

        if(m_playersOnMap.size() != infos.mapData.playersOnMap.size() || m_merchantsOnMap.size() != infos.mapData.merchantsOnMap.size() || m_monstersOnMap.size() != infos.mapData.monsterGroupsOnMap.size() ||  m_playersOnMap != playersOnMap || m_monstersOnMap != monstersOnMap)
            updateMap();

        ui->labelMapID->setText(QString("MapID : %1").arg(infos.mapData.map.getMapId()));
    }

    if (infos.connectionData.connectionState == ConnectionState::TRANSITION)
    {

    }

    if (infos.connectionData.connectionState == ConnectionState::DISCONNECTED)
    {

    }
}

void MapForm::updateFullMap()
{
    const BotData &infos = getData();

    if (infos.mapData.map.isInit())
    {
        entityTypes(QList<int>());
        interactiveTypes(QList<int>());
        collisionTypes(QList<int>());

        m_mapId = infos.mapData.map.getMapId();

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

            collisionTypes(collisions);
        }

        else
        {
            QList<CellData> mapCells = infos.mapData.map.getCellData();
            QList<int> collisions;

            for(int i = 0; i < 560; i++)
            {
                // Map
                if(mapCells[i].isWalkable())
                    collisions<<((uint)MapViewerCellEnum::NOTHING);

                else if(mapCells[i].isLos())
                    collisions<<((uint)MapViewerCellEnum::COLLISION_WITH_SIGHT);

                else
                    collisions<<((uint)MapViewerCellEnum::COLLISION_NO_SIGHT);
            }

            collisionTypes(collisions);
        }
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
            foreach(const EntityInfos &entity, infos.mapData.playersOnMap)
            {
                if (entityInfosList.size() > 0)
                {
                    foreach (const EntityInfos &entity2, entityInfosList)
                    {

                    }
                }
                else
                {
                    QVariant returnedValue;
                    QVariant actorId = entity.entityId;
                    QVariantList paths;
                    QVariant duration = 7000;
                    QVariant type = (uint)MapViewerCellEnum::PLAYER;
                    if (entity.keyMovements.size() > 0)
                    {
                        for (int i = 0; i < entity.keyMovements.size(); i++)
                        {
                            paths << cellPos[entity.keyMovements.at(i)];
                        }
                    }
                    else
                        paths << cellPos[entity.cellId];

                    QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addEntity",
                                              Q_RETURN_ARG(QVariant, returnedValue),
                                              Q_ARG(QVariant, actorId),
                                              Q_ARG(QVariant, QVariant::fromValue(paths)),
                                              Q_ARG(QVariant, duration),
                                              Q_ARG(QVariant, type));
                }
            }

            m_npcsOnMap.clear();
            foreach(const NpcInfos &npc, infos.mapData.npcsOnMap)
            {
                QVariant returnedValue;
                QVariant actorId = npc.contextualId;
                QVariantList paths;
                paths << cellPos[npc.cellId];
                QVariant duration = 7000;
                QVariant type = (uint)MapViewerCellEnum::NPC;

                QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addEntity",
                                          Q_RETURN_ARG(QVariant, returnedValue),
                                          Q_ARG(QVariant, actorId),
                                          Q_ARG(QVariant, QVariant::fromValue(paths)),
                                          Q_ARG(QVariant, duration),
                                          Q_ARG(QVariant, type));
            }

            foreach (const NpcQuestInfos &npc, infos.mapData.npcsQuestOnMap)
            {
                QVariant returnedValue;
                QVariant actorId = npc.contextualId;
                QVariantList paths;
                paths << cellPos[npc.cellId];
                QVariant duration = 7000;
                QVariant type = (uint)MapViewerCellEnum::NPC;

                QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addEntity",
                                          Q_RETURN_ARG(QVariant, returnedValue),
                                          Q_ARG(QVariant, actorId),
                                          Q_ARG(QVariant, QVariant::fromValue(paths)),
                                          Q_ARG(QVariant, duration),
                                          Q_ARG(QVariant, type));
            }

            m_merchantsOnMap.clear();
            foreach(const MerchantInfos &merchant, infos.mapData.merchantsOnMap)
            {
                QVariant returnedValue;
                QVariant actorId = merchant.merchantId;
                QVariantList paths;
                paths << cellPos[merchant.cellId];
                QVariant duration = 7000;
                QVariant type = (uint)MapViewerCellEnum::MERCHANT;

                QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addEntity",
                                          Q_RETURN_ARG(QVariant, returnedValue),
                                          Q_ARG(QVariant, actorId),
                                          Q_ARG(QVariant, QVariant::fromValue(paths)),
                                          Q_ARG(QVariant, duration),
                                          Q_ARG(QVariant, type));
            }

            m_monstersOnMap.clear();
            foreach(const MonsterGroup &monster, infos.mapData.monsterGroupsOnMap)
            {
                QVariant returnedValue;
                QVariant actorId = monster.contextualID;
                QVariantList paths;
                QVariant duration = 7000;
                QVariant type = (uint)MapViewerCellEnum::MONSTER;
                if (monster.keyMovements.size() > 0)
                {
                    for (int i = 0; i < monster.keyMovements.size(); i++)
                    {
                        paths << cellPos[monster.keyMovements.at(i)];
                    }
                }
                else
                    paths << cellPos[monster.cellID];

                QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addEntity",
                                          Q_RETURN_ARG(QVariant, returnedValue),
                                          Q_ARG(QVariant, actorId),
                                          Q_ARG(QVariant, QVariant::fromValue(paths)),
                                          Q_ARG(QVariant, duration),
                                          Q_ARG(QVariant, type));
            }

            QMap<int, int> interactivesCellId;
            for(int i = 0; i < infos.mapData.interactivesOnMap.size(); i++)
                interactivesCellId[infos.mapData.map.getInteractiveElementCellID(infos.mapData.interactivesOnMap[i].elementId)] = i;

            QMap<int, int> doorsCellId;
            for(int i = 0; i < infos.mapData.doorsOnMap.size(); i++)
                doorsCellId[infos.mapData.doorsOnMap[i].cellId] = i;

            QList<CellData> mapCells = infos.mapData.map.getCellData();
            QList<int> interactives;

            for(int i = 0; i < 560; i++)
            {
                // Interactives
                if(interactivesCellId.keys().contains(i))
                {
                    if(FarmManager::canFarmResource(infos.mapData.interactivesOnMap[interactivesCellId[i]]))
                        interactives<<((uint)MapViewerCellEnum::USABLE);

                    else
                        interactives<<((uint)MapViewerCellEnum::INTERACTIVE);
                }

                else if(doorsCellId.keys().contains(i))
                    interactives<<((uint)MapViewerCellEnum::DOOR);

                else
                    interactives<<MapViewerCellEnum::NOTHING;
            }

            //interactiveTypes(interactives);


            interactiveDisplayInfosList.clear();
            foreach (InteractiveDisplayInfos interactive, infos.interactionData.interactives)
            {
                InteractiveDisplayInfos in;
                in.id = interactive.id;
                in.cellId = interactive.cellId;
                in.name = interactive.name;
                interactiveDisplayInfosList<<in;
            }

            monsterGroupList.clear();
            foreach (MonsterGroup monster, infos.mapData.monsterGroupsOnMap.values())
                monsterGroupList << monster;

            entityInfosList.clear();
            foreach (EntityInfos player, infos.mapData.playersOnMap.values())
                entityInfosList << player;

            merchantInfosList.clear();
            foreach (MerchantInfos merchant, infos.mapData.merchantsOnMap.values())
                merchantInfosList << merchant;

            npcInfosList.clear();
            foreach (NpcInfos npc, infos.mapData.npcsOnMap.values())
                npcInfosList << npc;

            npcQuestInfosList.clear();
            foreach (NpcQuestInfos npc, infos.mapData.npcsQuestOnMap.values())
                npcQuestInfosList << npc;
        }
    }
}

void MapForm::resizeEvent(QResizeEvent *event)
{
    // size: 698x495

//    float aspectRatio = 451 / 316;
//    ui->quickWidget->resize(ui->quickWidget->width()*aspectRatio, ui->quickWidget->height()*aspectRatio);
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
