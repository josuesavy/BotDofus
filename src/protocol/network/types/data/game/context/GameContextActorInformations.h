#ifndef GAMECONTEXTACTORINFORMATIONS_H
#define GAMECONTEXTACTORINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/data/game/context/GameContextActorPositionInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameContextActorInformations : public GameContextActorPositionInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextActorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextActorInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextActorInformations(FuncTree tree);
  GameContextActorInformations();
  bool operator==(const GameContextActorInformations &compared);

  EntityLook look;

private:
  void _looktreeFunc(Reader *input);

  FuncTree _looktree;
};

#endif // GAMECONTEXTACTORINFORMATIONS_H