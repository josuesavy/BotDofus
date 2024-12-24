#ifndef REMOVETAXCOLLECTORORDEREDSPELLMESSAGE_H
#define REMOVETAXCOLLECTORORDEREDSPELLMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class RemoveTaxCollectorOrderedSpellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RemoveTaxCollectorOrderedSpellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RemoveTaxCollectorOrderedSpellMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RemoveTaxCollectorOrderedSpellMessage(FuncTree tree);
  RemoveTaxCollectorOrderedSpellMessage();

  double taxCollectorId;
  uint slot;

private:
  void _taxCollectorIdFunc(Reader *input);
  void _slotFunc(Reader *input);
};

#endif // REMOVETAXCOLLECTORORDEREDSPELLMESSAGE_H