#ifndef OBJECTITEMQUANTITYPRICEDATEEFFECTS_H
#define OBJECTITEMQUANTITYPRICEDATEEFFECTS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/ObjectEffects.h"
#include "src/Protocol/Types/Data/game/data/items/ObjectItemGenericQuantity.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectItemQuantityPriceDateEffects : public ObjectItemGenericQuantity
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemQuantityPriceDateEffects(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemQuantityPriceDateEffects(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemQuantityPriceDateEffects(FuncTree tree);
  ObjectItemQuantityPriceDateEffects();
  bool operator==(const ObjectItemQuantityPriceDateEffects &compared);

  double price;
  QSharedPointer<ObjectEffects> effects;
  uint date;

private:
  void _priceFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _dateFunc(Reader *input);

  FuncTree _effectstree;
};

#endif // OBJECTITEMQUANTITYPRICEDATEEFFECTS_H