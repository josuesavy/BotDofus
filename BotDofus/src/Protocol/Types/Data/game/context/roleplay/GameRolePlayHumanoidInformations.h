#ifndef GAMEROLEPLAYHUMANOIDINFORMATIONS_H
#define GAMEROLEPLAYHUMANOIDINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/HumanInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameRolePlayHumanoidInformations : public GameRolePlayNamedActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayHumanoidInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayHumanoidInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayHumanoidInformations(FuncTree tree);
  GameRolePlayHumanoidInformations();
  bool operator==(const GameRolePlayHumanoidInformations &compared);

  QSharedPointer<HumanInformations> humanoidInfo;
  uint accountId;

private:
  void _humanoidInfotreeFunc(Reader *input);
  void _accountIdFunc(Reader *input);

  FuncTree _humanoidInfotree;
};

#endif // GAMEROLEPLAYHUMANOIDINFORMATIONS_H