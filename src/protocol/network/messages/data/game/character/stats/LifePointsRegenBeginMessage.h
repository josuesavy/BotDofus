#ifndef LIFEPOINTSREGENBEGINMESSAGE_H
#define LIFEPOINTSREGENBEGINMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class LifePointsRegenBeginMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LifePointsRegenBeginMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LifePointsRegenBeginMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LifePointsRegenBeginMessage(FuncTree tree);
  LifePointsRegenBeginMessage();

  uint regenRate;

private:
  void _regenRateFunc(Reader *input);
};

#endif // LIFEPOINTSREGENBEGINMESSAGE_H