#ifndef EXCHANGEBIDPRICEFORSELLERMESSAGE_H
#define EXCHANGEBIDPRICEFORSELLERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeBidPriceMessage.h"

class ExchangeBidPriceForSellerMessage : public ExchangeBidPriceMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidPriceForSellerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidPriceForSellerMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidPriceForSellerMessage(FuncTree tree);
  ExchangeBidPriceForSellerMessage();

  bool allIdentical;
  QList<double> minimalPrices;

private:
  void _allIdenticalFunc(Reader *input);
  void _minimalPricestreeFunc(Reader *input);
  void _minimalPricesFunc(Reader *input);

  FuncTree _minimalPricestree;
};

#endif // EXCHANGEBIDPRICEFORSELLERMESSAGE_H