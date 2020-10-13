#ifndef SPELLSPRESET_H
#define SPELLSPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/SpellForPreset.h"
#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class SpellsPreset : public Preset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpellsPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpellsPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpellsPreset(FuncTree tree);
  SpellsPreset();
  bool operator==(const SpellsPreset &compared);

  QList<SpellForPreset> spells;

private:
  void _spellstreeFunc(Reader *input);
  void _spellsFunc(Reader *input);

  FuncTree _spellstree;
};

#endif // SPELLSPRESET_H