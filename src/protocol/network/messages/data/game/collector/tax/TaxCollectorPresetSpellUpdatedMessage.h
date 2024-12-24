#ifndef TAXCOLLECTORPRESETSPELLUPDATEDMESSAGE_H
#define TAXCOLLECTORPRESETSPELLUPDATEDMESSAGE_H

#include "src/protocol/network/types/data/game/Uuid.h"
#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorOrderedSpell.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TaxCollectorPresetSpellUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorPresetSpellUpdatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorPresetSpellUpdatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorPresetSpellUpdatedMessage(FuncTree tree);
  TaxCollectorPresetSpellUpdatedMessage();

  Uuid presetId;
  QList<TaxCollectorOrderedSpell> taxCollectorSpells;

private:
  void _presetIdtreeFunc(Reader *input);
  void _taxCollectorSpellstreeFunc(Reader *input);
  void _taxCollectorSpellsFunc(Reader *input);

  FuncTree _presetIdtree;
  FuncTree _taxCollectorSpellstree;
};

#endif // TAXCOLLECTORPRESETSPELLUPDATEDMESSAGE_H