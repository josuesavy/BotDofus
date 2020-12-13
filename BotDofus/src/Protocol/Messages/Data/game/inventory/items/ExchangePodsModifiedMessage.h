#ifndef EXCHANGEPODSMODIFIEDMESSAGE_H
#define EXCHANGEPODSMODIFIEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangePodsModifiedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangePodsModifiedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangePodsModifiedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangePodsModifiedMessage(FuncTree tree);
  ExchangePodsModifiedMessage();

  uint currentWeight;
  uint maxWeight;

private:
  void _currentWeightFunc(Reader *input);
  void _maxWeightFunc(Reader *input);
};

#endif // EXCHANGEPODSMODIFIEDMESSAGE_H