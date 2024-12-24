#ifndef FORGETTABLESPELLITEM_H
#define FORGETTABLESPELLITEM_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/SpellItem.h"
#include "src/utils/io/type/FuncTree.h"

class ForgettableSpellItem : public SpellItem
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ForgettableSpellItem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ForgettableSpellItem(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ForgettableSpellItem(FuncTree tree);
  ForgettableSpellItem();
  bool operator==(const ForgettableSpellItem &compared);

  bool available;

private:
  void _availableFunc(Reader *input);
};

#endif // FORGETTABLESPELLITEM_H