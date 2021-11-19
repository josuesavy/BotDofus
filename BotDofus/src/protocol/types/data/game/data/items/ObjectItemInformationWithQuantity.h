#ifndef OBJECTITEMINFORMATIONWITHQUANTITY_H
#define OBJECTITEMINFORMATIONWITHQUANTITY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/ObjectItemMinimalInformation.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ObjectItemInformationWithQuantity : public ObjectItemMinimalInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemInformationWithQuantity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemInformationWithQuantity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemInformationWithQuantity(FuncTree tree);
  ObjectItemInformationWithQuantity();
  bool operator==(const ObjectItemInformationWithQuantity &compared);

  uint quantity;

private:
  void _quantityFunc(Reader *input);
};

#endif // OBJECTITEMINFORMATIONWITHQUANTITY_H