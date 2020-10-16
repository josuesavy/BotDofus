#ifndef OBJECTITEMINFORMATIONWITHQUANTITY_H
#define OBJECTITEMINFORMATIONWITHQUANTITY_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/ObjectItemMinimalInformation.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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