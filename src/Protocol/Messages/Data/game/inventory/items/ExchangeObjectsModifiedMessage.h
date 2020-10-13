#ifndef EXCHANGEOBJECTSMODIFIEDMESSAGE_H
#define EXCHANGEOBJECTSMODIFIEDMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"

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