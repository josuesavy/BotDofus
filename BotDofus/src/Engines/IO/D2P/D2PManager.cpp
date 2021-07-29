#include "D2PManager.h"

D2PManager::D2PManager():
    m_folder(NULL),
    m_folder_2(NULL),
    m_isInit(false)
{
}

D2PManager::D2PManager(const QString &D2PFolder)
{
    init(D2PFolder);
}

D2PManager::~D2PManager()
{
    delete m_folder;
}

void D2PManager::init(const QString &D2PFolder)
{
    QTime t;
    t.start();

    m_isInit = true;
    m_folder = new class D2PFolder(D2PFolder + "/maps");
    m_folder_2 = new class D2PFolder(D2PFolder+"/gfx/items");
    m_pathFolder = D2PFolder;

    qDebug()<<"[D2PManager] Initialized ! ("<<t.elapsed()<<"ms)";
}

bool D2PManager::isInit() const
{
    return m_isInit;
}

const QPixmap D2PManager::getImage(QString id)
{
    m_mutex.lock();

    QByteArray data;

    foreach(D2PFile *file, m_folder_2->getFolderContent())
    {
        if(file->getContentImage().contains(id))
        {
            data = file->getContentImage().value(id)->getData();
        }
    }

    QPixmap img ;
    img.loadFromData(data);

    m_mutex.unlock();

    return img;
}

Map D2PManager::getMap(uint mapId)
{
    m_mutex.lock();

    if(!m_isInit)
        qDebug()<<"ERROR - D2PManager is not initialized!";

    Map map = getCompressedMap(mapId);

    m_mutex.unlock();

    return map;
}

QMap<uint, Map> D2PManager::parseAllMap()
{
    if(!m_isInit)
        qDebug()<<"ERROR - D2PManager is not initialized!";

    QMap<uint, Map> allMap;

    foreach (D2PFile *D2Pfile, m_folder->getFolderContent())
    {
        foreach (CompressedMap *compressedMap, D2Pfile->getContentMap())
        {
            allMap[compressedMap->getMapId()] = Map(compressedMap);
        }
    }

    return allMap;
}

const QString D2PManager::getPathFolder()
{
    return m_pathFolder;
}

const QString D2PManager::getDofusPath()
{
    QString pathDofus = m_pathFolder;
    return pathDofus.remove("/content");
}

CompressedMap* D2PManager::getCompressedMap(uint mapId)
{
    if(!m_isInit)
        qDebug()<<"ERROR - D2PManager is not initialized!";

    for (QList<D2PFile*>::const_iterator D2PFile = m_folder->getFolderContent().begin(); D2PFile != m_folder->getFolderContent().end(); ++D2PFile)
    {
        if ((*D2PFile)->getContentMap().contains(mapId))
        {
            return (*D2PFile)->getContentMap()[mapId];
        }
    }

    qDebug()<<"ERROR - D2PManager The map id"<<mapId<<"doesn't exist!";

    return NULL;
}
