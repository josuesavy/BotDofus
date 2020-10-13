#ifndef HOUSESELLREQUESTMESSAGE_H
#define HOUSESELLREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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