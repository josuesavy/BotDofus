#ifndef EXCHANGESTARTEDBIDBUYERMESSAGE_H
#define EXCHANGESTARTEDBIDBUYERMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/SellerBuyerDescriptor.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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