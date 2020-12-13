#ifndef CoreEngine_H
#define CoreEngine_H

#include "src/engines/core/process/frames/common/basic/CommonBasicFrame.h"
#include "src/engines/core/process/frames/connection/ConnectionFrame.h"
#include "src/engines/core/process/frames/connection/register/ConnectionRegisterFrame.h"
#include "src/engines/core/process/frames/connection/search/ConnectionSearchFrame.h"
#include "src/engines/core/process/frames/game/achievement/AchievementFrame.h"
#include "src/engines/core/process/frames/game/actions/GameActionsFrame.h"
#include "src/engines/core/process/frames/game/actions/fight/GameActionsFightFrame.h"
#include "src/engines/core/process/frames/game/actions/sequence/GameActionsSequenceFrame.h"
#include "src/engines/core/process/frames/game/alliance/GameAllianceFrame.h"
#include "src/engines/core/process/frames/game/almanach/GameAlmanachFrame.h"
#include "src/engines/core/process/frames/game/approach/GameApproachFrame.h"
#include "src/engines/core/process/frames/game/atlas/compass/GameAtlasCompassFrame.h"
#include "src/engines/core/process/frames/game/basic/GameBasicFrame.h"
#include "src/engines/core/process/frames/game/character/choice/GameCharacterChoiceFrame.h"
#include "src/engines/core/process/frames/game/character/creation/GameCharacterCreationFrame.h"
#include "src/engines/core/process/frames/game/character/deletion/GameCharacterDeletionFrame.h"
#include "src/engines/core/process/frames/game/character/stats/GameCharacterStatsFrame.h"
#include "src/engines/core/process/frames/game/character/status/GameCharacterStatusFrame.h"
#include "src/engines/core/process/frames/game/chat/GameChatFrame.h"
#include "src/engines/core/process/frames/game/context/GameContextFrame.h"
#include "src/engines/core/process/frames/game/context/fight/GameContextFightFrame.h"
#include "src/engines/core/process/frames/game/context/fight/character/GameContextFightCharacterFrame.h"
#include "src/engines/core/process/frames/game/context/mount/GameContextMountFrame.h"
#include "src/engines/core/process/frames/game/context/notification/GameContextNotificationFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/GameContextRoleplayFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/death/GameContextRoleplayDeathFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/emote/GameContextRoleplayEmoteFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/fight/GameContextRoleplayFightFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/fight/arena/GameContextRoleplayFightArenaFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/job/GameContextRoleplayJobFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/npc/GameContextRoleplayNpcFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/objects/GameContextRoleplayObjectsFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/party/GameContextRoleplayPartyFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/quest/GameContextRoleplayQuestFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/stats/GameContextRoleplayStatsFrame.h"
#include "src/engines/core/process/frames/game/context/roleplay/treasureHunt/GameContextRoleplayTreasureHuntFrame.h"
#include "src/engines/core/process/frames/game/dialog/GameDialogFrame.h"
#include "src/engines/core/process/frames/game/friend/GameFriendFrame.h"
#include "src/engines/core/process/frames/game/guild/GameGuildFrame.h"
#include "src/engines/core/process/frames/game/initialization/GameInitializationFrame.h"
#include "src/engines/core/process/frames/game/interactive/GameInteractiveFrame.h"
#include "src/engines/core/process/frames/game/interactive/zaap/GameInteractiveZaapFrame.h"
#include "src/engines/core/process/frames/game/inventory/GameInventoryFrame.h"
#include "src/engines/core/process/frames/game/inventory/exchanges/GameInventoryExchangesFrame.h"
#include "src/engines/core/process/frames/game/inventory/items/GameInventoryItemsFrame.h"
#include "src/engines/core/process/frames/game/inventory/spells/GameInventorySpellsFrame.h"
#include "src/engines/core/process/frames/game/inventory/storage/GameInventoryStorageFrame.h"
#include "src/engines/core/process/frames/game/moderation/GameModerationFrame.h"
#include "src/engines/core/process/frames/game/subscriber/GameSubscriberFrame.h"
#include "src/engines/core/process/frames/handshake/HandshakeFrame.h"
#include "src/engines/core/process/frames/queues/QueueFrame.h"
#include "src/engines/core/process/frames/secure/SecureFrame.h"
#include "src/engines/core/process/frames/security/SecurityFrame.h"
#include "src/engines/core/process/frames/server/basic/ServerBasicFrame.h"
#include "src/engines/core/process/frames/subscription/SubscriptionFrame.h"
#include "src/engines/core/process/frames/web/ankabox/WebAnkaboxFrame.h"

#include "src/engines/core/process/managers/arena/ArenaManager.h"
#include "src/engines/core/process/managers/connection/ConnectionManager.h"
#include "src/engines/core/process/managers/craft/CraftManager.h"
#include "src/engines/core/process/managers/exchange/ExchangeManager.h"
#include "src/engines/core/process/managers/farm/FarmManager.h"
#include "src/engines/core/process/managers/fight/FightManager.h"
#include "src/engines/core/process/managers/flood/FloodManager.h"
#include "src/engines/core/process/managers/group/GroupManager.h"
#include "src/engines/core/process/managers/interaction/InteractionManager.h"
#include "src/engines/core/process/managers/map/MapManager.h"
#include "src/engines/core/process/managers/security/SecurityManager.h"
#include "src/engines/core/process/managers/stats/StatsManager.h"

#include "src/engines/io/network/Reader.h"

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
