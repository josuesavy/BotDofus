#ifndef OBJECTITEMQUANTITY_H
#define OBJECTITEMQUANTITY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/Item.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ObjectItemQuantity : public Item
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemQuantity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemQuantity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemQuantity(FuncTree tree);
  ObjectItemQuantity();
  bool operator==(const ObjectItemQuantity &compared);

  uint objectUID;
  uint quantity;

private:
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // OBJECTITEMQUANTITY_H