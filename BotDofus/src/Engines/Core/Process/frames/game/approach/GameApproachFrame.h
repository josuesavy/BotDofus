#ifndef APPROACHFRAME_H
#define APPROACHFRAME_H

#include <QtSql/QtSql>

#include "src/Engines/Core/Process/frames/AbstractFrame.h"

class GameApproachFrame : public AbstractFrame
{
public:
    GameApproachFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // APPROACHFRAME_H
