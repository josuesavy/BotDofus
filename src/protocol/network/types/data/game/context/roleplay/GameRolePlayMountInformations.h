#ifndef GAMEROLEPLAYMOUNTINFORMATIONS_H
#define GAMEROLEPLAYMOUNTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameRolePlayMountInformations : public GameRolePlayNamedActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayMountInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayMountInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayMountInformations(FuncTree tree);
  GameRolePlayMountInformations();
  bool operator==(const GameRolePlayMountInformations &compared);

  QString ownerName;
  uint level;

private:
  void _ownerNameFunc(Reader *input);
  void _levelFunc(Reader *input);
};

#endif // GAMEROLEPLAYMOUNTINFORMATIONS_H