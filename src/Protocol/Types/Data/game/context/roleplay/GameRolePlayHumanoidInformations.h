#ifndef GAMEROLEPLAYHUMANOIDINFORMATIONS_H
#define GAMEROLEPLAYHUMANOIDINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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