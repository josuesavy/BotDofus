#ifndef EXCHANGEREQUESTMESSAGE_H
#define EXCHANGEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeRequestMessage(FuncTree tree);
  ExchangeRequestMessage();

  int exchangeType;

private:
  void _exchangeTypeFunc(Reader *input);
};

#endif // EXCHANGEREQUESTMESSAGE_H