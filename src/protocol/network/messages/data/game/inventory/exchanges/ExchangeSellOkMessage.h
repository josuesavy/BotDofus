#ifndef EXCHANGESELLOKMESSAGE_H
#define EXCHANGESELLOKMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeSellOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeSellOkMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeSellOkMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeSellOkMessage(FuncTree tree);
  ExchangeSellOkMessage();
};

#endif // EXCHANGESELLOKMESSAGE_H