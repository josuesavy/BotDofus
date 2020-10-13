#ifndef OBJECTITEMTOSELLINHUMANVENDORSHOP_H
#define OBJECTITEMTOSELLINHUMANVENDORSHOP_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Protocol/Types/Data/game/data/items/Item.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectItemToSellInHumanVendorShop : public Item
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemToSellInHumanVendorShop(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemToSellInHumanVendorShop(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemToSellInHumanVendorShop(FuncTree tree);
  void _publicPriceFunc(Reader *input);
  ObjectItemToSellInHumanVendorShop();
  bool operator==(const ObjectItemToSellInHumanVendorShop &compared);

  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;
  uint objectUID;
  uint quantity;
  double objectPrice;
  double publicPrice;

private:
  void _objectGIDFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
  void _objectPriceFunc(Reader *input);

  FuncTree _effectstree;
};

#endif // OBJECTITEMTOSELLINHUMANVENDORSHOP_H