#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE_H

#include "src/Protocol/Types/Data/game/house/HouseInformationsInside.h"
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

class MapComplementaryInformationsDataInHouseMessage : public MapComplementaryInformationsDataMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapComplementaryInformationsDataInHouseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapComplementaryInformationsDataInHouseMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapComplementaryInformationsDataInHouseMessage(FuncTree tree);
  MapComplementaryInformationsDataInHouseMessage();

  QSharedPointer<HouseInformationsInside> currentHouse;

private:
  void _currentHousetreeFunc(Reader *input);

  FuncTree _currentHousetree;
};

#endif // MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE_H