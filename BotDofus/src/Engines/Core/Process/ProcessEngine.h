#ifndef PROCESSENGINE_H
#define PROCESSENGINE_H

#include "src/Engines/Core/CoreEngine.h"
#include "src/Engines/Core/Process/Managers/connection/ConnectionManager.h"

class ProcessEngine : public CoreEngine
{
    Q_OBJECT

public:
    ProcessEngine();

    bool processMessage(const MessageInfos &data, SocketIO *sender);

private slots:
    void resetManagers(SocketIO *sender);
    void processUpdateRequest(SocketIO *sender);
    void connectToSocket(SocketIO* sender);

    void processData(QList<MessageInfos> messages);
};

#endif // PROCESSENGINE_H
