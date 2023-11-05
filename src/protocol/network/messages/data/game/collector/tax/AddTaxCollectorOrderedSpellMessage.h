#ifndef ADDTAXCOLLECTORORDEREDSPELLMESSAGE_H
#define ADDTAXCOLLECTORORDEREDSPELLMESSAGE_H

#include "src/protocol/types/data/game/collector/tax/TaxCollectorOrderedSpell.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AddTaxCollectorOrderedSpellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AddTaxCollectorOrderedSpellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AddTaxCollectorOrderedSpellMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AddTaxCollectorOrderedSpellMessage(FuncTree tree);
  AddTaxCollectorOrderedSpellMessage();

  double taxCollectorId;
  TaxCollectorOrderedSpell spell;

private:
  void _taxCollectorIdFunc(Reader *input);
  void _spelltreeFunc(Reader *input);

  FuncTree _spelltree;
};

#endif // ADDTAXCOLLECTORORDEREDSPELLMESSAGE_H