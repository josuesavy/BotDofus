#ifndef EXCHANGESTARTEDBIDSELLERMESSAGE_H
#define EXCHANGESTARTEDBIDSELLERMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItemToSellInBid.h"
#include "src/protocol/network/types/data/game/data/items/SellerBuyerDescriptor.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeStartedBidSellerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartedBidSellerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartedBidSellerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartedBidSellerMessage(FuncTree tree);
  ExchangeStartedBidSellerMessage();

  SellerBuyerDescriptor sellerDescriptor;
  QList<QSharedPointer<ObjectItemToSellInBid>> objectsInfos;

private:
  void _sellerDescriptortreeFunc(Reader *input);
  void _objectsInfostreeFunc(Reader *input);
  void _objectsInfosFunc(Reader *input);

  FuncTree _sellerDescriptortree;
  FuncTree _objectsInfostree;
};

#endif // EXCHANGESTARTEDBIDSELLERMESSAGE_H