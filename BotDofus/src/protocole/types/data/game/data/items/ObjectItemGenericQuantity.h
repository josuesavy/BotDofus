#ifndef OBJECTITEMGENERICQUANTITY_H
#define OBJECTITEMGENERICQUANTITY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/Item.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ObjectItemGenericQuantity : public Item
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemGenericQuantity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemGenericQuantity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemGenericQuantity(FuncTree tree);
  ObjectItemGenericQuantity();
  bool operator==(const ObjectItemGenericQuantity &compared);

  uint objectGID;
  uint quantity;

private:
  void _objectGIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // OBJECTITEMGENERICQUANTITY_H