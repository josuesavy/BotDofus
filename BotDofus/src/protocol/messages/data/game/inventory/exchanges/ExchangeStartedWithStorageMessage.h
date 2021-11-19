#ifndef EXCHANGESTARTEDWITHSTORAGEMESSAGE_H
#define EXCHANGESTARTEDWITHSTORAGEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeStartedMessage.h"

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