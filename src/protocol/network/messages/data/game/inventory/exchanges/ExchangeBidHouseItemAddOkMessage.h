#ifndef EXCHANGEBIDHOUSEITEMADDOKMESSAGE_H
#define EXCHANGEBIDHOUSEITEMADDOKMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItemToSellInBid.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeBidHouseItemAddOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseItemAddOkMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseItemAddOkMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseItemAddOkMessage(FuncTree tree);
  ExchangeBidHouseItemAddOkMessage();

  QSharedPointer<ObjectItemToSellInBid> itemInfo;

private:
  void _itemInfotreeFunc(Reader *input);

  FuncTree _itemInfotree;
};

#endif // EXCHANGEBIDHOUSEITEMADDOKMESSAGE_H