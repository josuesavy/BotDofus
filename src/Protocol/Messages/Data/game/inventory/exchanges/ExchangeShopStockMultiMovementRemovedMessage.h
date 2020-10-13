#ifndef EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE_H
#define EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeShopStockMultiMovementRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeShopStockMultiMovementRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeShopStockMultiMovementRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeShopStockMultiMovementRemovedMessage(FuncTree tree);
  ExchangeShopStockMultiMovementRemovedMessage();

  QList<uint> objectIdList;

private:
  void _objectIdListtreeFunc(Reader *input);
  void _objectIdListFunc(Reader *input);

  FuncTree _objectIdListtree;
};

#endif // EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE_H