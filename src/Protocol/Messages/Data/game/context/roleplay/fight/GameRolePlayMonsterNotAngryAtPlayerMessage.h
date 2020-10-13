#ifndef GAMEROLEPLAYMONSTERNOTANGRYATPLAYERMESSAGE_H
#define GAMEROLEPLAYMONSTERNOTANGRYATPLAYERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameRolePlayMonsterNotAngryAtPlayerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayMonsterNotAngryAtPlayerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayMonsterNotAngryAtPlayerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayMonsterNotAngryAtPlayerMessage(FuncTree tree);
  GameRolePlayMonsterNotAngryAtPlayerMessage();

  double playerId;
  double monsterGroupId;

private:
  void _playerIdFunc(Reader *input);
  void _monsterGroupIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYMONSTERNOTANGRYATPLAYERMESSAGE_H