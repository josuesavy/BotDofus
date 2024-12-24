#ifndef GAMEROLEPLAYCHARACTERINFORMATIONS_H
#define GAMEROLEPLAYCHARACTERINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/character/alignment/ActorAlignmentInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "src/protocol/network/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"

class GameRolePlayCharacterInformations : public GameRolePlayHumanoidInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayCharacterInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayCharacterInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayCharacterInformations(FuncTree tree);
  GameRolePlayCharacterInformations();
  bool operator==(const GameRolePlayCharacterInformations &compared);

  ActorAlignmentInformations alignmentInfos;

private:
  void _alignmentInfostreeFunc(Reader *input);

  FuncTree _alignmentInfostree;
};

#endif // GAMEROLEPLAYCHARACTERINFORMATIONS_H