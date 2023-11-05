#ifndef INVENTORYWEIGHTMESSAGE_H
#define INVENTORYWEIGHTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class InventoryWeightMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InventoryWeightMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InventoryWeightMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InventoryWeightMessage(FuncTree tree);
  InventoryWeightMessage();

  uint inventoryWeight;
  uint weightMax;

private:
  void _inventoryWeightFunc(Reader *input);
  void _weightMaxFunc(Reader *input);
};

#endif // INVENTORYWEIGHTMESSAGE_H