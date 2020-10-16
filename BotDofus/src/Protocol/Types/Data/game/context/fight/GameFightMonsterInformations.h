#ifndef GAMEFIGHTMONSTERINFORMATIONS_H
#define GAMEFIGHTMONSTERINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightAIInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameFightMonsterInformations : public GameFightAIInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightMonsterInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightMonsterInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightMonsterInformations(FuncTree tree);
  GameFightMonsterInformations();
  bool operator==(const GameFightMonsterInformations &compared);

  uint creatureGenericId;
  uint creatureGrade;
  uint creatureLevel;

private:
  void _creatureGenericIdFunc(Reader *input);
  void _creatureGradeFunc(Reader *input);
  void _creatureLevelFunc(Reader *input);
};

#endif // GAMEFIGHTMONSTERINFORMATIONS_H