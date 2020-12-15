#ifndef EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE_H
#define EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectRemovedFromBagMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectRemovedFromBagMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectRemovedFromBagMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectRemovedFromBagMessage(FuncTree tree);
  ExchangeObjectRemovedFromBagMessage();

  uint objectUID;

private:
  void _objectUIDFunc(Reader *input);
};

#endif // EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE_H