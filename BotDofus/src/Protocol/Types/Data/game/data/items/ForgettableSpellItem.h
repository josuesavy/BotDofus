#ifndef FORGETTABLESPELLITEM_H
#define FORGETTABLESPELLITEM_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/SpellItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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