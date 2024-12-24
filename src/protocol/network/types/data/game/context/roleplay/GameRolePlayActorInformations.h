#ifndef GAMEROLEPLAYACTORINFORMATIONS_H
#define GAMEROLEPLAYACTORINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/GameContextActorInformations.h"
#include "src/protocol/network/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"

class GameRolePlayActorInformations : public GameContextActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayActorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayActorInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayActorInformations(FuncTree tree);
  GameRolePlayActorInformations();
  bool operator==(const GameRolePlayActorInformations &compared);
};

#endif // GAMEROLEPLAYACTORINFORMATIONS_H