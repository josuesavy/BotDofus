#ifndef EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE_H
#define EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeStartedTaxCollectorShopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartedTaxCollectorShopMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartedTaxCollectorShopMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartedTaxCollectorShopMessage(FuncTree tree);
  ExchangeStartedTaxCollectorShopMessage();

  QList<QSharedPointer<ObjectItem>> objects;
  double kamas;

private:
  void _objectstreeFunc(Reader *input);
  void _objectsFunc(Reader *input);
  void _kamasFunc(Reader *input);

  FuncTree _objectstree;
};

#endif // EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE_H