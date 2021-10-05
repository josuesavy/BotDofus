#ifndef PROCESSENGINE_H
#define PROCESSENGINE_H

#include "src/engines/core/CoreEngine.h"
#include "src/engines/core/process/managers/connection/ConnectionManager.h"

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
