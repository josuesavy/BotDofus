#ifndef SHORTCUTEMOTE_H
#define SHORTCUTEMOTE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/shortcut/Shortcut.h"
#include "src/utils/io/type/FuncTree.h"

class ShortcutEmote : public Shortcut
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutEmote(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutEmote(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutEmote(FuncTree tree);
  ShortcutEmote();
  bool operator==(const ShortcutEmote &compared);

  uint emoteId;

private:
  void _emoteIdFunc(Reader *input);
};

#endif // SHORTCUTEMOTE_H