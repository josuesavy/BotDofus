#ifndef EXCHANGEOBJECTMODIFYPRICEDMESSAGE_H
#define EXCHANGEOBJECTMODIFYPRICEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeObjectMovePricedMessage.h"

class ExchangeObjectModifyPricedMessage : public ExchangeObjectMovePricedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectModifyPricedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectModifyPricedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectModifyPricedMessage(FuncTree tree);
  ExchangeObjectModifyPricedMessage();
};

#endif // EXCHANGEOBJECTMODIFYPRICEDMESSAGE_H