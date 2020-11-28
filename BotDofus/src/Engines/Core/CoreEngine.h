#ifndef CoreEngine_H
#define CoreEngine_H

#include "src/Engines/Core/Process/Frames/common/basic/CommonBasicFrame.h"
#include "src/Engines/Core/Process/Frames/connection/ConnectionFrame.h"
#include "src/Engines/Core/Process/Frames/connection/register/ConnectionRegisterFrame.h"
#include "src/Engines/Core/Process/Frames/game/achievement/AchievementFrame.h"
#include "src/Engines/Core/Process/Frames/game/actions/GameActionsFrame.h"
#include "src/Engines/Core/Process/Frames/game/actions/fight/GameActionsFightFrame.h"
#include "src/Engines/Core/Process/Frames/game/actions/sequence/GameActionsSequenceFrame.h"
#include "src/Engines/Core/Process/Frames/game/alliance/GameAllianceFrame.h"
#include "src/Engines/Core/Process/Frames/game/almanach/GameAlmanachFrame.h"
#include "src/Engines/Core/Process/Frames/game/approach/GameApproachFrame.h"
#include "src/Engines/Core/Process/Frames/game/atlas/compass/GameAtlasCompassFrame.h"
#include "src/Engines/Core/Process/Frames/game/basic/GameBasicFrame.h"
#include "src/Engines/Core/Process/Frames/game/character/choice/GameCharacterChoiceFrame.h"
#include "src/Engines/Core/Process/Frames/game/character/creation/GameCharacterCreationFrame.h"
#include "src/Engines/Core/Process/Frames/game/character/deletion/GameCharacterDeletionFrame.h"
#include "src/Engines/Core/Process/Frames/game/character/stats/GameCharacterStatsFrame.h"
#include "src/Engines/Core/Process/Frames/game/character/status/GameCharacterStatusFrame.h"
#include "src/Engines/Core/Process/Frames/game/chat/GameChatFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/GameContextFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/fight/GameContextFightFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/fight/character/GameContextFightCharacterFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/mount/GameContextMountFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/notification/GameContextNotificationFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/GameContextRoleplayFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/death/GameContextRoleplayDeathFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/fight/GameContextRoleplayFightFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/fight/arena/GameContextRoleplayFightArenaFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/job/GameContextRoleplayJobFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/npc/GameContextRoleplayNpcFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/objects/GameContextRoleplayObjectsFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/party/GameContextRoleplayPartyFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/quest/GameContextRoleplayQuestFrame.h"
#include "src/Engines/Core/Process/Frames/game/context/roleplay/stats/GameContextRoleplayStatsFrame.h"
#include "src/Engines/Core/Process/Frames/game/dialog/GameDialogFrame.h"
#include "src/Engines/Core/Process/Frames/game/friend/GameFriendFrame.h"
#include "src/Engines/Core/Process/Frames/game/guild/GameGuildFrame.h"
#include "src/Engines/Core/Process/Frames/game/initialization/GameInitializationFrame.h"
#include "src/Engines/Core/Process/Frames/game/interactive/GameInteractiveFrame.h"
#include "src/Engines/Core/Process/Frames/game/interactive/zaap/GameInteractiveZaapFrame.h"
#include "src/Engines/Core/Process/Frames/game/inventory/GameInventoryFrame.h"
#include "src/Engines/Core/Process/Frames/game/inventory/exchanges/GameInventoryExchangesFrame.h"
#include "src/Engines/Core/Process/Frames/game/inventory/items/GameInventoryItemsFrame.h"
#include "src/Engines/Core/Process/Frames/game/inventory/spells/GameInventorySpellsFrame.h"
#include "src/Engines/Core/Process/Frames/game/inventory/storage/GameInventoryStorageFrame.h"
#include "src/Engines/Core/Process/Frames/game/moderation/GameModerationFrame.h"
#include "src/Engines/Core/Process/Frames/game/subscriber/GameSubscriberFrame.h"
#include "src/Engines/Core/Process/Frames/handshake/HandshakeFrame.h"
#include "src/Engines/Core/Process/Frames/queues/QueueFrame.h"
#include "src/Engines/Core/Process/Frames/secure/SecureFrame.h"
#include "src/Engines/Core/Process/Frames/security/SecurityFrame.h"
#include "src/Engines/Core/Process/Frames/server/basic/ServerBasicFrame.h"
#include "src/Engines/Core/Process/Frames/subscription/SubscriptionFrame.h"
#include "src/Engines/Core/Process/Frames/web/ankabox/WebAnkaboxFrame.h"

#include "src/Engines/Core/Process/Managers/arena/ArenaManager.h"
#include "src/Engines/Core/Process/Managers/connection/ConnectionManager.h"
#include "src/Engines/Core/Process/Managers/craft/CraftManager.h"
#include "src/Engines/Core/Process/Managers/exchange/ExchangeManager.h"
#include "src/Engines/Core/Process/Managers/farm/FarmManager.h"
#include "src/Engines/Core/Process/Managers/fight/FightManager.h"
#include "src/Engines/Core/Process/Managers/flood/FloodManager.h"
#include "src/Engines/Core/Process/Managers/group/GroupManager.h"
#include "src/Engines/Core/Process/Managers/interaction/InteractionManager.h"
#include "src/Engines/Core/Process/Managers/map/MapManager.h"
#include "src/Engines/Core/Process/Managers/security/SecurityManager.h"
#include "src/Engines/Core/Process/Managers/stats/StatsManager.h"

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
