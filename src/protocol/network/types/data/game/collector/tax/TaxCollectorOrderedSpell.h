#ifndef TAXCOLLECTORORDEREDSPELL_H
#define TAXCOLLECTORORDEREDSPELL_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class TaxCollectorOrderedSpell : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorOrderedSpell(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorOrderedSpell(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorOrderedSpell(FuncTree tree);
  TaxCollectorOrderedSpell();
  bool operator==(const TaxCollectorOrderedSpell &compared);

  uint spellId;
  uint slot;

private:
  void _spellIdFunc(Reader *input);
  void _slotFunc(Reader *input);
};

#endif // TAXCOLLECTORORDEREDSPELL_H