#ifndef UPDATESPELLMODIFIERMESSAGE_H
#define UPDATESPELLMODIFIERMESSAGE_H

#include "src/protocol/types/data/game/character/characteristic/CharacterSpellModification.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class UpdateSpellModifierMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateSpellModifierMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateSpellModifierMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateSpellModifierMessage(FuncTree tree);
  UpdateSpellModifierMessage();

  double actorId;
  QSharedPointer<CharacterSpellModification> spellModifier;

private:
  void _actorIdFunc(Reader *input);
  void _spellModifiertreeFunc(Reader *input);

  FuncTree _spellModifiertree;
};

#endif // UPDATESPELLMODIFIERMESSAGE_H