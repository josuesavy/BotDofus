#ifndef GAMEROLEPLAYPORTALINFORMATIONS_H
#define GAMEROLEPLAYPORTALINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"

class GameRolePlayPortalInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayPortalInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayPortalInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayPortalInformations(FuncTree tree);
  GameRolePlayPortalInformations();
  bool operator==(const GameRolePlayPortalInformations &compared);

  QSharedPointer<PortalInformation> portal;

private:
  void _portaltreeFunc(Reader *input);

  FuncTree _portaltree;
};

#endif // GAMEROLEPLAYPORTALINFORMATIONS_H