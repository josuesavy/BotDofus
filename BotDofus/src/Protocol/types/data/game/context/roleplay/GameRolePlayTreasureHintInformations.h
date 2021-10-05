#ifndef GAMEROLEPLAYTREASUREHINTINFORMATIONS_H
#define GAMEROLEPLAYTREASUREHINTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameRolePlayTreasureHintInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayTreasureHintInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayTreasureHintInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayTreasureHintInformations(FuncTree tree);
  GameRolePlayTreasureHintInformations();
  bool operator==(const GameRolePlayTreasureHintInformations &compared);

  uint npcId;

private:
  void _npcIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYTREASUREHINTINFORMATIONS_H