#ifndef GAMEROLEPLAYPORTALINFORMATIONS_H
#define GAMEROLEPLAYPORTALINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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