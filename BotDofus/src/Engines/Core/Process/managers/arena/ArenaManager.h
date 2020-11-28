#ifndef ARENAMANAGER_H
#define ARENAMANAGER_H

#include "src/Engines/Core/Process/Managers/AbstractManager.h"

class ArenaManager : public AbstractManager
{
public:
    ArenaManager(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

    /*!
     * \brief processArena
     * \param sender
     * \return bool
     */
    bool processArena(SocketIO *sender, PvpArenaTypeEnum fightTypeId);

    /*!
     * \brief Register to Kolizeum
     * \param sender Bot's particular connection
     * \param fightType Fight's type in which we register (duel, solo, team)
     */
    void arenaRegister(SocketIO *sender, PvpArenaTypeEnum fightTypeId);

    /*!
     * \brief Unsubscribe to Kolizeum
     * \param sender Bot's particular connection
     */
    void arenaUnregister(SocketIO *sender);

    /*!
     * \brief Send answer to accept invitation
     * \param sender Bot's particular connection
     * \param fightTypeId Fight's type in which we register (duel, solo, team)
     * \param accept Accept or not
     */
    void arenaFightAnswer(SocketIO *sender, PvpArenaTypeEnum fightTypeId, bool accept);
};

#endif // ARENAMANAGER_H
