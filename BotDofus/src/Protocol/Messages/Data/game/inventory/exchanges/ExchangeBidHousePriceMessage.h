#ifndef EXCHANGEBIDHOUSEPRICEMESSAGE_H
#define EXCHANGEBIDHOUSEPRICEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeBidHousePriceMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHousePriceMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHousePriceMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHousePriceMessage(FuncTree tree);
  ExchangeBidHousePriceMessage();

  uint genId;

private:
  void _genIdFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSEPRICEMESSAGE_H