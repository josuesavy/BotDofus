#ifndef EXCHANGEOBJECTMODIFIEDINBAGMESSAGE_H
#define EXCHANGEOBJECTMODIFIEDINBAGMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"

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