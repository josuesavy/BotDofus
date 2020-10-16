#ifndef PADDOCKSELLREQUESTMESSAGE_H
#define PADDOCKSELLREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PaddockSellRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockSellRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockSellRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockSellRequestMessage(FuncTree tree);
  PaddockSellRequestMessage();

  double price;
  bool forSale;

private:
  void _priceFunc(Reader *input);
  void _forSaleFunc(Reader *input);
};

#endif // PADDOCKSELLREQUESTMESSAGE_H