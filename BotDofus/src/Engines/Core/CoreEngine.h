#ifndef CoreEngine_H
#define CoreEngine_H

#include "src/Engines/Core/Process/frames/common/basic/CommonBasicFrame.h"
#include "src/Engines/Core/Process/frames/connection/ConnectionFrame.h"
#include "src/Engines/Core/Process/frames/connection/register/ConnectionRegisterFrame.h"
#include "src/Engines/Core/Process/frames/game/achievement/AchievementFrame.h"
#include "src/Engines/Core/Process/frames/game/actions/GameActionsFrame.h"
#include "src/Engines/Core/Process/frames/game/actions/fight/GameActionsFightFrame.h"
#include "src/Engines/Core/Process/frames/game/actions/sequence/GameActionsSequenceFrame.h"
#include "src/Engines/Core/Process/frames/game/alliance/GameAllianceFrame.h"
#include "src/Engines/Core/Process/frames/game/almanach/GameAlmanachFrame.h"
#include "src/Engines/Core/Process/frames/game/approach/GameApproachFrame.h"
#include "src/Engines/Core/Process/frames/game/atlas/compass/GameAtlasCompassFrame.h"
#include "src/Engines/Core/Process/frames/game/basic/GameBasicFrame.h"
#include "src/Engines/Core/Process/frames/game/character/choice/GameCharacterChoiceFrame.h"
#include "src/Engines/Core/Process/frames/game/character/creation/GameCharacterCreationFrame.h"
#include "src/Engines/Core/Process/frames/game/character/deletion/GameCharacterDeletionFrame.h"
#include "src/Engines/Core/Process/frames/game/character/stats/GameCharacterStatsFrame.h"
#include "src/Engines/Core/Process/frames/game/character/status/GameCharacterStatusFrame.h"
#include "src/Engines/Core/Process/frames/game/chat/GameChatFrame.h"
#include "src/Engines/Core/Process/frames/game/context/GameContextFrame.h"
#include "src/Engines/Core/Process/frames/game/context/fight/GameContextFightFrame.h"
#include "src/Engines/Core/Process/frames/game/context/fight/character/GameContextFightCharacterFrame.h"
#include "src/Engines/Core/Process/frames/game/context/mount/GameContextMountFrame.h"
#include "src/Engines/Core/Process/frames/game/context/notification/GameContextNotificationFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/GameContextRoleplayFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/death/GameContextRoleplayDeathFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/fight/GameContextRoleplayFightFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/fight/arena/GameContextRoleplayFightArenaFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/job/GameContextRoleplayJobFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/npc/GameContextRoleplayNpcFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/objects/GameContextRoleplayObjectsFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/party/GameContextRoleplayPartyFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/quest/GameContextRoleplayQuestFrame.h"
#include "src/Engines/Core/Process/frames/game/context/roleplay/stats/GameContextRoleplayStatsFrame.h"
#include "src/Engines/Core/Process/frames/game/dialog/GameDialogFrame.h"
#include "src/Engines/Core/Process/frames/game/friend/GameFriendFrame.h"
#include "src/Engines/Core/Process/frames/game/guild/GameGuildFrame.h"
#include "src/Engines/Core/Process/frames/game/initialization/GameInitializationFrame.h"
#include "src/Engines/Core/Process/frames/game/interactive/GameInteractiveFrame.h"
#include "src/Engines/Core/Process/frames/game/interactive/zaap/GameInteractiveZaapFrame.h"
#include "src/Engines/Core/Process/frames/game/inventory/GameInventoryFrame.h"
#include "src/Engines/Core/Process/frames/game/inventory/exchanges/GameInventoryExchangesFrame.h"
#include "src/Engines/Core/Process/frames/game/inventory/items/GameInventoryItemsFrame.h"
#include "src/Engines/Core/Process/frames/game/inventory/spells/GameInventorySpellsFrame.h"
#include "src/Engines/Core/Process/frames/game/inventory/storage/GameInventoryStorageFrame.h"
#include "src/Engines/Core/Process/frames/game/moderation/GameModerationFrame.h"
#include "src/Engines/Core/Process/frames/game/subscriber/GameSubscriberFrame.h"
#include "src/Engines/Core/Process/frames/handshake/HandshakeFrame.h"
#include "src/Engines/Core/Process/frames/queues/QueueFrame.h"
#include "src/Engines/Core/Process/frames/secure/SecureFrame.h"
#include "src/Engines/Core/Process/frames/security/SecurityFrame.h"
#include "src/Engines/Core/Process/frames/server/basic/ServerBasicFrame.h"
#include "src/Engines/Core/Process/frames/subscription/SubscriptionFrame.h"
#include "src/Engines/Core/Process/frames/web/ankabox/WebAnkaboxFrame.h"

#include "src/Engines/Core/Process/managers/arena/ArenaManager.h"
#include "src/Engines/Core/Process/managers/connection/ConnectionManager.h"
#include "src/Engines/Core/Process/managers/craft/CraftManager.h"
#include "src/Engines/Core/Process/managers/exchange/ExchangeManager.h"
#include "src/Engines/Core/Process/managers/farm/FarmManager.h"
#include "src/Engines/Core/Process/managers/fight/FightManager.h"
#include "src/Engines/Core/Process/managers/flood/FloodManager.h"
#include "src/Engines/Core/Process/managers/group/GroupManager.h"
#include "src/Engines/Core/Process/managers/interaction/InteractionManager.h"
#include "src/Engines/Core/Process/managers/map/MapManager.h"
#include "src/Engines/Core/Process/managers/security/SecurityManager.h"
#include "src/Engines/Core/Process/managers/stats/StatsManager.h"

#include "src/Engines/IO/Network/Reader.h"

class CoreEngine : public QObject, public DataHandler
{
    Q_OBJECT

public:
    CoreEngine();
    ~CoreEngine();

    MapManager &getMapManager();
    FarmManager &getFarmManager();
    CraftManager &getCraftManager();
    FightManager &getFightManager();
    FloodManager &getFloodManager();
    GroupManager &getGroupManager();
    StatsManager &getStatsManager();
    //ScriptManager &getScriptModule();
    ExchangeManager &getExchangeManager();
    ConnectionManager &getConnectionManager();
    InteractionManager &getInteractionManager();
    SecurityManager &getSecurityManager();

    const BotData &getData(SocketIO *sender);

signals:
    void informationsUpdated(SocketIO *sender);

protected:
    QList<AbstractFrame*> m_frames;
    QMap<ManagerType, AbstractManager*> m_managers;
};

#endif // CoreEngine_H
