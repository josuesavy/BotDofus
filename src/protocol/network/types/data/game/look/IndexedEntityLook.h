#ifndef INDEXEDENTITYLOOK_H
#define INDEXEDENTITYLOOK_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

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

   look;
  uint index;

private:
  void _looktreeFunc(Reader *input);
  void _indexFunc(Reader *input);

  FuncTree _looktree;
};

#endif // INDEXEDENTITYLOOK_H