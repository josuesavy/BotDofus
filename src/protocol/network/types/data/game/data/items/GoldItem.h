#ifndef GOLDITEM_H
#define GOLDITEM_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/Item.h"
#include "src/utils/io/type/FuncTree.h"

class GoldItem : public Item
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GoldItem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GoldItem(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GoldItem(FuncTree tree);
  GoldItem();
  bool operator==(const GoldItem &compared);

  double sum;

private:
  void _sumFunc(Reader *input);
};

#endif // GOLDITEM_H