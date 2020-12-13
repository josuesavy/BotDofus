#ifndef PRISMMODULEEXCHANGEREQUESTMESSAGE_H
#define PRISMMODULEEXCHANGEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismModuleExchangeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismModuleExchangeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismModuleExchangeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismModuleExchangeRequestMessage(FuncTree tree);
  PrismModuleExchangeRequestMessage();
};

#endif // PRISMMODULEEXCHANGEREQUESTMESSAGE_H