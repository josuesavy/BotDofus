#ifndef TAXCOLLECTORORDEREDSPELLUPDATEDMESSAGE_H
#define TAXCOLLECTORORDEREDSPELLUPDATEDMESSAGE_H

#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorOrderedSpell.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TaxCollectorOrderedSpellUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorOrderedSpellUpdatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorOrderedSpellUpdatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorOrderedSpellUpdatedMessage(FuncTree tree);
  TaxCollectorOrderedSpellUpdatedMessage();

  double taxCollectorId;
  QList<TaxCollectorOrderedSpell> taxCollectorSpells;

private:
  void _taxCollectorIdFunc(Reader *input);
  void _taxCollectorSpellstreeFunc(Reader *input);
  void _taxCollectorSpellsFunc(Reader *input);

  FuncTree _taxCollectorSpellstree;
};

#endif // TAXCOLLECTORORDEREDSPELLUPDATEDMESSAGE_H