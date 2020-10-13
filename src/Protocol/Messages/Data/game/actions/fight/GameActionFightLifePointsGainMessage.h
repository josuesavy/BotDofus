#ifndef GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE_H
#define GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightLifePointsGainMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightLifePointsGainMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightLifePointsGainMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightLifePointsGainMessage(FuncTree tree);
  GameActionFightLifePointsGainMessage();

  double targetId;
  uint delta;

private:
  void _targetIdFunc(Reader *input);
  void _deltaFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE_H