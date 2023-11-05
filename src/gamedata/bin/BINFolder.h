#pragma once

#include "BINFile.h"

#include <QDir>
#include <QDirIterator>

class BINFolder
{
public:
    BINFolder(const QString &folderName);
    ~BINFolder();

    const QString &getFolderName() const;
    const uint &getBINFileCount() const;
    const QList<BINFile*> &getFolderContent() const;

private:
    QString m_folderName;
    QList<BINFile*> m_folderContent;
    uint m_BINFileCount;
};
