#ifndef EXCHANGEACCEPTMESSAGE_H
#define EXCHANGEACCEPTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeAcceptMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeAcceptMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeAcceptMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeAcceptMessage(FuncTree tree);
  ExchangeAcceptMessage();
};

#endif // EXCHANGEACCEPTMESSAGE_H