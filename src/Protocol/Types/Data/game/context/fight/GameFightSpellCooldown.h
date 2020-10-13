#ifndef GAMEFIGHTSPELLCOOLDOWN_H
#define GAMEFIGHTSPELLCOOLDOWN_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameFightSpellCooldown : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightSpellCooldown(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightSpellCooldown(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightSpellCooldown(FuncTree tree);
  GameFightSpellCooldown();
  bool operator==(const GameFightSpellCooldown &compared);

  int spellId;
  uint cooldown;

private:
  void _spellIdFunc(Reader *input);
  void _cooldownFunc(Reader *input);
};

#endif // GAMEFIGHTSPELLCOOLDOWN_H