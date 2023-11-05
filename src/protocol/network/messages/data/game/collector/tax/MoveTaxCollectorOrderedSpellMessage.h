#ifndef MOVETAXCOLLECTORORDEREDSPELLMESSAGE_H
#define MOVETAXCOLLECTORORDEREDSPELLMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MoveTaxCollectorOrderedSpellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MoveTaxCollectorOrderedSpellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MoveTaxCollectorOrderedSpellMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MoveTaxCollectorOrderedSpellMessage(FuncTree tree);
  MoveTaxCollectorOrderedSpellMessage();

  double taxCollectorId;
  uint movedFrom;
  uint movedTo;

private:
  void _taxCollectorIdFunc(Reader *input);
  void _movedFromFunc(Reader *input);
  void _movedToFunc(Reader *input);
};

#endif // MOVETAXCOLLECTORORDEREDSPELLMESSAGE_H