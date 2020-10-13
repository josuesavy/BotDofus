#ifndef SHORTCUTOBJECTIDOLSPRESET_H
#define SHORTCUTOBJECTIDOLSPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutObject.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ShortcutObjectIdolsPreset : public ShortcutObject
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutObjectIdolsPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutObjectIdolsPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutObjectIdolsPreset(FuncTree tree);
  ShortcutObjectIdolsPreset();
  bool operator==(const ShortcutObjectIdolsPreset &compared);

  int presetId;

private:
  void _presetIdFunc(Reader *input);
};

#endif // SHORTCUTOBJECTIDOLSPRESET_H