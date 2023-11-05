#ifndef FORGETTABLESPELLSPRESET_H
#define FORGETTABLESPELLSPRESET_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/presets/Preset.h"
#include "src/engines/io/network/utils/FuncTree.h"

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

   baseSpellsPreset;
  QList<> forgettableSpells;

private:
  void _baseSpellsPresettreeFunc(Reader *input);
  void _forgettableSpellstreeFunc(Reader *input);
  void _forgettableSpellsFunc(Reader *input);

  FuncTree _baseSpellsPresettree;
  FuncTree _forgettableSpellstree;
};

#endif // FORGETTABLESPELLSPRESET_H