#ifndef GAMEROLEPLAYNPCINFORMATIONS_H
#define GAMEROLEPLAYNPCINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameRolePlayNpcInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayNpcInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayNpcInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayNpcInformations(FuncTree tree);
  GameRolePlayNpcInformations();
  bool operator==(const GameRolePlayNpcInformations &compared);

  uint npcId;
  bool sex;
  uint specialArtworkId;

private:
  void _npcIdFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _specialArtworkIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYNPCINFORMATIONS_H