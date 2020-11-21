#ifndef SECURITYMANAGER_H
#define SECURITYMANAGER_H

#include <QByteArray>
#include <QCryptographicHash>
#include <QFile>

class SecurityManager
{
public:
    SecurityManager();

    static QByteArray fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm);
};

#endif // SECURITYMANAGER_H
