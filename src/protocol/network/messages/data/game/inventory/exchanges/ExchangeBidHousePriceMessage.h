#ifndef EXCHANGEBIDHOUSEPRICEMESSAGE_H
#define EXCHANGEBIDHOUSEPRICEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  uint objectGID;

private:
  void _objectGIDFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSEPRICEMESSAGE_H