#ifndef OBJECTITEMTOSELL_H
#define OBJECTITEMTOSELL_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Protocol/Types/Data/game/data/items/Item.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectItemToSell : public Item
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemToSell(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemToSell(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemToSell(FuncTree tree);
  ObjectItemToSell();
  bool operator==(const ObjectItemToSell &compared);

  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;
  uint objectUID;
  uint quantity;
  double objectPrice;

private:
  void _objectGIDFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
  void _objectPriceFunc(Reader *input);

  FuncTree _effectstree;
};

#endif // OBJECTITEMTOSELL_H