#ifndef EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE_H
#define EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItemGenericQuantity.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeBidHouseUnsoldItemsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseUnsoldItemsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseUnsoldItemsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseUnsoldItemsMessage(FuncTree tree);
  ExchangeBidHouseUnsoldItemsMessage();

  QList<ObjectItemGenericQuantity> items;

private:
  void _itemstreeFunc(Reader *input);
  void _itemsFunc(Reader *input);

  FuncTree _itemstree;
};

#endif // EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE_H