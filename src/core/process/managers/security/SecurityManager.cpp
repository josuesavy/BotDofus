#include "SecurityManager.h"

SecurityManager::SecurityManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::UNKNOWN, connectionsData)
{

}

void SecurityManager::reset(SocketIO *sender)
{

}

QByteArray SecurityManager::fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm)
{
    QFile f(fileName);
    if (f.open(QFile::ReadOnly))
    {
        QCryptographicHash hash(hashAlgorithm);
        if (hash.addData(&f))
            return hash.result();
    }
    return QByteArray();
}
