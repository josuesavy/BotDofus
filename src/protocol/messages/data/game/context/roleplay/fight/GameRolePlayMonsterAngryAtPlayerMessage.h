#ifndef GAMEROLEPLAYMONSTERANGRYATPLAYERMESSAGE_H
#define GAMEROLEPLAYMONSTERANGRYATPLAYERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayMonsterAngryAtPlayerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayMonsterAngryAtPlayerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayMonsterAngryAtPlayerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayMonsterAngryAtPlayerMessage(FuncTree tree);
  GameRolePlayMonsterAngryAtPlayerMessage();

  double playerId;
  double monsterGroupId;
  double angryStartTime;
  double attackTime;

private:
  void _playerIdFunc(Reader *input);
  void _monsterGroupIdFunc(Reader *input);
  void _angryStartTimeFunc(Reader *input);
  void _attackTimeFunc(Reader *input);
};

#endif // GAMEROLEPLAYMONSTERANGRYATPLAYERMESSAGE_H