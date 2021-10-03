#ifndef EXCHANGEMOUNTSSTABLEBORNADDMESSAGE_H
#define EXCHANGEMOUNTSSTABLEBORNADDMESSAGE_H

#include "src/protocol/types/data/game/mount/MountClientData.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeMountsStableAddMessage.h"

class ExchangeMountsStableBornAddMessage : public ExchangeMountsStableAddMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMountsStableBornAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMountsStableBornAddMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMountsStableBornAddMessage(FuncTree tree);
  ExchangeMountsStableBornAddMessage();
};

#endif // EXCHANGEMOUNTSSTABLEBORNADDMESSAGE_H