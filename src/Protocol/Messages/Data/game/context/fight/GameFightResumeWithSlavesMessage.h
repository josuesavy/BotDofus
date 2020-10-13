#ifndef GAMEFIGHTRESUMEWITHSLAVESMESSAGE_H
#define GAMEFIGHTRESUMEWITHSLAVESMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/GameFightResumeSlaveInfo.h"
#include "src/Protocol/Types/Data/game/action/fight/FightDispellableEffectExtendedInformations.h"
#include "src/Protocol/Types/Data/game/actions/fight/GameActionMark.h"
#include "src/Protocol/Types/Data/game/idol/Idol.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightEffectTriggerCount.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightSpellCooldown.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/fight/GameFightResumeMessage.h"

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