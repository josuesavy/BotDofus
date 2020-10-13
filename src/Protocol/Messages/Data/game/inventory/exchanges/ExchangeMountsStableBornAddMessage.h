#ifndef EXCHANGEMOUNTSSTABLEBORNADDMESSAGE_H
#define EXCHANGEMOUNTSSTABLEBORNADDMESSAGE_H

#include "src/Protocol/Types/Data/game/mount/MountClientData.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeMountsStableAddMessage.h"

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