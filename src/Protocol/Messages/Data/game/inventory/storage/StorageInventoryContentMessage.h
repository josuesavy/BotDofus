#ifndef STORAGEINVENTORYCONTENTMESSAGE_H
#define STORAGEINVENTORYCONTENTMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/InventoryContentMessage.h"

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