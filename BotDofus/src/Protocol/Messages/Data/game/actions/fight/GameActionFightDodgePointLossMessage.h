#ifndef GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE_H
#define GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

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