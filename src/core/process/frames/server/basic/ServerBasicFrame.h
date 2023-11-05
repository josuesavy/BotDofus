#ifndef SERVERBASICFRAME_H
#define SERVERBASICFRAME_H

#include "src/core/process/frames/AbstractFrame.h"
#include "src/utils/ParamsDecoder.h"

class ServerBasicFrame : public AbstractFrame
{
public:
    ServerBasicFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // SERVERBASICFRAME_H
