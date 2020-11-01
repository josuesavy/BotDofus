#ifndef PROCESSENGINE_H
#define PROCESSENGINE_H

#include <QObject>
#include <QCryptographicHash>
#include <unistd.h>

#include "src/Engines/Core/CoreEngine.h"
#include "src/Engines/IO/D2O/D2OManager.h"
#include "src/Engines/Pathfinding/Map/Pathfinding.h"
#include "src/Engines/IO/D2O/Misc/ParamsDecoder.h"

class ProcessEngine : public CoreEngine
{
    Q_OBJECT

public:
    ProcessEngine();

    bool processMessage(const MessageInfos &data, SocketIO *sender);

private slots:
    void resetModules(SocketIO *sender);
    void processUpdateRequest(SocketIO *sender);
    void connectToSocket(SocketIO* sender);

    void processData(QList<MessageInfos> messages);

private:
    int basicNoOperationMsgCounter;

    QByteArray fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm);
};

#endif // PROCESSENGINE_H
