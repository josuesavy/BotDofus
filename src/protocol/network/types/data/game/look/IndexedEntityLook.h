#ifndef INDEXEDENTITYLOOK_H
#define INDEXEDENTITYLOOK_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"

class IndexedEntityLook : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IndexedEntityLook(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IndexedEntityLook(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IndexedEntityLook(FuncTree tree);
  IndexedEntityLook();
  bool operator==(const IndexedEntityLook &compared);

  QSharedPointer<EntityLook> look;
  uint index;

private:
  void _looktreeFunc(Reader *input);
  void _indexFunc(Reader *input);

  FuncTree _looktree;
};

#endif // INDEXEDENTITYLOOK_H