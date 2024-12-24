#ifndef EXCHANGEOBJECTSADDEDMESSAGE_H
#define EXCHANGEOBJECTSADDEDMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectsAddedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectsAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectsAddedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectsAddedMessage(FuncTree tree);
  ExchangeObjectsAddedMessage();

  QList<QSharedPointer<ObjectItem>> object;

private:
  void _objecttreeFunc(Reader *input);
  void _objectFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // EXCHANGEOBJECTSADDEDMESSAGE_H