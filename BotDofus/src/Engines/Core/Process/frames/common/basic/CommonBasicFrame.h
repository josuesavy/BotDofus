#ifndef COMMONBASICFRAME_H
#define COMMONBASICFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"

class CommonBasicFrame : public AbstractFrame
{
public:
    CommonBasicFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // COMMONBASICFRAME_H
