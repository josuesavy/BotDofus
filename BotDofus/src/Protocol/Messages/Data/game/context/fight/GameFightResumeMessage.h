#ifndef GAMEFIGHTRESUMEMESSAGE_H
#define GAMEFIGHTRESUMEMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/GameFightSpellCooldown.h"
#include "src/Protocol/Types/Data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "src/Protocol/Types/Data/game/actions/fight/GameActionMark.h"
#include "src/Protocol/Types/Data/game/idol/Idol.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightEffectTriggerCount.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/fight/GameFightSpectateMessage.h"

class GameFightResumeMessage : public GameFightSpectateMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightResumeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightResumeMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightResumeMessage(FuncTree tree);
  GameFightResumeMessage();

  QList<GameFightSpellCooldown> spellCooldowns;
  uint summonCount;
  uint bombCount;

private:
  void _spellCooldownstreeFunc(Reader *input);
  void _spellCooldownsFunc(Reader *input);
  void _summonCountFunc(Reader *input);
  void _bombCountFunc(Reader *input);

  FuncTree _spellCooldownstree;
};

#endif // GAMEFIGHTRESUMEMESSAGE_H