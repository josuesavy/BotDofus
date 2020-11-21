#ifndef GAMECHARACTERCHOICEFRAME_H
#define GAMECHARACTERCHOICEFRAME_H

#include <QInputDialog>

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/connection/managers/ConnectionManager.h"

class GameCharacterChoiceFrame : public AbstractFrame
{
public:
    GameCharacterChoiceFrame(QMap<SocketIO*, BotData> *connectionsData);

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

#endif // GAMECHARACTERCHOICEFRAME_H
