#ifndef INVENTORYCONTENTMESSAGE_H
#define INVENTORYCONTENTMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class InventoryContentMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InventoryContentMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InventoryContentMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InventoryContentMessage(FuncTree tree);
  InventoryContentMessage();

  QList<QSharedPointer<ObjectItem>> objects;
  double kamas;

private:
  void _objectstreeFunc(Reader *input);
  void _objectsFunc(Reader *input);
  void _kamasFunc(Reader *input);

  FuncTree _objectstree;
};

#endif // INVENTORYCONTENTMESSAGE_H