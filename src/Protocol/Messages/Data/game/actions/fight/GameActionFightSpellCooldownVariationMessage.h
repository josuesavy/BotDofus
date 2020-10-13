#ifndef GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE_H
#define GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

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