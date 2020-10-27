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

    displayCellIds(false); // Don't display cell id in the beginning
    cellClicked(false); // Don't display a random cell clicked
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
    m_engine->getMapModule().changeCell(m_sender, cell);
}

void MapForm::changeToNearestCell(uint cell)
{
    m_engine->getMapModule().changeToNearestCell(m_sender, cell);
}

void MapForm::useInteractive(uint cell)
{
    foreach (InteractiveDisplayInfos interactive, inl)
    {
        if(interactive.cellId == cell)
        {
            m_engine->getInteractionModule().processUse(m_sender, interactive.id,"");
            break;
        }
    }
}

void MapForm::showInfos(uint cell)
{
    QString txt;

    foreach (InteractiveDisplayInfos interactive, inl)
    {
        if(interactive.cellId == cell)
            txt += QString("%1 (ID: %2, CellId: %3)").arg(interactive.name).arg(interactive.id).arg(interactive.cellId);
    }

    foreach (MonsterGroup monsters, ml)
    {
        if(monsters.cellID == cell)
        {
            if(!txt.isEmpty())
                txt += "\n";

            txt += QString("<b><center>Niveau %1<center></b>").arg(monsters.level);
            txt += QString("<hr>");

            // stars empty: &#9734;
            // stars fill: &#9733;

            foreach(Monster monster, monsters.monsters)
            {
                QSharedPointer<MonsterData> m = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, monster.id));
                txt += QString("<br>%1 (%2)").arg(m->getName()).arg(monster.level);
            }
        }
    }

    foreach (EntityInfos entity, pl)
    {
        if(entity.cellId == cell)
        {
            if(!txt.isEmpty())
                txt += "\n";

            txt += QString("%1 (Niv. %2)").arg(entity.name).arg(entity.level);
        }
    }

    foreach (NpcInfos npc, npcl)
    {
        if(npc.cellId == cell)
        {
            if(!txt.isEmpty())
                txt += "\n";

            QSharedPointer<NpcData> npcData = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npc.npcId));
            txt += QString("%1").arg(npcData->getName());
        }
    }

    if(!txt.isEmpty())
        QToolTip::showText(QCursor::pos(), txt);
}

void MapForm::hideInfos()
{
    QToolTip::hideText();
}

