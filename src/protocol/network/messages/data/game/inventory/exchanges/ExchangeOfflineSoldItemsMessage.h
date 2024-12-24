#ifndef EXCHANGEOFFLINESOLDITEMSMESSAGE_H
#define EXCHANGEOFFLINESOLDITEMSMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItemQuantityPriceDateEffects.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeOfflineSoldItemsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeOfflineSoldItemsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeOfflineSoldItemsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeOfflineSoldItemsMessage(FuncTree tree);
  ExchangeOfflineSoldItemsMessage();

  QList<QSharedPointer<ObjectItemQuantityPriceDateEffects>> bidHouseItems;

private:
  void _bidHouseItemstreeFunc(Reader *input);
  void _bidHouseItemsFunc(Reader *input);

  FuncTree _bidHouseItemstree;
};

#endif // EXCHANGEOFFLINESOLDITEMSMESSAGE_H