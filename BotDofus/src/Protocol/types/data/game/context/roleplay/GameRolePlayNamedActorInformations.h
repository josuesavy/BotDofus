#ifndef GAMEROLEPLAYNAMEDACTORINFORMATIONS_H
#define GAMEROLEPLAYNAMEDACTORINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameRolePlayNamedActorInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayNamedActorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayNamedActorInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayNamedActorInformations(FuncTree tree);
  GameRolePlayNamedActorInformations();
  bool operator==(const GameRolePlayNamedActorInformations &compared);

  QString name;

private:
  void _nameFunc(Reader *input);
};

#endif // GAMEROLEPLAYNAMEDACTORINFORMATIONS_H