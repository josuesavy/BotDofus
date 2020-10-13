#ifndef INVENTORYWEIGHTMESSAGE_H
#define INVENTORYWEIGHTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
  uint shopWeight;
  uint weightMax;

private:
  void _inventoryWeightFunc(Reader *input);
  void _shopWeightFunc(Reader *input);
  void _weightMaxFunc(Reader *input);
};

#endif // INVENTORYWEIGHTMESSAGE_H