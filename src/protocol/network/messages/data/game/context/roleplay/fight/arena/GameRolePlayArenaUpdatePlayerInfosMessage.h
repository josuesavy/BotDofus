#ifndef GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE_H
#define GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/fight/arena/ArenaRankInfos.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayArenaUpdatePlayerInfosMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaUpdatePlayerInfosMessage(FuncTree tree);
  GameRolePlayArenaUpdatePlayerInfosMessage();

  QList<ArenaRankInfos> arenaRanks;
  double banEndDate;

private:
  void _arenaRankstreeFunc(Reader *input);
  void _arenaRanksFunc(Reader *input);
  void _banEndDateFunc(Reader *input);

  FuncTree _arenaRankstree;
};

#endif // GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE_H