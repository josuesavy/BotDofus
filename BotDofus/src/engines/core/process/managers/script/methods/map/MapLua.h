#ifndef MAP_LUA_H
#define MAP_LUA_H

#include "src/engines/core/CoreEngine.h"

class MapLua: public CoreEngine
{
public:
    void changeMap(SocketIO *sender, QString direction)
    {
        QList<MapSide> sides;
        QStringList directions = direction.split("|");
        foreach (QString d, directions)
        {
            d.replace(" ", "");

            QRegularExpression t("[tT][oO][pP]");
            QRegularExpression l("[lL][eE][fF][tT]");
            QRegularExpression r("[rR][iI][gG][hH][tT]");
            QRegularExpression b("[bB][oO][tT][tT][oO][mM]");

            QRegularExpressionMatch mt = t.match(d);
            QRegularExpressionMatch ml = l.match(d);
            QRegularExpressionMatch mr = r.match(d);
            QRegularExpressionMatch mb = b.match(d);

            if (mt.hasMatch())
                sides.append(MapSide::TOP);
            else if (ml.hasMatch())
                sides.append(MapSide::LEFT);
            else if (mr.hasMatch())
                sides.append(MapSide::RIGHT);
            else if (mb.hasMatch())
                sides.append(MapSide::BOTTOM);
            else
                sides = QList<MapSide>();
        }

        MapSide side = sides[QRandomGenerator::global()->generate() % sides.size()];
        m_botData[sender].scriptData.activeManager = ManagerType::MAP;

        if (getMapManager().changeMap(sender, side))
            m_botData[sender].scriptData.scriptMaxTime = 60000;
        else
            action(sender) << "Une erreur est survenue, impossible de passer d'une carte à une autre";
    }

    int countPlayers(SocketIO *sender)
    {
        return m_botData[sender].mapData.playersOnMap.size();
    }

    QString currentArea(SocketIO *sender)
    {
        QSharedPointer<SubAreaData> subAreas = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QString currentArea = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subAreas->getAreaId()))->getName();
        return currentArea;
    }

    QString currentSubArea(SocketIO *sender)
    {
        QSharedPointer<SubAreaData> subAreas = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QString currentSubArea = subAreas->getName();
        return currentSubArea;
    }

    int currentCell(SocketIO *sender)
    {
        return m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId;
    }

    QString currentMap(SocketIO *sender)
    {
        QString currentMap = QString("%1,%2").arg(m_botData[sender].mapData.map.getPosition().getX()).arg(m_botData[sender].mapData.map.getPosition().getY());
        return currentMap;
    }

    int currentMapId(SocketIO *sender)
    {
        return m_botData[sender].mapData.map.getMapId();
    }

    void door(SocketIO *sender)
    {

    }

    void fight(SocketIO *sender)
    {
        getFightManager().processMonsters(sender);
    }

    void moveToCell(SocketIO *sender, int cellId)
    {
        getMapManager().changeCell(sender, cellId);
    }

    int onCell(SocketIO *sender, int cellId)
    {
        bool onCell = m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId == cellId?true:false;
        return onCell;
    }

    bool onMap(SocketIO *sender, QString mapPosition)
    {
        bool onMap = false;
        if (mapPosition.split(',').at(0) == QString::number(m_botData[sender].mapData.map.getPosition().getX()) && mapPosition.split(',').at(1) == QString::number(m_botData[sender].mapData.map.getPosition().getY()))
            {
                onMap = true;
            }

        return onMap;
    }

    bool onMap(SocketIO *sender, int mapId)
    {
        // process
        bool onMap = false;
        if (mapId == m_botData[sender].mapData.map.getMapId())
            onMap = true;
        return onMap;
    }

    void saveZaap(SocketIO *sender)
    {

    }

    void useById(SocketIO *sender)
    {

    }

    bool lockedHouse(SocketIO *sender)
    {
        return false;
    }

    bool lockedStorage(SocketIO *sender)
    {
        return false;
    }
};

#endif // MAP_LUA_H
