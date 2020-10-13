#ifndef GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_H
#define GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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