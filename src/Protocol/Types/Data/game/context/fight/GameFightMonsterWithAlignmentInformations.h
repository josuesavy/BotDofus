#ifndef GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS_H
#define GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightMonsterInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameFightMonsterWithAlignmentInformations : public GameFightMonsterInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightMonsterWithAlignmentInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightMonsterWithAlignmentInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightMonsterWithAlignmentInformations(FuncTree tree);
  GameFightMonsterWithAlignmentInformations();
  bool operator==(const GameFightMonsterWithAlignmentInformations &compared);

  ActorAlignmentInformations alignmentInfos;

private:
  void _alignmentInfostreeFunc(Reader *input);

  FuncTree _alignmentInfostree;
};

#endif // GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS_H