#ifndef SUBENTITY_H
#define SUBENTITY_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class EntityLook;

class SubEntity : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SubEntity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SubEntity(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SubEntity(FuncTree tree);
  SubEntity();
  bool operator==(const SubEntity &compared);

  uint bindingPointCategory;
  uint bindingPointIndex;
  QSharedPointer<EntityLook> subEntityLook;

private:
  void _bindingPointCategoryFunc(Reader *input);
  void _bindingPointIndexFunc(Reader *input);
  void _subEntityLooktreeFunc(Reader *input);

  FuncTree _subEntityLooktree;
};

#endif // SUBENTITY_H