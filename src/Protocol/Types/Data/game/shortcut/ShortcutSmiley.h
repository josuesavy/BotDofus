#ifndef SHORTCUTSMILEY_H
#define SHORTCUTSMILEY_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/shortcut/Shortcut.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ShortcutSmiley : public Shortcut
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutSmiley(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutSmiley(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutSmiley(FuncTree tree);
  ShortcutSmiley();
  bool operator==(const ShortcutSmiley &compared);

  uint smileyId;

private:
  void _smileyIdFunc(Reader *input);
};

#endif // SHORTCUTSMILEY_H