#ifndef EXCHANGESTARTEDMESSAGE_H
#define EXCHANGESTARTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartedMessage(FuncTree tree);
  ExchangeStartedMessage();

  int exchangeType;

private:
  void _exchangeTypeFunc(Reader *input);
};

#endif // EXCHANGESTARTEDMESSAGE_H