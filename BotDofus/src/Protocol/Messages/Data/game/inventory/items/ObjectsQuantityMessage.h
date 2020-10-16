#ifndef OBJECTSQUANTITYMESSAGE_H
#define OBJECTSQUANTITYMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItemQuantity.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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