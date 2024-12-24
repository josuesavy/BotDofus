#ifndef GAMEACTIONFIGHTSTEALKAMAMESSAGE_H
#define GAMEACTIONFIGHTSTEALKAMAMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightStealKamaMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightStealKamaMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightStealKamaMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightStealKamaMessage(FuncTree tree);
  GameActionFightStealKamaMessage();

  double targetId;
  double amount;

private:
  void _targetIdFunc(Reader *input);
  void _amountFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTSTEALKAMAMESSAGE_H