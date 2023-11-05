#ifndef MAPFORM_H
#define MAPFORM_H

#include <QWidget>
#include <QQmlContext>

#include <QToolTip>
#include <QCursor>

#include "src/core/process/ProcessEngine.h"
#include "src/core/DataHandler.h"
#include "src/utils/PropertyHelper.h"

namespace Ui {
class MapForm;
}

class MapForm : public QWidget
{
    Q_OBJECT

    Q_ENUMS(MapViewerCellEnum)

    AUTO_PROPERTY(QList<int>, entityTypes)
    AUTO_PROPERTY(QList<int>, interactiveTypes)
    AUTO_PROPERTY(QList<int>, collisionTypes)
    AUTO_PROPERTY(bool, displayCellIds)
    AUTO_PROPERTY(bool, cellClicked)
    AUTO_PROPERTY(int, cellChangeColor)

public:
    explicit MapForm(ProcessEngine *engine, const ConnectionInfos &infos, SocketIO *sender, QWidget *parent = nullptr);
    MapForm()=default;
    ~MapForm();

    SocketIO *getSocket();
    ConnectionInfos getConnectionInfos() const;

    Q_INVOKABLE void changeCell(uint cell);
    Q_INVOKABLE void changeToNearestCell(uint cell);
    Q_INVOKABLE void useInteractive(int cell);
    Q_INVOKABLE void useDoorInteractive(int cell);
    Q_INVOKABLE void showInfos(int cell);

    enum MapViewerCellEnum
    {
        NOTHING,
        PLAYER,
        BOT,
        PLAYER_BOT,
        NPC,
        USABLE,
        MONSTER,
        INTERACTIVE,
        DOOR,
        COLLISION_NO_SIGHT,
        COLLISION_WITH_SIGHT,
        DEFENDER,
        CHALLENGER,
        MERCHANT,
        PATH
    };

public slots:
    void updateInterface();
    void updateMap();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_checkBoxDisplayCellIds_stateChanged(int arg1);

    void on_pushButtonTop_clicked();

    void on_pushButtonLeft_clicked();

    void on_pushButtonRight_clicked();

    void on_pushButtonBottom_clicked();

private:
    Ui::MapForm *ui;

    SocketIO *m_sender;
    ProcessEngine *m_engine;
    ConnectionInfos m_infos;

    const BotData &getData() const;

    int m_mapId;
    QList<uint> m_interactivesOnMap;
    QList<uint> m_playersOnMap;
    QList<uint> m_npcsOnMap;
    QList<uint> m_merchantsOnMap;
    QList<uint> m_monstersOnMap;
    QList<uint> m_defenderOnMap;
    QList<uint> m_challengerOnMap;

    QList<InteractiveDisplayInfos> interactiveDisplayInfosList;
    QList<MonsterGroup> monsterGroupList;
    QList<EntityInfos> entityInfosList;
    QList<MerchantInfos> merchantInfosList;
    QList<NpcInfos> npcInfosList;
    QList<NpcQuestInfos> npcQuestInfosList;
};

#endif // MAPFORM_H
