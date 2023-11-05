#ifndef MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE_H

#include "src/protocol/types/data/game/context/fight/FightCommonInformations.h"
#include "src/protocol/types/data/game/context/fight/FightStartingPositions.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/types/data/game/house/HouseInformations.h"
#include "src/protocol/types/data/game/interactive/InteractiveElement.h"
#include "src/protocol/types/data/game/interactive/MapObstacle.h"
#include "src/protocol/types/data/game/interactive/StatedElement.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/MapComplementaryInformationsDataMessage.h"

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