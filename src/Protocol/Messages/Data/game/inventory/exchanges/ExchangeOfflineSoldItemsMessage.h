#ifndef EXCHANGEOFFLINESOLDITEMSMESSAGE_H
#define EXCHANGEOFFLINESOLDITEMSMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItemQuantityPriceDateEffects.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
  QList<QSharedPointer<ObjectItemQuantityPriceDateEffects>> merchantItems;

private:
  void _bidHouseItemstreeFunc(Reader *input);
  void _bidHouseItemsFunc(Reader *input);
  void _merchantItemstreeFunc(Reader *input);
  void _merchantItemsFunc(Reader *input);

  FuncTree _bidHouseItemstree;
  FuncTree _merchantItemstree;
};

#endif // EXCHANGEOFFLINESOLDITEMSMESSAGE_H