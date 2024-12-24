#ifndef EXCHANGEOBJECTSMODIFIEDMESSAGE_H
#define EXCHANGEOBJECTSMODIFIEDMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeObjectMessage.h"

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