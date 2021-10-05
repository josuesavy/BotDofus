#ifndef GAMEFIGHTFIGHTERMONSTERLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERMONSTERLIGHTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightFighterMonsterLightInformations : public GameFightFighterLightInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightFighterMonsterLightInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightFighterMonsterLightInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightFighterMonsterLightInformations(FuncTree tree);
  GameFightFighterMonsterLightInformations();
  bool operator==(const GameFightFighterMonsterLightInformations &compared);

  uint creatureGenericId;

private:
  void _creatureGenericIdFunc(Reader *input);
};

#endif // GAMEFIGHTFIGHTERMONSTERLIGHTINFORMATIONS_H