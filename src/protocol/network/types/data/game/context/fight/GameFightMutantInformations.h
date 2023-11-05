#ifndef GAMEFIGHTMUTANTINFORMATIONS_H
#define GAMEFIGHTMUTANTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterNamedInformations.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightMutantInformations : public GameFightFighterNamedInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightMutantInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightMutantInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightMutantInformations(FuncTree tree);
  GameFightMutantInformations();
  bool operator==(const GameFightMutantInformations &compared);

  uint powerLevel;

private:
  void _powerLevelFunc(Reader *input);
};

#endif // GAMEFIGHTMUTANTINFORMATIONS_H