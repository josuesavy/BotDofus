#ifndef MAPCOMPLEMENTARYINFORMATIONSBREACHMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSBREACHMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/breach/BreachBranch.h"
#include "src/Protocol/Types/Data/game/house/HouseInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/Protocol/Types/Data/game/interactive/InteractiveElement.h"
#include "src/Protocol/Types/Data/game/interactive/StatedElement.h"
#include "src/Protocol/Types/Data/game/interactive/MapObstacle.h"
#include "src/Protocol/Types/Data/game/context/fight/FightCommonInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightStartingPositions.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/MapComplementaryInformationsDataMessage.h"

class MapComplementaryInformationsBreachMessage : public MapComplementaryInformationsDataMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapComplementaryInformationsBreachMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapComplementaryInformationsBreachMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapComplementaryInformationsBreachMessage(FuncTree tree);
  MapComplementaryInformationsBreachMessage();

  uint floor;
  uint room;
  uint infinityMode;
  QList<QSharedPointer<BreachBranch>> branches;

private:
  void _floorFunc(Reader *input);
  void _roomFunc(Reader *input);
  void _infinityModeFunc(Reader *input);
  void _branchestreeFunc(Reader *input);
  void _branchesFunc(Reader *input);

  FuncTree _branchestree;
};

#endif // MAPCOMPLEMENTARYINFORMATIONSBREACHMESSAGE_H