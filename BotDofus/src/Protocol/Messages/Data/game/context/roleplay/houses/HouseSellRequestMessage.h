#ifndef HOUSESELLREQUESTMESSAGE_H
#define HOUSESELLREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HouseSellRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseSellRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseSellRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseSellRequestMessage(FuncTree tree);
  HouseSellRequestMessage();

  uint instanceId;
  double amount;
  bool forSale;

private:
  void _instanceIdFunc(Reader *input);
  void _amountFunc(Reader *input);
  void _forSaleFunc(Reader *input);
};

#endif // HOUSESELLREQUESTMESSAGE_H