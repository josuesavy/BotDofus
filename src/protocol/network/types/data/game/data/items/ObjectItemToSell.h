#ifndef OBJECTITEMTOSELL_H
#define OBJECTITEMTOSELL_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/protocol/types/data/game/data/items/Item.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

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