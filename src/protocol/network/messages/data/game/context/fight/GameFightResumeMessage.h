#ifndef GAMEFIGHTRESUMEMESSAGE_H
#define GAMEFIGHTRESUMEMESSAGE_H

#include "src/protocol/types/data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "src/protocol/types/data/game/actions/fight/GameActionMark.h"
#include "src/protocol/types/data/game/context/fight/GameFightEffectTriggerCount.h"
#include "src/protocol/types/data/game/context/fight/GameFightSpellCooldown.h"
#include "src/protocol/types/data/game/idol/Idol.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/fight/GameFightSpectateMessage.h"

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