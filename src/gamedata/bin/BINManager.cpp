#include "BINManager.h"

BINManager::BINManager():
    m_folder(NULL),
    m_isInit(false)
{

}

BINManager::BINManager(const QString &BINFolder)
{
    init(BINFolder);
}

BINManager::~BINManager()
{
    delete m_folder;
}

void BINManager::init(const QString &BINFolder)
{
    QTime t;
    t.start();

    m_isInit = true;
    m_folder = new class BINFolder(BINFolder + "/maps");
    m_pathFolder = BINFolder;

    qDebug()<<"[BINManager] Initialized ! ("<<t.elapsed()<<"ms)";
}

bool BINManager::isInit() const
{
    return m_isInit;
}

WorldGraph BINManager::getWorldGraph()
{
    m_mutex.lock();

    if (!m_isInit)
        qDebug()<<"ERROR - BINManager is not initialized!";

    WorldGraph worldGraph;
    for (QList<BINFile*>::const_iterator BINFile = m_folder->getFolderContent().begin(); BINFile != m_folder->getFolderContent().end(); ++BINFile)
    {
        if ((*BINFile)->getPath().contains("WorldGraph"))
        {
            worldGraph = *(*BINFile)->getWorldGraph();
        }
    }

    m_mutex.unlock();

    return worldGraph;
}
