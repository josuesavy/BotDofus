#ifndef TAXCOLLECTORPRESET_H
#define TAXCOLLECTORPRESET_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/Uuid.h"
#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorOrderedSpell.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristics.h"
#include "src/utils/io/type/FuncTree.h"

class TaxCollectorPreset : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorPreset(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorPreset(FuncTree tree);
  TaxCollectorPreset();
  bool operator==(const TaxCollectorPreset &compared);

  Uuid presetId;
  QList<TaxCollectorOrderedSpell> spells;
  QSharedPointer<CharacterCharacteristics> characteristics;

private:
  void _presetIdtreeFunc(Reader *input);
  void _spellstreeFunc(Reader *input);
  void _spellsFunc(Reader *input);
  void _characteristicstreeFunc(Reader *input);

  FuncTree _presetIdtree;
  FuncTree _spellstree;
  FuncTree _characteristicstree;
};

#endif // TAXCOLLECTORPRESET_H