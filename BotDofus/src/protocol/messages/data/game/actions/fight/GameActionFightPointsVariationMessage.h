#ifndef GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE_H
#define GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightPointsVariationMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightPointsVariationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightPointsVariationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightPointsVariationMessage(FuncTree tree);
  GameActionFightPointsVariationMessage();

  double targetId;
  int delta;

private:
  void _targetIdFunc(Reader *input);
  void _deltaFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE_H