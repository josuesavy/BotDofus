#ifndef SECURITYMANAGER_H
#define SECURITYMANAGER_H

#include <QByteArray>
#include <QCryptographicHash>
#include <QFile>

#include "src/Engines/Core/Process/Managers/AbstractManager.h"

class SecurityManager : public AbstractManager
{
public:
    SecurityManager(QMap<SocketIO*, BotData> *connectionsData);

    static QByteArray fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm);
};

#endif // SECURITYMANAGER_H
