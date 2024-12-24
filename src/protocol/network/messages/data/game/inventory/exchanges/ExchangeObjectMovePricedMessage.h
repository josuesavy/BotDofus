#ifndef EXCHANGEOBJECTMOVEPRICEDMESSAGE_H
#define EXCHANGEOBJECTMOVEPRICEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeObjectMoveMessage.h"

class ExchangeObjectMovePricedMessage : public ExchangeObjectMoveMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectMovePricedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectMovePricedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectMovePricedMessage(FuncTree tree);
  ExchangeObjectMovePricedMessage();

  double price;

private:
  void _priceFunc(Reader *input);
};

#endif // EXCHANGEOBJECTMOVEPRICEDMESSAGE_H