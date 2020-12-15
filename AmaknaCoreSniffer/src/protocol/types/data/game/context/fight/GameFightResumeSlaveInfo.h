#ifndef GAMEFIGHTRESUMESLAVEINFO_H
#define GAMEFIGHTRESUMESLAVEINFO_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/GameFightSpellCooldown.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightResumeSlaveInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightResumeSlaveInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightResumeSlaveInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightResumeSlaveInfo(FuncTree tree);
  GameFightResumeSlaveInfo();
  bool operator==(const GameFightResumeSlaveInfo &compared);

  double slaveId;
  QList<GameFightSpellCooldown> spellCooldowns;
  uint summonCount;
  uint bombCount;

private:
  void _slaveIdFunc(Reader *input);
  void _spellCooldownstreeFunc(Reader *input);
  void _spellCooldownsFunc(Reader *input);
  void _summonCountFunc(Reader *input);
  void _bombCountFunc(Reader *input);

  FuncTree _spellCooldownstree;
};

#endif // GAMEFIGHTRESUMESLAVEINFO_H