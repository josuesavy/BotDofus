#ifndef EXCHANGESTARTOKNPCSHOPMESSAGE_H
#define EXCHANGESTARTOKNPCSHOPMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItemToSellInNpcShop.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeStartOkNpcShopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkNpcShopMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkNpcShopMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkNpcShopMessage(FuncTree tree);
  ExchangeStartOkNpcShopMessage();

  double npcSellerId;
  uint tokenId;
  QList<QSharedPointer<ObjectItemToSellInNpcShop>> objectsInfos;

private:
  void _npcSellerIdFunc(Reader *input);
  void _tokenIdFunc(Reader *input);
  void _objectsInfostreeFunc(Reader *input);
  void _objectsInfosFunc(Reader *input);

  FuncTree _objectsInfostree;
};

#endif // EXCHANGESTARTOKNPCSHOPMESSAGE_H