#ifndef EXCHANGEOBJECTMOVEMESSAGE_H
#define EXCHANGEOBJECTMOVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeObjectMoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectMoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectMoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectMoveMessage(FuncTree tree);
  ExchangeObjectMoveMessage();

  uint objectUID;
  int quantity;

private:
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // EXCHANGEOBJECTMOVEMESSAGE_H