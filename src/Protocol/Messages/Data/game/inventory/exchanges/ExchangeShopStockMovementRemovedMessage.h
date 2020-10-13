#ifndef EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE_H
#define EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeShopStockMovementRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeShopStockMovementRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeShopStockMovementRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeShopStockMovementRemovedMessage(FuncTree tree);
  ExchangeShopStockMovementRemovedMessage();

  uint objectId;

private:
  void _objectIdFunc(Reader *input);
};

#endif // EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE_H