#ifndef GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_H
#define GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayAttackMonsterRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayAttackMonsterRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayAttackMonsterRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayAttackMonsterRequestMessage(FuncTree tree);
  GameRolePlayAttackMonsterRequestMessage();

  double monsterGroupId;

private:
  void _monsterGroupIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_H