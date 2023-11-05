#ifndef PADDOCKITEM_H
#define PADDOCKITEM_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/mount/ItemDurability.h"
#include "src/protocol/types/data/game/context/roleplay/ObjectItemInRolePlay.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PaddockItem : public ObjectItemInRolePlay
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockItem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockItem(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockItem(FuncTree tree);
  PaddockItem();
  bool operator==(const PaddockItem &compared);

  ItemDurability durability;

private:
  void _durabilitytreeFunc(Reader *input);

  FuncTree _durabilitytree;
};

#endif // PADDOCKITEM_H