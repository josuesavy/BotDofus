#ifndef EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE_H
#define EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItemToSell.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeShopStockMultiMovementUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeShopStockMultiMovementUpdatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeShopStockMultiMovementUpdatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeShopStockMultiMovementUpdatedMessage(FuncTree tree);
  ExchangeShopStockMultiMovementUpdatedMessage();

  QList<QSharedPointer<ObjectItemToSell>> objectInfoList;

private:
  void _objectInfoListtreeFunc(Reader *input);
  void _objectInfoListFunc(Reader *input);

  FuncTree _objectInfoListtree;
};

#endif // EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE_H