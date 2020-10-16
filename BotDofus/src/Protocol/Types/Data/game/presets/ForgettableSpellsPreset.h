#ifndef FORGETTABLESPELLSPRESET_H
#define FORGETTABLESPELLSPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/SpellsPreset.h"
#include "src/Protocol/Types/Data/game/presets/SpellForPreset.h"
#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ForgettableSpellsPreset : public Preset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ForgettableSpellsPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ForgettableSpellsPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ForgettableSpellsPreset(FuncTree tree);
  ForgettableSpellsPreset();
  bool operator==(const ForgettableSpellsPreset &compared);

  QSharedPointer<SpellsPreset> baseSpellsPreset;
  QList<SpellForPreset> forgettableSpells;

private:
  void _baseSpellsPresettreeFunc(Reader *input);
  void _forgettableSpellstreeFunc(Reader *input);
  void _forgettableSpellsFunc(Reader *input);

  FuncTree _baseSpellsPresettree;
  FuncTree _forgettableSpellstree;
};

#endif // FORGETTABLESPELLSPRESET_H