void MapForm::updateInterface()
{
    const BotData &infos = getData();

    if (infos.connectionData.connectionState == ConnectionState::CONNECTED)
    {
        QList<uint> playersOnMap;
        QList<uint> monstersOnMap;

        foreach(const EntityInfos &entity, infos.mapData.playersOnMap.values())
            playersOnMap<<entity.cellId;

        foreach(const MonsterGroup &monster, infos.mapData.monsterGroupsOnMap.values())
            monstersOnMap<<monster.cellID;

        if(m_mapId != infos.mapData.map.getMapId() || m_playersOnMap.size() != infos.mapData.playersOnMap.size() || m_monstersOnMap.size() != infos.mapData.monsterGroupsOnMap.size() ||  m_playersOnMap != playersOnMap || m_monstersOnMap != monstersOnMap)
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
        int selfCellId = infos.fightData.fighters[infos.mapData.botId].cellId;

        if(infos.generalData.botState == FIGHTING_STATE)
        {
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
            QList<int> c;
            QList<int> z;
            QList<int> e;

            for(int i = 0; i < 560; i++)
            {
                if(mapCells[i].isWalkable())
                    c<<((uint)MapViewerCellEnum::NOTHING);

                else if(mapCells[i].isLos())
                    c<<((uint)MapViewerCellEnum::COLLISION_WITH_SIGHT);

                else
                    c<<((uint)MapViewerCellEnum::COLLISION_NO_SIGHT);


                if(m_defenderOnMap.contains(i))
                    e<<((uint)MapViewerCellEnum::MONSTER);

                else if(m_challengerOnMap.contains(i))
                {
                    if(i == selfCellId)
                        e<<((uint)MapViewerCellEnum::BOT);

                    else
                        e<<((uint)MapViewerCellEnum::PLAYER);
                }

                else
                    e<<MapViewerCellEnum::NOTHING;
            }

            entityTypes(e);
            interactiveTypes(z);
            collisionTypes(c);
        }

        else
        {
            QList<int> pnjsCellId;
            QList<int> merchantsCellId;
            QList<int> playersPathsCellId;
            QList<int> monstersPathsCellId;
            m_playersOnMap.clear();
            m_monstersOnMap.clear();

            foreach(const EntityInfos &entity, infos.mapData.playersOnMap)
                m_playersOnMap << entity.cellId;

            foreach(const NpcInfos &npc, infos.mapData.npcsOnMap)
                pnjsCellId << npc.cellId;

            foreach(const MerchantInfos &merchant, infos.mapData.merchantsOnMap)
                merchantsCellId << merchant.cellId;

            foreach(const MonsterGroup &monster, infos.mapData.monsterGroupsOnMap)
                m_monstersOnMap<<monster.cellID;

            QMap<int, int> interactivesCellId;

            for(int i = 0; i < infos.mapData.interactivesOnMap.size(); i++)
                interactivesCellId[infos.mapData.map.getInteractiveElementCellID(infos.mapData.interactivesOnMap[i].elementId)] = i;


            QList<CellData> mapCells = infos.mapData.map.getCellData();
            QList<int> c;
            QList<int> z;
            QList<int> e;

            for(int i = 0; i < 560; i++)
            {
                if(mapCells[i].isWalkable())
                    c<<((uint)MapViewerCellEnum::NOTHING);

                else if(mapCells[i].isLos())
                    c<<((uint)MapViewerCellEnum::COLLISION_WITH_SIGHT);

                else
                    c<<((uint)MapViewerCellEnum::COLLISION_NO_SIGHT);


                if(m_monstersOnMap.contains(i))
                    e<<((uint)MapViewerCellEnum::MONSTER);

                else if(m_playersOnMap.contains(i))
                {
                    if(i == selfCellId)
                        e<<((uint)MapViewerCellEnum::BOT);

                    else
                        e<<((uint)MapViewerCellEnum::PLAYER);
                }

                else if(pnjsCellId.contains(i))
                    e<<((uint)MapViewerCellEnum::NPC);

                else if(merchantsCellId.contains(i))
                    e<<((uint)MapViewerCellEnum::MERCHANT);

                else
                    e<<MapViewerCellEnum::NOTHING;


                if(interactivesCellId.keys().contains(i))
                {
                    if(FarmModule::canFarmResource(infos.mapData.interactivesOnMap[interactivesCellId[i]]))
                        z<<((uint)MapViewerCellEnum::USABLE);

                    else
                        z<<((uint)MapViewerCellEnum::INTERACTIVE);
                }

                else
                    z<<MapViewerCellEnum::NOTHING;
            }

            entityTypes(e);
            interactiveTypes(z);
            collisionTypes(c);

            inl.clear();
            ml.clear();
            pl.clear();
            npcl.clear();

            foreach (InteractiveDisplayInfos interactive, infos.interactionData.interactives)
            {
                InteractiveDisplayInfos in;
                in.id = interactive.id;
                in.cellId = interactive.cellId;
                in.name = interactive.name;
                inl<<in;
            }

            foreach (MonsterGroup monster, infos.mapData.monsterGroupsOnMap.values())
                ml << monster;

            foreach (EntityInfos player, infos.mapData.playersOnMap.values())
                pl << player;

            foreach (NpcInfos npc, infos.mapData.npcsOnMap.values())
                npcl << npc;
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
        m_engine->getMapModule().changeMap(m_sender, MapSide::TOP);
}

void MapForm::on_pushButtonLeft_clicked()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE && !getData().scriptData.isActive)
        m_engine->getMapModule().changeMap(m_sender, MapSide::LEFT);
}

void MapForm::on_pushButtonRight_clicked()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE && !getData().scriptData.isActive)
        m_engine->getMapModule().changeMap(m_sender, MapSide::RIGHT);
}

void MapForm::on_pushButtonBottom_clicked()
{
    if (getData().generalData.botState == BotState::INACTIVE_STATE && !getData().scriptData.isActive)
        m_engine->getMapModule().changeMap(m_sender, MapSide::BOTTOM);
}
