#ifndef GAMEROLEPLAYAGGRESSIONMESSAGE_H
#define GAMEROLEPLAYAGGRESSIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayAggressionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayAggressionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayAggressionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayAggressionMessage(FuncTree tree);
  GameRolePlayAggressionMessage();

  double attackerId;
  double defenderId;

private:
  void _attackerIdFunc(Reader *input);
  void _defenderIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYAGGRESSIONMESSAGE_H