#ifndef EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE_H
#define EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE_H

#include "src/protocol/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeBidHouseInListAddedMessage.h"

class ExchangeBidHouseInListUpdatedMessage : public ExchangeBidHouseInListAddedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseInListUpdatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseInListUpdatedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseInListUpdatedMessage(FuncTree tree);
  ExchangeBidHouseInListUpdatedMessage();
};

#endif // EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE_H