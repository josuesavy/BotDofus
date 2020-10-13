#ifndef EXCHANGESTARTOKHUMANVENDORMESSAGE_H
#define EXCHANGESTARTOKHUMANVENDORMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItemToSellInHumanVendorShop.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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