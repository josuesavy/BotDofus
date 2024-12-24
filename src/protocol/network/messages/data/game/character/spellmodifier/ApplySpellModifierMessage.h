#ifndef APPLYSPELLMODIFIERMESSAGE_H
#define APPLYSPELLMODIFIERMESSAGE_H

#include "src/protocol/network/types/data/game/character/spellmodifier/SpellModifierMessage.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ApplySpellModifierMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ApplySpellModifierMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ApplySpellModifierMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ApplySpellModifierMessage(FuncTree tree);
  ApplySpellModifierMessage();

  double actorId;
  SpellModifierMessage modifier;

private:
  void _actorIdFunc(Reader *input);
  void _modifiertreeFunc(Reader *input);

  FuncTree _modifiertree;
};

#endif // APPLYSPELLMODIFIERMESSAGE_H