#ifndef EXCHANGESTARTEDMOUNTSTOCKMESSAGE_H
#define EXCHANGESTARTEDMOUNTSTOCKMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeStartedMountStockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartedMountStockMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartedMountStockMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartedMountStockMessage(FuncTree tree);
  ExchangeStartedMountStockMessage();

  QList<QSharedPointer<ObjectItem>> objectsInfos;

private:
  void _objectsInfostreeFunc(Reader *input);
  void _objectsInfosFunc(Reader *input);

  FuncTree _objectsInfostree;
};

#endif // EXCHANGESTARTEDMOUNTSTOCKMESSAGE_H