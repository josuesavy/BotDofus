#ifndef CoreEngine_H
#define CoreEngine_H

#include "src/Engines/IO/Network/Reader.h"
#include "src/Engines/Core/Process/connection/frames/HandshakeFrame.h"
#include "src/Engines/Core/Process/flood/FloodModule.h"
#include "src/Engines/Core/Process/fight/FightModule.h"
#include "src/Engines/Core/Process/farm/FarmModule.h"
#include "src/Engines/Core/Process/map/MapModule.h"
#include "src/Engines/Core/Process/connection/ConnectionModule.h"
#include "src/Engines/Core/Process/characters/StatsModule.h"
#include "src/Engines/Core/Process/exchange/ExchangeModule.h"
#include "src/Engines/Core/Process/group/GroupModule.h"
#include "src/Engines/Core/Process/craft/CraftModule.h"
#include "src/Engines/Core/Process/script/ScriptModule.h"
#include "src/Engines/Core/Process/interaction/InteractionModule.h"
#include "src/Engines/Core/Process/arena/ArenaModule.h"
#include "src/Engines/Core/Process/shop/ShopModule.h"

class CoreEngine : public QObject, public DataHandler
{

    Q_OBJECT

public:
    CoreEngine();
    ~CoreEngine();

    MapModule &getMapModule();
    FarmModule &getFarmModule();
    CraftModule &getCraftModule();
    FightModule &getFightModule();
    FloodModule &getFloodModule();
    GroupModule &getGroupModule();
    StatsModule &getStatsModule();
    ScriptModule &getScriptModule();
    ExchangeModule &getExchangeModule();
    ConnectionModule &getConnectionModule();
    InteractionModule &getInteractionModule();
    ArenaModule &getArenaModule();
    ShopModule &getShopModule();

    const BotData &getData(SocketIO *sender);

signals:
    void informationsUpdated(SocketIO *sender);

protected:
    QMap<ModuleType, AbstractFrame*> m_modules;
    QList<AbstractFrame*> m_moduless;

private:
    QMap<SocketIO*, ConnectionInfos> m_connectionsInfos;
};

#endif // CoreEngine_H
