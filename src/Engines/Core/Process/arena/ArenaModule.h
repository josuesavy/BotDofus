#ifndef ARENAMODULE_H
#define ARENAMODULE_H

/*!
 * \class The ArenaModule class for all Kolizeum's features
 * \brief ..
 * \author Garten
 * \version Alpha
 */

#include "src/Engines/Core/Process/abstract/AbstractModule.h"

class ArenaModule : public AbstractModule
{
    Q_OBJECT
public:
    ArenaModule(QMap<SocketIO*, BotData> *connectionsData);
    ~ArenaModule();

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

    /*!
     * \brief Process message of the Kolizeum
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

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

#endif // ARENAMODULE_H
