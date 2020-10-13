#ifndef OBJECTITEMINROLEPLAY_H
#define OBJECTITEMINROLEPLAY_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectItemInRolePlay : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemInRolePlay(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemInRolePlay(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemInRolePlay(FuncTree tree);
  ObjectItemInRolePlay();
  bool operator==(const ObjectItemInRolePlay &compared);

  uint cellId;
  uint objectGID;

private:
  void _cellIdFunc(Reader *input);
  void _objectGIDFunc(Reader *input);
};

#endif // OBJECTITEMINROLEPLAY_H