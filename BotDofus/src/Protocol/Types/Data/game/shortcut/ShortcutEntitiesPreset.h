#ifndef SHORTCUTENTITIESPRESET_H
#define SHORTCUTENTITIESPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/shortcut/Shortcut.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ShortcutEntitiesPreset : public Shortcut
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShortcutEntitiesPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShortcutEntitiesPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShortcutEntitiesPreset(FuncTree tree);
  ShortcutEntitiesPreset();
  bool operator==(const ShortcutEntitiesPreset &compared);

  int presetId;

private:
  void _presetIdFunc(Reader *input);
};

#endif // SHORTCUTENTITIESPRESET_H