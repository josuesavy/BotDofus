#ifndef MAPMETHODS_H
#define MAPMETHODS_H

extern "C"
{
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
}

#include "src/engines/DataHandler.h"
#include "src/engines/core/process/managers/map/MapManager.h"
#include "src/engines/core/process/managers/fight/FightManager.h"

class MapMethods : public DataHandler
{
public:
    static int changeMap(lua_State *L, SocketIO *sender, MapManager *mapManager)
    {
        // get parameters
        QString direction = lua_tostring(L, 1);

        // process
        QList<MapSide> sides;
        QStringList directions = direction.split("|");
        foreach (QString d, directions)
        {
            s.replace(" ", "");

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

        if (m_mapManager->changeMap(sender, side))
            m_botData[sender].scriptData.scriptMaxTime = 60000;
        else
            action(sender) << "Une erreur est survenue, impossible de passer d'une carte à une autre";

        // return the result

        return 1;
    }

    static int countPlayers(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process
        int countPlayers = m_botData[sender].mapData.playersOnMap.size();

        // return the result
        lua_pushinteger(L, countPlayers);

        return 1;
    }

    static int currentArea(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process
        QSharedPointer<SubAreaData> subAreas = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QString currentArea = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subAreas->getAreaId()))->getName();

        // return the result
        lua_pushstring(L, currentArea.toStdString().c_str());

        return 1;
    }

    static int currentSubArea(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process
        QSharedPointer<SubAreaData> subAreas = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QString currentSubArea = subAreas->getName();

        // return the result
        lua_pushstring(L, currentSubArea.toStdString().c_str());

        return 1;
    }

    static int currentCell(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process
        int cellId = m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId;

        // return the result
        lua_pushinteger(L, cellId);

        return 1;
    }

    static int currentMap(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process
        QString currentMap = QString("%1,%2").arg(m_botData[sender].mapData.map.getPosition().getX()).arg(m_botData[sender].mapData.map.getPosition().getY());

        // return the result
        lua_pushstring(L, currentMap.toStdString().c_str());

        return 1;
    }

    static int currentMapId(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process
        int currentMapId = m_botData[sender].mapData.map.getMapId();

        // return the result
        lua_pushinteger(L, currentMapId);

        return 1;
    }

    static int door(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process

        // return the result

        return 1;
    }

    static int fight(lua_State *L, SocketIO *sender, FightManager *fightManager)
    {
        // get parameters

        // process
        fightManager->processMonsters(sender);

        // return the result

        return 1;
    }

    static int moveToCell(lua_State *L, SocketIO *sender, MapManager *mapManager)
    {
        // get parameters
        int cellId = lua_tointeger(L, 1);

        // process
        mapManager->changeCell(sender, cellId);

        // return the result

        return 1;
    }

    static int onCell(lua_State *L, SocketIO *sender)
    {
        // get parameters
        int cellId = lua_tointeger(L, 1);

        // process
        bool onCell = m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId == cellId?true:false;

        // return the result
        lua_pushboolean(L, onCell);

        return 1;
    }

    static int onMap(lua_State *L, SocketIO *sender)
    {
        // get parameters
        QString mapPosition;
        if (lua_isstring(L, -1))
        {
            mapPosition = lua_tostring(L, 1);
        }

        int mapId = INVALID;
        if(lua_isinteger(L, -1))
        {
            mapId = lua_tointeger(L, 1);
        }

        // process
        bool onMap = false;
        if (!mapPosition.isEmpty() && mapId == INVALID)
        {
            if (mapPosition.split(',').at(0) == QString::number(m_botData[sender].mapData.map.getPosition().getX()) && mapPosition.split(',').at(1) == QString::number(m_botData[sender].mapData.map.getPosition().getY()))
            {
                onMap = true;
            }
        }
        else if (mapPosition.isEmpty() && mapId > 0)
        {
            if (mapId == m_botData[sender].mapData.map.getMapId())
                onMap = true;
        }

        // return the result
        lua_pushboolean(L, onMap);

        return 1;
    }

    static int saveZaap(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process

        // return the result

        return 1;
    }

    static int useById(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process

        // return the result

        return 1;
    }

    static int lockedHouse(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process

        // return the result

        return 1;
    }

    static int lockedStorage(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process

        // return the result

        return 1;
    }
};

#endif // MAPMETHODS_H
