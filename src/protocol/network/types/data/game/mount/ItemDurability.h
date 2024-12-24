#ifndef ITEMDURABILITY_H
#define ITEMDURABILITY_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class ItemDurability : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ItemDurability(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ItemDurability(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ItemDurability(FuncTree tree);
  ItemDurability();
  bool operator==(const ItemDurability &compared);

  int durability;
  int durabilityMax;

private:
  void _durabilityFunc(Reader *input);
  void _durabilityMaxFunc(Reader *input);
};

#endif // ITEMDURABILITY_H