#ifndef GAMEACTIONFIGHTSLIDEMESSAGE_H
#define GAMEACTIONFIGHTSLIDEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightSlideMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightSlideMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightSlideMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightSlideMessage(FuncTree tree);
  GameActionFightSlideMessage();

  double targetId;
  int startCellId;
  int endCellId;

private:
  void _targetIdFunc(Reader *input);
  void _startCellIdFunc(Reader *input);
  void _endCellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTSLIDEMESSAGE_H