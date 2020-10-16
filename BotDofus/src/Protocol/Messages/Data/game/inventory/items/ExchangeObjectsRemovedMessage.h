#ifndef EXCHANGEOBJECTSREMOVEDMESSAGE_H
#define EXCHANGEOBJECTSREMOVEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeObjectsRemovedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectsRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectsRemovedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectsRemovedMessage(FuncTree tree);
  ExchangeObjectsRemovedMessage();

  QList<uint> objectUID;

private:
  void _objectUIDtreeFunc(Reader *input);
  void _objectUIDFunc(Reader *input);

  FuncTree _objectUIDtree;
};

#endif // EXCHANGEOBJECTSREMOVEDMESSAGE_H