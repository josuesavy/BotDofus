#ifndef INVENTORYMETHODS_H
#define INVENTORYMETHODS_H

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#include "src/engines/core/process/managers/script/methods/inventory/Inventory.h"

class InventoryMethods
{
    static const char className[];
    static const luaL_Reg methods[12];

    static Inventory *checkinventory(lua_State *L, int narg) {
        luaL_checktype(L, narg, LUA_TUSERDATA);
        void *ud = luaL_checkudata(L, narg, className);
        if(!ud) luaL_typeerror(L, narg, className);
        return *(Inventory**)ud;  // unbox pointer
    }

    static int deleteItem(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int gid = luaL_checkinteger(L, 2);
        int quantity = luaL_checkinteger(L, 3);
        i->deleteItem(new SocketIO(), gid, quantity);
        return 0;
    }

    static int equipItem(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int gid = luaL_checkinteger(L, 2);
        i->equipItem(new SocketIO(), gid);
        return 0;
    }

    static int itemCount(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int gid = luaL_checkinteger(L, 2);
        int itemCount = i->itemCount(new SocketIO(), gid);
        lua_pushinteger(L, itemCount);
        return 1;
    }

    static int itemNameId(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int gid = luaL_checkinteger(L, 2);
        QString itemNameId = i->itemNameId(new SocketIO(), gid);
        lua_pushstring(L, itemNameId.toStdString().c_str());
        return 1;
    }

    static int itemTypeId(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int gid = luaL_checkinteger(L, 2);
        int itemTypeId = i->itemTypeId(new SocketIO(), gid);
        lua_pushinteger(L, itemTypeId);
        return 1;
    }

    static int itemWeight(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int gid = luaL_checkinteger(L, 2);
        int itemWeight = i->itemWeight(new SocketIO(), gid);
        lua_pushinteger(L, itemWeight);
        return 1;
    }

    static int pods(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int pods = i->pods(new SocketIO());
        lua_pushinteger(L, pods);
        return 1;
    }

    static int podsMax(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int podsMax = i->podsMax(new SocketIO());
        lua_pushinteger(L, podsMax);
        return 1;
    }

    static int podsP(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int podsP = i->podsP(new SocketIO());
        lua_pushinteger(L, podsP);
        return 1;
    }

    static int useItem(lua_State *L)
    {
        Inventory *i = checkinventory(L, 1);
        int gid = luaL_checkinteger(L, 2);
        i->useItem(new SocketIO(), gid);
        return 0;
    }

    static int inventoryContent(lua_State *L)
    {
        // TODO return map's list
        return 0;
    }

public:
    static void Register(lua_State* L) {
          lua_newtable(L);                 int methodtable = lua_gettop(L);
          luaL_newmetatable(L, className); int metatable   = lua_gettop(L);

          lua_pushliteral(L, "__metatable");
          lua_pushvalue(L, methodtable);
          lua_settable(L, metatable);  // hide metatable from Lua getmetatable()

          lua_pushliteral(L, "__index");
          lua_pushvalue(L, methodtable);
          lua_settable(L, metatable);

//          lua_pushliteral(L, "__gc");
//          lua_pushcfunction(L, gc_account);
//          lua_settable(L, metatable);

          lua_pop(L, 1);  // drop metatable

          luaL_newlib(L, methods);  // fill methodtable
          lua_pop(L, 1);  // drop methodtable

//          lua_register(L, className, create_account);
        }
};

const char InventoryMethods::className[] = "inventory";

const luaL_Reg InventoryMethods::methods[] = {
    { "deleteItem", deleteItem },
    { "equipItem", equipItem },
    { "itemCount", itemCount },
    { "itemNameId", itemNameId },
    { "itemTypeId", itemTypeId },
    { "itemWeight", itemWeight },
    { "pods", pods },
    { "podsMax", podsMax },
    { "podsP", podsP },
    { "podsMax", useItem },
    { "podsP", inventoryContent },
    { NULL, NULL }
};

#endif // INVENTORYMETHODS_H
