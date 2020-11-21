#ifndef SECURITYMESSAGE_H
#define SECURITYMESSAGE_H

#include <QtSql/QtSql>

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/security/managers/SecurityManager.h"

class SecurityFrame : public AbstractFrame
{
public:
    SecurityFrame(QMap<SocketIO*, BotData> *connectionsData);

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

#endif // SECURITYMESSAGE_H
