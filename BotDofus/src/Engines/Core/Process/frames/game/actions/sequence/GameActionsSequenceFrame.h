#ifndef SEQUENCEFRAME_H
#define SEQUENCEFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/fight/FightManager.h"

class GameActionsSequenceFrame : public AbstractFrame
{
public:
    GameActionsSequenceFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);


    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    FightManager *m_fightManager;
};

#endif // SEQUENCEFRAME_H
