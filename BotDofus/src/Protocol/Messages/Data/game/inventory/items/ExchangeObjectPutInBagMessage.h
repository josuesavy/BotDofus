#ifndef EXCHANGEOBJECTPUTINBAGMESSAGE_H
#define EXCHANGEOBJECTPUTINBAGMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectPutInBagMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectPutInBagMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectPutInBagMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectPutInBagMessage(FuncTree tree);
  ExchangeObjectPutInBagMessage();

  QSharedPointer<ObjectItem> object;

private:
  void _objecttreeFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // EXCHANGEOBJECTPUTINBAGMESSAGE_H