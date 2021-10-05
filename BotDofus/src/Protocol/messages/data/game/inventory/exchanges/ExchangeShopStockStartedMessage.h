#ifndef EXCHANGESHOPSTOCKSTARTEDMESSAGE_H
#define EXCHANGESHOPSTOCKSTARTEDMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItemToSell.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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