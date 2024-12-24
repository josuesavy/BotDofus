#ifndef FORGETTABLESPELLCLIENTACTIONMESSAGE_H
#define FORGETTABLESPELLCLIENTACTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ForgettableSpellClientActionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ForgettableSpellClientActionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ForgettableSpellClientActionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ForgettableSpellClientActionMessage(FuncTree tree);
  ForgettableSpellClientActionMessage();

  uint spellId;
  uint action;

private:
  void _spellIdFunc(Reader *input);
  void _actionFunc(Reader *input);
};

#endif // FORGETTABLESPELLCLIENTACTIONMESSAGE_H