#ifndef FIGHTFRAME_H
#define FIGHTFRAME_H

#include "src/Engines/Core/Process/abstract/AbstractFrame.h"

class FightFrame : public AbstractFrame
{
public:
    FightFrame(QMap<SocketIO*, BotData> *connectionsData);

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
};

#endif // FIGHTFRAME_H
