#ifndef GAMEROLEPLAYGROUPMONSTERINFORMATIONS_H
#define GAMEROLEPLAYGROUPMONSTERINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameRolePlayGroupMonsterInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayGroupMonsterInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayGroupMonsterInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayGroupMonsterInformations(FuncTree tree);
  GameRolePlayGroupMonsterInformations();
  bool operator==(const GameRolePlayGroupMonsterInformations &compared);

  QSharedPointer<GroupMonsterStaticInformations> staticInfos;
  int lootShare;
  int alignmentSide;
  bool keyRingBonus;
  bool hasHardcoreDrop;
  bool hasAVARewardToken;

private:
  void deserializeByteBoxes(Reader *input);
  void _staticInfostreeFunc(Reader *input);
  void _lootShareFunc(Reader *input);
  void _alignmentSideFunc(Reader *input);

  FuncTree _staticInfostree;
};

#endif // GAMEROLEPLAYGROUPMONSTERINFORMATIONS_H