#ifndef TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE_H
#define TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TreasureHuntAvailableRetryCountUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntAvailableRetryCountUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntAvailableRetryCountUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntAvailableRetryCountUpdateMessage(FuncTree tree);
  TreasureHuntAvailableRetryCountUpdateMessage();

  uint questType;
  int availableRetryCount;

private:
  void _questTypeFunc(Reader *input);
  void _availableRetryCountFunc(Reader *input);
};

#endif // TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE_H