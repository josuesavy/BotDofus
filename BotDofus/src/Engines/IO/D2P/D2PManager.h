#pragma once

#include <QMutex>
#include <QTime>

#include <QPixmap>

#include "GeneralInformation/D2pFolder.h"
#include "Map/Map.h"
#include "GeneralInformation/CompressedMap.h"
#include "GeneralInformation/D2pFile.h"
#include "src/Engines/IO/Singleton.h"


class D2PManager
{
    friend class Singleton<D2PManager>;

public:
    D2PManager(const QString &D2PFolder);
    ~D2PManager();

    void init(const QString &D2PFolder);
    bool isInit() const;

    const QPixmap getImage(QString id);

    Map getMap(uint mapId);
    QMap<uint, Map> parseAllMap();

    const QString getPathFolder();
    const QString getDofusPath();

private:
    D2PManager();
    CompressedMap* getCompressedMap(uint mapId);

    bool m_isInit;
    D2PFolder *m_folder;
    D2PFolder *m_folder_2;

    QString m_pathFolder;

    QMutex m_mutex;
};

class D2PManagerSingleton : public Singleton<D2PManager>
{
};
