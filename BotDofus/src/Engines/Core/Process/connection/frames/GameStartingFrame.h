#ifndef GAMESTARTINGFRAME_H
#define GAMESTARTINGFRAME_H

#include "src/Engines/Core/Process/abstract/AbstractFrame.h"
#include "src/Engines/IO/D2O/Misc/ParamsDecoder.h"

class GameStartingFrame : public AbstractFrame
{
    Q_OBJECT

public:
    GameStartingFrame(QMap<SocketIO*, BotData> *connectionsData);

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

#endif // GAMESTARTINGFRAME_H
