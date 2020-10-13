#ifndef EXCHANGEREQUESTEDMESSAGE_H
#define EXCHANGEREQUESTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeRequestedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeRequestedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeRequestedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeRequestedMessage(FuncTree tree);
  ExchangeRequestedMessage();

  int exchangeType;

private:
  void _exchangeTypeFunc(Reader *input);
};

#endif // EXCHANGEREQUESTEDMESSAGE_H