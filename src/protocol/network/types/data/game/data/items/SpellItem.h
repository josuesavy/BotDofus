#ifndef SPELLITEM_H
#define SPELLITEM_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/Item.h"
#include "src/utils/io/type/FuncTree.h"

class SpellItem : public Item
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpellItem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpellItem(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpellItem(FuncTree tree);
  SpellItem();
  bool operator==(const SpellItem &compared);

  int spellId;
  int spellLevel;

private:
  void _spellIdFunc(Reader *input);
  void _spellLevelFunc(Reader *input);
};

#endif // SPELLITEM_H