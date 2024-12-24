#ifndef PRISMEXCHANGEREQUESTMESSAGE_H
#define PRISMEXCHANGEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PrismExchangeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismExchangeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismExchangeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismExchangeRequestMessage(FuncTree tree);
  PrismExchangeRequestMessage();
};

#endif // PRISMEXCHANGEREQUESTMESSAGE_H