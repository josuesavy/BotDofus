#ifndef LIFEPOINTSREGENENDMESSAGE_H
#define LIFEPOINTSREGENENDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/character/stats/UpdateLifePointsMessage.h"

class LifePointsRegenEndMessage : public UpdateLifePointsMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LifePointsRegenEndMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LifePointsRegenEndMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LifePointsRegenEndMessage(FuncTree tree);
  LifePointsRegenEndMessage();

  uint lifePointsGained;

private:
  void _lifePointsGainedFunc(Reader *input);
};

#endif // LIFEPOINTSREGENENDMESSAGE_H