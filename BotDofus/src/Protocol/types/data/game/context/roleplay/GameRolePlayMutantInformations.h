#ifndef GAMEROLEPLAYMUTANTINFORMATIONS_H
#define GAMEROLEPLAYMUTANTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameRolePlayMutantInformations : public GameRolePlayHumanoidInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayMutantInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayMutantInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayMutantInformations(FuncTree tree);
  GameRolePlayMutantInformations();
  bool operator==(const GameRolePlayMutantInformations &compared);

  uint monsterId;
  int powerLevel;

private:
  void _monsterIdFunc(Reader *input);
  void _powerLevelFunc(Reader *input);
};

#endif // GAMEROLEPLAYMUTANTINFORMATIONS_H