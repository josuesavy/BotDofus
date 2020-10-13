#ifndef EXCHANGEOBJECTMODIFIEDMESSAGE_H
#define EXCHANGEOBJECTMODIFIEDMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectModifiedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectModifiedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectModifiedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectModifiedMessage(FuncTree tree);
  ExchangeObjectModifiedMessage();

  QSharedPointer<ObjectItem> object;

private:
  void _objecttreeFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // EXCHANGEOBJECTMODIFIEDMESSAGE_H