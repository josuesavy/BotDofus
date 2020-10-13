#ifndef EXCHANGESHOPSTOCKSTARTEDMESSAGE_H
#define EXCHANGESHOPSTOCKSTARTEDMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItemToSell.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeShopStockStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeShopStockStartedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeShopStockStartedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeShopStockStartedMessage(FuncTree tree);
  ExchangeShopStockStartedMessage();

  QList<QSharedPointer<ObjectItemToSell>> objectsInfos;

private:
  void _objectsInfostreeFunc(Reader *input);
  void _objectsInfosFunc(Reader *input);

  FuncTree _objectsInfostree;
};

#endif // EXCHANGESHOPSTOCKSTARTEDMESSAGE_H