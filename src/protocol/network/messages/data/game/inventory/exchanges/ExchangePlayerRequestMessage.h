#ifndef EXCHANGEPLAYERREQUESTMESSAGE_H
#define EXCHANGEPLAYERREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeRequestMessage.h"

class ExchangePlayerRequestMessage : public ExchangeRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangePlayerRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangePlayerRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangePlayerRequestMessage(FuncTree tree);
  ExchangePlayerRequestMessage();

  double target;

private:
  void _targetFunc(Reader *input);
};

#endif // EXCHANGEPLAYERREQUESTMESSAGE_H