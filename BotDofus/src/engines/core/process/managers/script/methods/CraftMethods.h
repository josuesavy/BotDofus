#ifndef CRAFTMETHODS_H
#define CRAFTMETHODS_H

extern "C"
{
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
}

#include "src/engines/DataHandler.h"
#include "src/engines/core/process/managers/craft/CraftManager.h"

class CraftMethods : public DataHandler
{
public:
    static int putItem(lua_State *L, SocketIO *sender, CraftManager *craftManager)
    {
        // get parameters
        int id = lua_tointeger(L, 1);
        int quantity = lua_tointeger(L, 2);

        // process
        QSharedPointer<ItemData> item = D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, id);
        craftManager->addItemToCraftList(sender, item.getName());
        craftManager->updateQuantity(sender, id, quantity);

        // return the result

        return 1;
    }

    static int changeQuantityToCraft(lua_State *L, SocketIO *sender, CraftManager *craftManager)
    {
        // get parameters
        int id = lua_tointeger(L, 1);

        // process
        craftManager->updateQuantity(sender, id, quantity);

        // return the result

        return 1;
    }

    static int ready(lua_State *L, SocketIO *sender, CraftManager *craftManager)
    {
        // get parameters

        // process
        craftManager->processCraft(sender);

        // return the result

        return 1;
    }

    static int leaveDialog(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process

        // return the result

        return 1;
    }
};

#endif // CRAFTMETHODS_H
