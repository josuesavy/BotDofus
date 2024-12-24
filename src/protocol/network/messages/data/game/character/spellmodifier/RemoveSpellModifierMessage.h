#ifndef REMOVESPELLMODIFIERMESSAGE_H
#define REMOVESPELLMODIFIERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class RemoveSpellModifierMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RemoveSpellModifierMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RemoveSpellModifierMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RemoveSpellModifierMessage(FuncTree tree);
  RemoveSpellModifierMessage();

  double actorId;
  uint actionType;
  uint modifierType;
  uint spellId;

private:
  void _actorIdFunc(Reader *input);
  void _actionTypeFunc(Reader *input);
  void _modifierTypeFunc(Reader *input);
  void _spellIdFunc(Reader *input);
};

#endif // REMOVESPELLMODIFIERMESSAGE_H