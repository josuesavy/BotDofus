#ifndef EXCHANGEPLAYERREQUESTMESSAGE_H
#define EXCHANGEPLAYERREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeRequestMessage.h"

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