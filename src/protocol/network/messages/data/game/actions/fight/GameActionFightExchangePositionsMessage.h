#ifndef GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE_H
#define GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightExchangePositionsMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightExchangePositionsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightExchangePositionsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightExchangePositionsMessage(FuncTree tree);
  GameActionFightExchangePositionsMessage();

  double targetId;
  int casterCellId;
  int targetCellId;

private:
  void _targetIdFunc(Reader *input);
  void _casterCellIdFunc(Reader *input);
  void _targetCellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE_H