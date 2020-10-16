#ifndef EXCHANGESTARTEDMOUNTSTOCKMESSAGE_H
#define EXCHANGESTARTEDMOUNTSTOCKMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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