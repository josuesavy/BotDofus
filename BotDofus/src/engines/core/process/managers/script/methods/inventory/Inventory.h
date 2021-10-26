#ifndef INVENTORY_H
#define INVENTORY_H

#include "src/engines/core/CoreEngine.h"

class Inventory: public CoreEngine
{
public:
    void deleteItem(SocketIO *sender, int gid, int quantity)
    {
        int uid = INVALID;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID)
            {
                uid = m_botData[sender].playerData.inventoryContent.at(i).UID;
                break;
            }
        }
        getStatsManager().destroyItem(sender, uid, quantity);
    }

    void equipItem(SocketIO *sender, int gid)
    {
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
            getStatsManager().unequipItem(sender, uid);

        else
            getStatsManager().equipItem(sender, uid);
    }

    int itemCount(SocketIO *sender, int gid)
    {
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

        return count;
    }

    QString itemNameId(SocketIO *sender, int gid)
    {
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

        return name;
    }

    int itemTypeId(SocketIO *sender, int gid)
    {
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

        return typeId;
    }

    int itemWeight(SocketIO *sender, int gid)
    {
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

        return weight;
    }

    int pods(SocketIO *sender)
    {
        return m_botData[sender].playerData.pods.current;
    }

    int podsMax(SocketIO *sender)
    {
        return m_botData[sender].playerData.pods.max;
    }

    int podsP(SocketIO *sender)
    {
        int pods = m_botData[sender].playerData.pods.current;
        int podsMax = m_botData[sender].playerData.pods.max;

        return (pods * 100 / podsMax); // ((input - min) * 100) / (max - min)
    }

    void useItem(SocketIO *sender, int gid)
    {
        int uid = INVALID;
        for(int i=0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if(gid == m_botData[sender].playerData.inventoryContent.at(i).GID)
            {
                uid = m_botData[sender].playerData.inventoryContent.at(i).UID;
                break;
            }
        }
        getStatsManager().useItem(sender, uid);
    }

    QList<QMap<QString,int>> inventoryContent(SocketIO *sender)
    {
        return QList<QMap<QString,int>>();
    }
};

#endif // INVENTORY_H
