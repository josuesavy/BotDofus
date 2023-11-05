#ifndef SECURITYMANAGER_H
#define SECURITYMANAGER_H

#include <QByteArray>
#include <QCryptographicHash>
#include <QFile>

#include "src/core/process/managers/AbstractManager.h"

class SecurityManager : public AbstractManager
{
public:
    SecurityManager(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

    static QByteArray fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm);
};

#endif // SECURITYMANAGER_H
