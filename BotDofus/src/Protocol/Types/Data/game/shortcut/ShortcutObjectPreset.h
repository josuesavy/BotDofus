#ifndef SHORTCUTOBJECTPRESET_H
#define SHORTCUTOBJECTPRESET_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/shortcut/ShortcutObject.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ShortcutObjectPreset : public ShortcutObject
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutObjectPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutObjectPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutObjectPreset(FuncTree tree);
  ShortcutObjectPreset();
  bool operator==(const ShortcutObjectPreset &compared);

  int presetId;

private:
  void _presetIdFunc(Reader *input);
};

#endif // SHORTCUTOBJECTPRESET_H