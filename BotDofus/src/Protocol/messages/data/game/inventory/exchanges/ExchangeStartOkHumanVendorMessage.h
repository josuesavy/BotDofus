#ifndef EXCHANGESTARTOKHUMANVENDORMESSAGE_H
#define EXCHANGESTARTOKHUMANVENDORMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItemToSellInHumanVendorShop.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeStartOkHumanVendorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkHumanVendorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkHumanVendorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkHumanVendorMessage(FuncTree tree);
  ExchangeStartOkHumanVendorMessage();

  double sellerId;
  QList<QSharedPointer<ObjectItemToSellInHumanVendorShop>> objectsInfos;

private:
  void _sellerIdFunc(Reader *input);
  void _objectsInfostreeFunc(Reader *input);
  void _objectsInfosFunc(Reader *input);

  FuncTree _objectsInfostree;
};

#endif // EXCHANGESTARTOKHUMANVENDORMESSAGE_H