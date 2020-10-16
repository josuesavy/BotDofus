#ifndef EXCHANGEREQUESTEDTRADEMESSAGE_H
#define EXCHANGEREQUESTEDTRADEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeRequestedMessage.h"

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