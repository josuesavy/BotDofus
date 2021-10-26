#ifndef CHARACTER_H
#define CHARACTER_H

#include "src/engines/core/CoreEngine.h"

class Character: public CoreEngine
{
public:
    int breed(SocketIO *sender)
    {
        return m_botData[sender].playerData.breed;
    }

    QString name(SocketIO *sender)
    {
        return m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].name;
    }

    bool sex(SocketIO *sender)
    {
        return m_botData[sender].playerData.sex;
    }

    int level(SocketIO *sender)
    {
        return m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].level;
    }

    int lifePoints(SocketIO *sender)
    {
        return m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base;
    }

    int maxLifePoints(SocketIO *sender)
    {
        return m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].base;
    }

    int lifePointsP(SocketIO *sender)
    {
        return (m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base + m_botData[sender].playerData.stats[(uint)StatIds::VITALITY].base - m_botData[sender].playerData.stats[(uint)StatIds::CUR_PERMANENT_DAMAGE].base)+ m_botData[sender].playerData.stats[(uint)StatIds::CUR_LIFE].base + m_botData[sender].playerData.stats[(uint)StatIds::CUR_PERMANENT_DAMAGE].base;
    }

    int energyPoints(SocketIO *sender)
    {
        return m_botData[sender].playerData.stats[(uint)StatIds::ENERGY_POINTS].total;
    }

    int maxEnergyPoints(SocketIO *sender)
    {
        return m_botData[sender].playerData.stats[(uint)StatIds::MAX_ENERGY_POINTS].total;
    }

    int experience(SocketIO *sender)
    {
        return m_botData[sender].playerData.experience-m_botData[sender].playerData.experienceLevelFloor;
    }

    bool freeMode(SocketIO *sender)
    {
        return m_botData[sender].playerData.subscriptionEndDate > 0?true:false;
    }

    int kamas(SocketIO *sender)
    {
        return m_botData[sender].playerData.kamas;
    }
};

#endif // CHARACTER_H
