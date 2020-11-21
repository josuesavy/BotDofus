#include "SecurityManager.h"

SecurityManager::SecurityManager()
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
