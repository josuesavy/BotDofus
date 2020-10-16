#ifndef EXCHANGESTARTEDWITHSTORAGEMESSAGE_H
#define EXCHANGESTARTEDWITHSTORAGEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeStartedMessage.h"

class ExchangeStartedWithStorageMessage : public ExchangeStartedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartedWithStorageMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartedWithStorageMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartedWithStorageMessage(FuncTree tree);
  ExchangeStartedWithStorageMessage();

  uint storageMaxSlot;

private:
  void _storageMaxSlotFunc(Reader *input);
};

#endif // EXCHANGESTARTEDWITHSTORAGEMESSAGE_H