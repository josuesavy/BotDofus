#ifndef GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE_H
#define GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/fight/arena/ArenaRankInfos.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

  ArenaRankInfos solo;

private:
  void _solotreeFunc(Reader *input);

  FuncTree _solotree;
};

#endif // GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE_H