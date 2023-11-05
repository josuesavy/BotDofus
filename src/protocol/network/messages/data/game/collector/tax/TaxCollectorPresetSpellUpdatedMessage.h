#ifndef TAXCOLLECTORPRESETSPELLUPDATEDMESSAGE_H
#define TAXCOLLECTORPRESETSPELLUPDATEDMESSAGE_H

#include "src/protocol/types/data/game/collector/tax/TaxCollectorOrderedSpell.h"
#include "src/protocol/types/data/game/uuid.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  uuid presetId;
  QList<TaxCollectorOrderedSpell> taxCollectorSpells;

private:
  void _presetIdtreeFunc(Reader *input);
  void _taxCollectorSpellstreeFunc(Reader *input);
  void _taxCollectorSpellsFunc(Reader *input);

  FuncTree _presetIdtree;
  FuncTree _taxCollectorSpellstree;
};

#endif // TAXCOLLECTORPRESETSPELLUPDATEDMESSAGE_H