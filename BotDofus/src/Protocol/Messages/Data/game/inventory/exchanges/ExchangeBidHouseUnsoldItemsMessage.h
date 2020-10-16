#ifndef EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE_H
#define EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItemGenericQuantity.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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