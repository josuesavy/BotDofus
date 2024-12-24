#ifndef SPELLFORPRESET_H
#define SPELLFORPRESET_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class SpellForPreset : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpellForPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpellForPreset(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpellForPreset(FuncTree tree);
  SpellForPreset();
  bool operator==(const SpellForPreset &compared);

  uint spellId;
  QList<int> shortcuts;

private:
  void _spellIdFunc(Reader *input);
  void _shortcutstreeFunc(Reader *input);
  void _shortcutsFunc(Reader *input);

  FuncTree _shortcutstree;
};

#endif // SPELLFORPRESET_H