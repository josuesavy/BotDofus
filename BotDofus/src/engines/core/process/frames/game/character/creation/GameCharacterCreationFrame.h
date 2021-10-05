#ifndef GAMECHARACTERCREATIONFRAME_H
#define GAMECHARACTERCREATIONFRAME_H

#include <QtSql/QtSql>

#include "src/engines/core/process/frames/AbstractFrame.h"

class GameCharacterCreationFrame : public AbstractFrame
{
public:
    GameCharacterCreationFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMECHARACTERCREATIONFRAME_H
