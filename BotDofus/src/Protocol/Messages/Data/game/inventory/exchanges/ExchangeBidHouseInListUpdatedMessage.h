#ifndef EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE_H
#define EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeBidHouseInListAddedMessage.h"

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