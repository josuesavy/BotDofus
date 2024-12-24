#ifndef FORGETTABLESPELLDELETEMESSAGE_H
#define FORGETTABLESPELLDELETEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ForgettableSpellDeleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ForgettableSpellDeleteMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ForgettableSpellDeleteMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ForgettableSpellDeleteMessage(FuncTree tree);
  ForgettableSpellDeleteMessage();

  uint reason;
  QList<uint> spells;

private:
  void _reasonFunc(Reader *input);
  void _spellstreeFunc(Reader *input);
  void _spellsFunc(Reader *input);

  FuncTree _spellstree;
};

#endif // FORGETTABLESPELLDELETEMESSAGE_H