#ifndef OBJECTITEMQUANTITYPRICEDATEEFFECTS_H
#define OBJECTITEMQUANTITYPRICEDATEEFFECTS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/ObjectItemGenericQuantity.h"
#include "src/engines/io/network/utils/FuncTree.h"

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
   effects;
  uint date;

private:
  void _priceFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _dateFunc(Reader *input);

  FuncTree _effectstree;
};

#endif // OBJECTITEMQUANTITYPRICEDATEEFFECTS_H