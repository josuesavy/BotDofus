#ifndef MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE_H

#include "src/Protocol/Types/Data/game/house/HouseInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/Protocol/Types/Data/game/interactive/InteractiveElement.h"
#include "src/Protocol/Types/Data/game/interactive/StatedElement.h"
#include "src/Protocol/Types/Data/game/interactive/MapObstacle.h"
#include "src/Protocol/Types/Data/game/context/fight/FightCommonInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightStartingPositions.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/MapComplementaryInformationsDataMessage.h"

class MapComplementaryInformationsWithCoordsMessage : public MapComplementaryInformationsDataMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapComplementaryInformationsWithCoordsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapComplementaryInformationsWithCoordsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapComplementaryInformationsWithCoordsMessage(FuncTree tree);
  MapComplementaryInformationsWithCoordsMessage();

  int worldX;
  int worldY;

private:
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
};

#endif // MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE_H