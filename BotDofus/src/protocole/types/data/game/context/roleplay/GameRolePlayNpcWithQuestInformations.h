#ifndef GAMEROLEPLAYNPCWITHQUESTINFORMATIONS_H
#define GAMEROLEPLAYNPCWITHQUESTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/quest/GameRolePlayNpcQuestFlag.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNpcInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameRolePlayNpcWithQuestInformations : public GameRolePlayNpcInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayNpcWithQuestInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayNpcWithQuestInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayNpcWithQuestInformations(FuncTree tree);
  GameRolePlayNpcWithQuestInformations();
  bool operator==(const GameRolePlayNpcWithQuestInformations &compared);

  GameRolePlayNpcQuestFlag questFlag;

private:
  void _questFlagtreeFunc(Reader *input);

  FuncTree _questFlagtree;
};

#endif // GAMEROLEPLAYNPCWITHQUESTINFORMATIONS_H