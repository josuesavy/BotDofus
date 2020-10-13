#ifndef SHORTCUTSPELL_H
#define SHORTCUTSPELL_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/shortcut/Shortcut.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ShortcutSpell : public Shortcut
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutSpell(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutSpell(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutSpell(FuncTree tree);
  ShortcutSpell();
  bool operator==(const ShortcutSpell &compared);

  uint spellId;

private:
  void _spellIdFunc(Reader *input);
};

#endif // SHORTCUTSPELL_H