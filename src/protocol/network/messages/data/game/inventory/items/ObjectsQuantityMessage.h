#ifndef OBJECTSQUANTITYMESSAGE_H
#define OBJECTSQUANTITYMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItemQuantity.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ObjectsQuantityMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectsQuantityMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectsQuantityMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectsQuantityMessage(FuncTree tree);
  ObjectsQuantityMessage();

  QList<ObjectItemQuantity> objectsUIDAndQty;

private:
  void _objectsUIDAndQtytreeFunc(Reader *input);
  void _objectsUIDAndQtyFunc(Reader *input);

  FuncTree _objectsUIDAndQtytree;
};

#endif // OBJECTSQUANTITYMESSAGE_H