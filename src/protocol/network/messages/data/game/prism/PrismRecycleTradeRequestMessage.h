#ifndef PRISMRECYCLETRADEREQUESTMESSAGE_H
#define PRISMRECYCLETRADEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PrismRecycleTradeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismRecycleTradeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismRecycleTradeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismRecycleTradeRequestMessage(FuncTree tree);
  PrismRecycleTradeRequestMessage();
};

#endif // PRISMRECYCLETRADEREQUESTMESSAGE_H