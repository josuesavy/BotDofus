#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern "C"
{
#include "Lua514/include/lua.h"
#include "Lua514/include/lauxlib.h"
#include "Lua514/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "Lua514/lua5.1.lib")
#endif

#include <QString>
#include <QDebug>

struct global
{
    static int printMessage(lua_State *L)
    {
        qDebug() << "[Script]" << luaL_checkstring(L, 1);
        return 0;
    }

    static int printSuccess(lua_State *L)
    {
        qDebug() << "(Success) [Script]" << luaL_checkstring(L, 1);
        return 0;
    }

    static int printWarning(lua_State *L)
    {
        qDebug() << "(Warning) [Script]" << luaL_checkstring(L, 1);
        return 0;
    }

    static int printError(lua_State *L)
    {
        qDebug() << "(Error) [Script]" << luaL_checkstring(L, 1);
        return 0;
    }


    static int getCountFight(lua_State *L)
    {
        lua_pushnumber(L, 1);
        return 1;
    }

    static int getCountGather(lua_State *L)
    {
        lua_pushnumber(L, 1);
        return 1;
    }


    static void delay(int mills);

    static void finishScript();
};


struct character
{
public:
    QString name();
    int level();
    int lifePoints();
    int maxLifePoints();
    double experience();
    int energyPoints();
    int maxEnergyPoints();
    double kamas();
    bool sex();
    int breed();
    bool freeMode();
};


struct inventory
{
public:
    int pods();
    int podsMax();
    QString nameItem(int id);
    bool useItem(int id);
    bool equipItem(int id);
    bool throwItem(int id);
    bool deleteItem(int id, int quantity);
};


struct exchange
{
public:

};


struct map
{
public:
    void moveToCell(int cellid);
    void changeMap(QString direction);
    void door(int cellid);
    bool onCell(int cellid);
    bool onMap(QString position);
    bool onMap(int mapid);
    int currentMap();
    QString currentMapId();
    int currentCell();
    QString currentArea();
    QString currentSubArea();
    int countPlayers();
    bool isPlayerOnMap(QString name);
};


struct flood
{
public:
    void sendGeneralMessage(QString text);
    void sendTeamMessage(QString text);
    void sendGuildMessage(QString text);
    void sendAllianceMessage(QString text);
    void sendPartyMessage(QString text);
    void sendPrivateMessage(QString dest, QString text);
    void sendArenaMessage(QString text);
    void sendCommunityMessage(QString text);
    void sendSaleMessage(QString text);
    void sendSeekMessage(QString text);
};


struct farm
{
public:
    QString name(int id);
    int level(int id);
};


struct mount
{
public:
    bool hasMount();
    bool isRiding();
    void toggleRiding();
    int energy();
    void feedMount(int id, int quantity);
    int xpRatio();
    void setXpRatio(int exp);
    int level();
};

#endif // FUNCTIONS_H
