#ifndef EXCHANGEOBJECTMODIFYPRICEDMESSAGE_H
#define EXCHANGEOBJECTMODIFYPRICEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeObjectMovePricedMessage.h"

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