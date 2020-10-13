#ifndef EXCHANGEREQUESTONSHOPSTOCKMESSAGE_H
#define EXCHANGEREQUESTONSHOPSTOCKMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeRequestOnShopStockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeRequestOnShopStockMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeRequestOnShopStockMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeRequestOnShopStockMessage(FuncTree tree);
  ExchangeRequestOnShopStockMessage();
};

#endif // EXCHANGEREQUESTONSHOPSTOCKMESSAGE_H