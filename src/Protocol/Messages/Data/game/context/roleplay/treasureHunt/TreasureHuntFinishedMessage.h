#ifndef TREASUREHUNTFINISHEDMESSAGE_H
#define TREASUREHUNTFINISHEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TreasureHuntFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntFinishedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntFinishedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntFinishedMessage(FuncTree tree);
  TreasureHuntFinishedMessage();

  uint questType;

private:
  void _questTypeFunc(Reader *input);
};

#endif // TREASUREHUNTFINISHEDMESSAGE_H