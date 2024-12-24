#ifndef OBJECTITEMNOTINCONTAINER_H
#define OBJECTITEMNOTINCONTAINER_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/protocol/network/types/data/game/data/items/Item.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class ObjectItemNotInContainer : public Item
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemNotInContainer(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemNotInContainer(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemNotInContainer(FuncTree tree);
  ObjectItemNotInContainer();
  bool operator==(const ObjectItemNotInContainer &compared);

  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;
  uint objectUID;
  uint quantity;

private:
  void _objectGIDFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);

  FuncTree _effectstree;
};

#endif // OBJECTITEMNOTINCONTAINER_H