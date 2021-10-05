#ifndef EXCHANGEREQUESTEDTRADEMESSAGE_H
#define EXCHANGEREQUESTEDTRADEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeRequestedMessage.h"

class ExchangeRequestedTradeMessage : public ExchangeRequestedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeRequestedTradeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeRequestedTradeMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeRequestedTradeMessage(FuncTree tree);
  ExchangeRequestedTradeMessage();

  double source;
  double target;

private:
  void _sourceFunc(Reader *input);
  void _targetFunc(Reader *input);
};

#endif // EXCHANGEREQUESTEDTRADEMESSAGE_H