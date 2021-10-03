#ifndef EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE_H
#define EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItemToSell.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeShopStockMovementUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeShopStockMovementUpdatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeShopStockMovementUpdatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeShopStockMovementUpdatedMessage(FuncTree tree);
  ExchangeShopStockMovementUpdatedMessage();

  QSharedPointer<ObjectItemToSell> objectInfo;

private:
  void _objectInfotreeFunc(Reader *input);

  FuncTree _objectInfotree;
};

#endif // EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE_H