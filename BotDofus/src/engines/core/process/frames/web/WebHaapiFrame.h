#ifndef WEBHAAPIFRAME_H
#define WEBHAAPIFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"

class WebHaapiFrame : public AbstractFrame
{
public:
    WebHaapiFrame(QMap<SocketIO *, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // WEBHAAPIFRAME_H
