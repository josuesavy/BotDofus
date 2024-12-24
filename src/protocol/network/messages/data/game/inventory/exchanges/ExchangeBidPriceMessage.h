#ifndef EXCHANGEBIDPRICEMESSAGE_H
#define EXCHANGEBIDPRICEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeBidPriceMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidPriceMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidPriceMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidPriceMessage(FuncTree tree);
  ExchangeBidPriceMessage();

  uint genericId;
  double averagePrice;

private:
  void _genericIdFunc(Reader *input);
  void _averagePriceFunc(Reader *input);
};

#endif // EXCHANGEBIDPRICEMESSAGE_H