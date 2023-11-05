#ifndef ITEM_H
#define ITEM_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class Item : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_Item(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_Item(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_Item(FuncTree tree);
  Item();
  bool operator==(const Item &compared);
};

#endif // ITEM_H