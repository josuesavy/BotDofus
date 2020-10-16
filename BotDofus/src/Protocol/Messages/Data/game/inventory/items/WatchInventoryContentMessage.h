#ifndef WATCHINVENTORYCONTENTMESSAGE_H
#define WATCHINVENTORYCONTENTMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/InventoryContentMessage.h"

class WatchInventoryContentMessage : public InventoryContentMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_WatchInventoryContentMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_WatchInventoryContentMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_WatchInventoryContentMessage(FuncTree tree);
  WatchInventoryContentMessage();
};

#endif // WATCHINVENTORYCONTENTMESSAGE_H