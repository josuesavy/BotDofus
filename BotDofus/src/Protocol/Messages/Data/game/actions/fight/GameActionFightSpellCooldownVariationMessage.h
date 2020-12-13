#ifndef GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE_H
#define GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightSpellCooldownVariationMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightSpellCooldownVariationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightSpellCooldownVariationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightSpellCooldownVariationMessage(FuncTree tree);
  GameActionFightSpellCooldownVariationMessage();

  double targetId;
  uint spellId;
  int value;

private:
  void _targetIdFunc(Reader *input);
  void _spellIdFunc(Reader *input);
  void _valueFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE_H