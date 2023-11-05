#ifndef GAMEFIGHTRESUMEWITHSLAVESMESSAGE_H
#define GAMEFIGHTRESUMEWITHSLAVESMESSAGE_H

#include "src/protocol/types/data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "src/protocol/types/data/game/actions/fight/GameActionMark.h"
#include "src/protocol/types/data/game/context/fight/GameFightEffectTriggerCount.h"
#include "src/protocol/types/data/game/context/fight/GameFightResumeSlaveInfo.h"
#include "src/protocol/types/data/game/context/fight/GameFightSpellCooldown.h"
#include "src/protocol/types/data/game/idol/Idol.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/fight/GameFightResumeMessage.h"

class GameFightResumeWithSlavesMessage : public GameFightResumeMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightResumeWithSlavesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightResumeWithSlavesMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightResumeWithSlavesMessage(FuncTree tree);
  GameFightResumeWithSlavesMessage();

  QList<GameFightResumeSlaveInfo> slavesInfo;

private:
  void _slavesInfotreeFunc(Reader *input);
  void _slavesInfoFunc(Reader *input);

  FuncTree _slavesInfotree;
};

#endif // GAMEFIGHTRESUMEWITHSLAVESMESSAGE_H