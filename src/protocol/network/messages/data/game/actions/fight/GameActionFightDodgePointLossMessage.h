#ifndef GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE_H
#define GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightDodgePointLossMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightDodgePointLossMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightDodgePointLossMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightDodgePointLossMessage(FuncTree tree);
  GameActionFightDodgePointLossMessage();

  double targetId;
  uint amount;

private:
  void _targetIdFunc(Reader *input);
  void _amountFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE_H