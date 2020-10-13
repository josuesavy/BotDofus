#ifndef OBJECTITEMTOSELLINNPCSHOP_H
#define OBJECTITEMTOSELLINNPCSHOP_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/ObjectItemMinimalInformation.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectItemToSellInNpcShop : public ObjectItemMinimalInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemToSellInNpcShop(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemToSellInNpcShop(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemToSellInNpcShop(FuncTree tree);
  ObjectItemToSellInNpcShop();
  bool operator==(const ObjectItemToSellInNpcShop &compared);

  double objectPrice;
  QString buyCriterion;

private:
  void _objectPriceFunc(Reader *input);
  void _buyCriterionFunc(Reader *input);
};

#endif // OBJECTITEMTOSELLINNPCSHOP_H