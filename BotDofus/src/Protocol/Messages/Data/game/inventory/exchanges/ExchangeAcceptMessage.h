#ifndef EXCHANGEACCEPTMESSAGE_H
#define EXCHANGEACCEPTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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