#ifndef GAMEROLEPLAYARENAUPDATEPLAYERINFOSALLQUEUESMESSAGE_H
#define GAMEROLEPLAYARENAUPDATEPLAYERINFOSALLQUEUESMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/fight/arena/ArenaRankInfos.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/fight/arena/GameRolePlayArenaUpdatePlayerInfosMessage.h"

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