#include "BINFile.h"

BINFile::BINFile(const QString &path):
    m_path(path)
{
    if (!path.contains(".bin"))
        qDebug()<<"ERROR - BINFile - Incorrect extension"<<path;

    getFileContent();
}

BINFile::~BINFile()
{
    delete m_worldGraph;
}

const QString &BINFile::getPath() const
{
    return m_path;
}

const WorldGraph *BINFile::getWorldGraph() const
{
    return m_worldGraph;
}

void BINFile::getFileContent()
{
    m_worldGraph = new WorldGraph(m_path);
}
