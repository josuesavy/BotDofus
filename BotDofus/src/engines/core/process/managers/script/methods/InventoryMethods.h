#ifndef INVENTORYMETHODS_H
#define INVENTORYMETHODS_H

extern "C"
{
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
}

#include "src/engines/DataHandler.h"
#include "src/engines/core/process/managers/stats/StatsManager.h"

class InventoryMethods : public DataHandler
{
public:
    static int deleteItem(lua_State *L, SocketIO *sender, StatsManager *statsManager)
    {
        // Get parameters
        int gid = lua_tointeger(L, 1);
        int quantity = lua_tointeger(L, 2);

        // Process
        int uid = INVALID;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID)
            {
                uid = m_botData[sender].playerData.inventoryContent.at(i).UID;
                break;
            }
        }
        statsManager->destroyItem(sender, uid, quantity);

        // Return the result
        bool isDestroyed = true;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID && quantity == m_botData[sender].playerData.inventoryContent.at(i).quantity)
            {
                isDestroyed = false;
                break;
            }
        }
        lua_pushboolean(L, isDestroyed);

        return 1;
    }

    static int equipItem(lua_State *L, SocketIO *sender, StatsManager *statsManager)
    {
        // get parameters
        int gid = lua_tointeger(L, 1);

        // process
        int uid = INVALID;
        bool isEquipped = false;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID)
            {
                gid = m_botData[sender].playerData.inventoryContent.at(i).UID;
                isEquipped = m_botData[sender].playerData.inventoryContent.at(i).isEquipped;
                break;
            }
        }

        if(isEquipped)
        {
            qDebug()<<"ACCOUNTFORM - UNEQUIP ITEM"<<uid;
            statsManager->unequipItem(sender, uid);
        }
        else
        {
            qDebug()<<"ACCOUNTFORM - EQUIP ITEM"<<uid;
            statsManager->equipItem(sender, uid);
        }

        // return the result
        bool isEquiped = false;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID && m_botData[sender].playerData.inventoryContent.at(i).isEquipped)
            {
                isEquiped = true;
                break;
            }
        }
        lua_pushboolean(L, isEquiped);

        return 1;
    }

    static int itemCount(lua_State *L, SocketIO *sender)
    {
        // get parameters
        int gid = lua_tointeger(L, 1);

        // process
        int count = 0;
        int uid = INVALID;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID)
            {
                uid = m_botData[sender].playerData.inventoryContent.at(i).UID;
                count = m_botData[sender].playerData.inventoryContent.at(i).quantity;
                break;
            }
        }

        // return the result
        lua_pushinteger(L, count);

        return 1;
    }

    static int itemNameId(lua_State *L, SocketIO *sender)
    {
        // get parameters
        int gid = lua_tointeger(L, 1);

        // process
        QString name = "Unknown";
        int uid = INVALID;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID)
            {
                uid = m_botData[sender].playerData.inventoryContent.at(i).UID;
                name = D2OManagerSingleton::get()->getItem(m_botData[sender].playerData.inventoryContent.at(i).GID)->getName();
                break;
            }
        }

        // return the result
        lua_pushstring(L, name.toStdString().c_str());

        return 1;
    }

    static int itemTypeId(lua_State *L, SocketIO *sender)
    {
        // get parameters
        int gid = lua_tointeger(L, 1);

        // process
        int typeId = INVALID;
        int uid = INVALID;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID)
            {
                uid = m_botData[sender].playerData.inventoryContent.at(i).UID;
                typeId = D2OManagerSingleton::get()->getItem(m_botData[sender].playerData.inventoryContent.at(i).GID)->getTypeId();
                break;
            }
        }

        // return the result
        lua_pushinteger(L, typeId);

        return 1;
    }

    static int itemWeight(lua_State *L, SocketIO *sender)
    {
        // get parameters
        int gid = lua_tointeger(L, 1);

        // process
        int weight = INVALID;
        int uid = INVALID;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID)
            {
                uid = m_botData[sender].playerData.inventoryContent.at(i).UID;
                weight = D2OManagerSingleton::get()->getItem(m_botData[sender].playerData.inventoryContent.at(i).GID)->getRealWeight();
                break;
            }
        }

        // return the result
        lua_pushinteger(L, weight);

        return 1;
    }

    static int pods(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process
        int pods = m_botData[sender].playerData.pods.current;

        // return the result
        lua_pushinteger(L, pods);

        return 1;
    }

    static int podsMax(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process
        int podsMax = m_botData[sender].playerData.pods.max;

        // return the result
        lua_pushinteger(L, podsMax);

        return 1;
    }

    static int podsP(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process
        int pods = m_botData[sender].playerData.pods.current;
        int podsMax = m_botData[sender].playerData.pods.max;
        int podsPercent = (pods * 100 / podsMax); // ((input - min) * 100) / (max - min)

        // return the result
        lua_pushinteger(L, podsPercent);

        return 1;
    }

    static int useItem(lua_State *L, SocketIO *sender, StatsManager *statsManager)
    {
        // get parameters
        int gid = lua_tointeger(L, 1);

        // process
        int quantity = 0;
        int uid = INVALID;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID)
            {
                uid = m_botData[sender].playerData.inventoryContent.at(i).UID;
                quantity = m_botData[sender].playerData.inventoryContent.at(i).quantity;
                break;
            }
        }
        statsManager->useItem(sender, uid);

        // return the result
        bool isUsed = true;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID && quantity == m_botData[sender].playerData.inventoryContent.at(i).quantity)
            {
                isUsed = false;
                break;
            }
        }
        lua_pushboolean(L, isUsed);

        return 1;
    }

    static int inventoryContent(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process

        // return the result

        return 1;
    }
};

#endif // INVENTORYMETHODS_H
