#ifndef REGISTERFRAME_H
#define REGISTERFRAME_H

#include <QInputDialog>

#include "src/core/process/frames/AbstractFrame.h"

class ConnectionRegisterFrame : public AbstractFrame
{
public:
    ConnectionRegisterFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // REGISTERFRAME_H
