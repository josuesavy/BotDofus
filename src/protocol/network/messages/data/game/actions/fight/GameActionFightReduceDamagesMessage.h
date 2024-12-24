#ifndef GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE_H
#define GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightReduceDamagesMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightReduceDamagesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightReduceDamagesMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightReduceDamagesMessage(FuncTree tree);
  GameActionFightReduceDamagesMessage();

  double targetId;
  uint amount;

private:
  void _targetIdFunc(Reader *input);
  void _amountFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE_H