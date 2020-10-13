#ifndef SHORTCUTOBJECT_H
#define SHORTCUTOBJECT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/shortcut/Shortcut.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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