#ifndef EXCHANGEOBJECTSMODIFIEDMESSAGE_H
#define EXCHANGEOBJECTSMODIFIEDMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectsModifiedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectsModifiedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectsModifiedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectsModifiedMessage(FuncTree tree);
  ExchangeObjectsModifiedMessage();

  QList<QSharedPointer<ObjectItem>> object;

private:
  void _objecttreeFunc(Reader *input);
  void _objectFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // EXCHANGEOBJECTSMODIFIEDMESSAGE_H