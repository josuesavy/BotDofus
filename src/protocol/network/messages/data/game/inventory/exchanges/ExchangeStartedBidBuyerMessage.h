#ifndef EXCHANGESTARTEDBIDBUYERMESSAGE_H
#define EXCHANGESTARTEDBIDBUYERMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/SellerBuyerDescriptor.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeStartedBidBuyerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartedBidBuyerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartedBidBuyerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartedBidBuyerMessage(FuncTree tree);
  ExchangeStartedBidBuyerMessage();

  SellerBuyerDescriptor buyerDescriptor;

private:
  void _buyerDescriptortreeFunc(Reader *input);

  FuncTree _buyerDescriptortree;
};

#endif // EXCHANGESTARTEDBIDBUYERMESSAGE_H