#include "BINFolder.h"

BINFolder::BINFolder(const QString &folderName)
{
    if (!QDir(m_folderName).exists())
        qDebug()<<"ERROR - BINFolder - The folder"<<m_folderName<<"doesn't exist";

    QDirIterator dirIt(m_folderName, QDirIterator::Subdirectories);
    while (dirIt.hasNext())
    {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
        {
            if (QFileInfo(dirIt.filePath()).suffix() == "bin")
            {
                m_folderContent.push_back(new BINFile(dirIt.filePath()));
                m_BINFileCount++;
            }
        }
    }

    if (m_BINFileCount == 0)
        qDebug()<<"ERROR - BINFile - Wrong folder, no BIN file was found"<<m_folderName;
}

BINFolder::~BINFolder()
{
    foreach(BINFile *file, m_folderContent)
        delete file;
}

const QString &BINFolder::getFolderName() const
{
    return m_folderName;
}

const uint &BINFolder::getBINFileCount() const
{
    return m_BINFileCount;
}

const QList<BINFile *> &BINFolder::getFolderContent() const
{
    return m_folderContent;
}
