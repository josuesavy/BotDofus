#pragma once

#include <QString>

#include "BINFile.h"
#include "BINFolder.h"
#include "world/WorldGraph.h"
#include "src/utils/Singleton.h"

class BINManager
{
    friend class Singleton<BINManager>;

public:
    BINManager(const QString &BINFolder);
    ~BINManager();

    void init(const QString &BINFolder);
    bool isInit() const;

    WorldGraph getWorldGraph();

    const QString getPathFolder();

private:
    BINManager();

    bool m_isInit;
    BINFolder *m_folder;

    QString m_pathFolder;

    QMutex m_mutex;
};

class BINManagerSingleton : public Singleton<BINManager>
{
};
