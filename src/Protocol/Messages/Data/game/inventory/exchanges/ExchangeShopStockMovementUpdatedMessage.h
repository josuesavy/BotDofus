#ifndef EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE_H
#define EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItemToSell.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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