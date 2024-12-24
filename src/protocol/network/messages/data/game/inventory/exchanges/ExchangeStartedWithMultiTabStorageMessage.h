#ifndef EXCHANGESTARTEDWITHMULTITABSTORAGEMESSAGE_H
#define EXCHANGESTARTEDWITHMULTITABSTORAGEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeStartedMessage.h"

class ExchangeStartedWithMultiTabStorageMessage : public ExchangeStartedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartedWithMultiTabStorageMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartedWithMultiTabStorageMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartedWithMultiTabStorageMessage(FuncTree tree);
  ExchangeStartedWithMultiTabStorageMessage();

  uint storageMaxSlot;
  uint tabNumber;

private:
  void _storageMaxSlotFunc(Reader *input);
  void _tabNumberFunc(Reader *input);
};

#endif // EXCHANGESTARTEDWITHMULTITABSTORAGEMESSAGE_H