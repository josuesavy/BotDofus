#ifndef EXCHANGEOBJECTMODIFIEDINBAGMESSAGE_H
#define EXCHANGEOBJECTMODIFIEDINBAGMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectModifiedInBagMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectModifiedInBagMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectModifiedInBagMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectModifiedInBagMessage(FuncTree tree);
  ExchangeObjectModifiedInBagMessage();

  QSharedPointer<ObjectItem> object;

private:
  void _objecttreeFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // EXCHANGEOBJECTMODIFIEDINBAGMESSAGE_H