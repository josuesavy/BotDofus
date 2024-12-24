#ifndef OBJECTITEM_H
#define OBJECTITEM_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/protocol/network/types/data/game/data/items/Item.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class ObjectItem : public Item
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItem(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItem(FuncTree tree);
  ObjectItem();
  bool operator==(const ObjectItem &compared);

  uint position;
  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;
  uint objectUID;
  uint quantity;
  bool favorite;

private:
  void _positionFunc(Reader *input);
  void _objectGIDFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
  void _favoriteFunc(Reader *input);

  FuncTree _effectstree;
};

#endif // OBJECTITEM_H