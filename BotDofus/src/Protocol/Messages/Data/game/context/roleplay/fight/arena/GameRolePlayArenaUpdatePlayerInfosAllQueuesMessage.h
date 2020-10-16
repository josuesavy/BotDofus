#ifndef GAMEROLEPLAYARENAUPDATEPLAYERINFOSALLQUEUESMESSAGE_H
#define GAMEROLEPLAYARENAUPDATEPLAYERINFOSALLQUEUESMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/fight/arena/ArenaRankInfos.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/fight/arena/GameRolePlayArenaUpdatePlayerInfosMessage.h"

class GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage : public GameRolePlayArenaUpdatePlayerInfosMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage(FuncTree tree);
  GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage();

  ArenaRankInfos team;
  ArenaRankInfos duel;

private:
  void _teamtreeFunc(Reader *input);
  void _dueltreeFunc(Reader *input);

  FuncTree _teamtree;
  FuncTree _dueltree;
};

#endif // GAMEROLEPLAYARENAUPDATEPLAYERINFOSALLQUEUESMESSAGE_H