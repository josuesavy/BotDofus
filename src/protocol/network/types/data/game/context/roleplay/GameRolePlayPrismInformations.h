#ifndef GAMEROLEPLAYPRISMINFORMATIONS_H
#define GAMEROLEPLAYPRISMINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/prism/PrismInformation.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameRolePlayPrismInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayPrismInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayPrismInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayPrismInformations(FuncTree tree);
  GameRolePlayPrismInformations();
  bool operator==(const GameRolePlayPrismInformations &compared);

  QSharedPointer<PrismInformation> prism;

private:
  void _prismtreeFunc(Reader *input);

  FuncTree _prismtree;
};

#endif // GAMEROLEPLAYPRISMINFORMATIONS_H