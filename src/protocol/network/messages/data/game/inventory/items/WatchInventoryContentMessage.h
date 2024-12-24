#ifndef WATCHINVENTORYCONTENTMESSAGE_H
#define WATCHINVENTORYCONTENTMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/items/InventoryContentMessage.h"

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