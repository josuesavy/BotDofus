#ifndef TAXCOLLECTORPRESET_H
#define TAXCOLLECTORPRESET_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/uuid.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristics.h"
#include "src/engines/io/network/utils/FuncTree.h"

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

  uuid presetId;
  QList<> spells;
  CharacterCharacteristics characteristics;

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