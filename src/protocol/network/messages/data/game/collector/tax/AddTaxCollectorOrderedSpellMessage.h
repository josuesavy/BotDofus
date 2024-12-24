#ifndef ADDTAXCOLLECTORORDEREDSPELLMESSAGE_H
#define ADDTAXCOLLECTORORDEREDSPELLMESSAGE_H

#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorOrderedSpell.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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