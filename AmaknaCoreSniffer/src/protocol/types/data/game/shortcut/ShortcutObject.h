#ifndef SHORTCUTOBJECT_H
#define SHORTCUTOBJECT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/shortcut/Shortcut.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ShortcutObject : public Shortcut
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutObject(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutObject(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutObject(FuncTree tree);
  ShortcutObject();
  bool operator==(const ShortcutObject &compared);
};

#endif // SHORTCUTOBJECT_H