#ifndef THREADINITGAMEDATA_H
#define THREADINITGAMEDATA_H

#include "src/gamedata/d2o/D2OManager.h"
#include "src/gamedata/d2p/D2PManager.h"
#include "src/utils/pathfinding/world/PathfindingMap.h"
#include "src/gamedata/i18n/I18nFileAccessor.h"

#include <QObject>
#include <QThread>
#include <QSemaphore>

class ThreadInitGameData : public QThread {
    Q_OBJECT
public:
    ThreadInitGameData(QSemaphore* semaphore, QString d2o, QString i18n, QString d2p, QWidget *parent = nullptr): QThread(parent)
    {
        m_semaphore=semaphore;
        m_d2o=d2o;
        m_i18n=i18n;
        m_d2p=d2p;
    }
    ~ThreadInitGameData(){}

signals:
    void updateInterface(int value, QString message);

protected:
    void run() override {
        // ServerHandlerSingleton::get()->init();
        emit updateInterface(20, tr("Initializing game data... (2/4)"));
        D2OManagerSingleton::get()->init(m_d2o, m_i18n);
        emit updateInterface(20, tr("Initializing game data... (3/4)"));
        D2PManagerSingleton::get()->init(m_d2p);
        emit updateInterface(20, tr("Initializing game data... (4/4)"));
        PathfindingMap::initialize();
        m_semaphore->release();
    }

private:
    QSemaphore *m_semaphore;
    QString m_d2o, m_i18n, m_d2p;
};

#endif // THREADINITGAMEDATA_H
