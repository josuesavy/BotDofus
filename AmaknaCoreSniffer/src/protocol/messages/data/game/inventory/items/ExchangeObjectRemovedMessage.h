#ifndef EXCHANGEOBJECTREMOVEDMESSAGE_H
#define EXCHANGEOBJECTREMOVEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectRemovedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectRemovedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectRemovedMessage(FuncTree tree);
  ExchangeObjectRemovedMessage();

  uint objectUID;

private:
  void _objectUIDFunc(Reader *input);
};

#endif // EXCHANGEOBJECTREMOVEDMESSAGE_H