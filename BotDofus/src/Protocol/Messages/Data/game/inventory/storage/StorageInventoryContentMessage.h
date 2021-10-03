#ifndef STORAGEINVENTORYCONTENTMESSAGE_H
#define STORAGEINVENTORYCONTENTMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/items/InventoryContentMessage.h"

class StorageInventoryContentMessage : public InventoryContentMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StorageInventoryContentMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StorageInventoryContentMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StorageInventoryContentMessage(FuncTree tree);
  StorageInventoryContentMessage();
};

#endif // STORAGEINVENTORYCONTENTMESSAGE_H