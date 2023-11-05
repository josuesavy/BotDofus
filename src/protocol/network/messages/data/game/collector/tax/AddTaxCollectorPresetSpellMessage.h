#ifndef ADDTAXCOLLECTORPRESETSPELLMESSAGE_H
#define ADDTAXCOLLECTORPRESETSPELLMESSAGE_H

#include "src/protocol/types/data/game/collector/tax/TaxCollectorOrderedSpell.h"
#include "src/protocol/types/data/game/uuid.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AddTaxCollectorPresetSpellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AddTaxCollectorPresetSpellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AddTaxCollectorPresetSpellMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AddTaxCollectorPresetSpellMessage(FuncTree tree);
  AddTaxCollectorPresetSpellMessage();

  uuid presetId;
  TaxCollectorOrderedSpell spell;

private:
  void _presetIdtreeFunc(Reader *input);
  void _spelltreeFunc(Reader *input);

  FuncTree _presetIdtree;
  FuncTree _spelltree;
};

#endif // ADDTAXCOLLECTORPRESETSPELLMESSAGE_H