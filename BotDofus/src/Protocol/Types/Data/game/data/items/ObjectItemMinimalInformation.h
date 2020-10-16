#ifndef OBJECTITEMMINIMALINFORMATION_H
#define OBJECTITEMMINIMALINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Protocol/Types/Data/game/data/items/Item.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectItemMinimalInformation : public Item
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemMinimalInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemMinimalInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemMinimalInformation(FuncTree tree);
  ObjectItemMinimalInformation();
  bool operator==(const ObjectItemMinimalInformation &compared);

  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;

private:
  void _objectGIDFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);

  FuncTree _effectstree;
};

#endif // OBJECTITEMMINIMALINFORMATION_H