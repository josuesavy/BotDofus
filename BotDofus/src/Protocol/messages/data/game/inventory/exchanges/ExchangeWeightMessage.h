#ifndef EXCHANGEWEIGHTMESSAGE_H
#define EXCHANGEWEIGHTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeWeightMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeWeightMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeWeightMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeWeightMessage(FuncTree tree);
  ExchangeWeightMessage();

  uint currentWeight;
  uint maxWeight;

private:
  void _currentWeightFunc(Reader *input);
  void _maxWeightFunc(Reader *input);
};

#endif // EXCHANGEWEIGHTMESSAGE_H