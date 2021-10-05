#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE_H

#include "src/protocol/types/data/game/house/HouseInformationsInside.h"
#include "src/protocol/types/data/game/house/HouseInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/types/data/game/interactive/InteractiveElement.h"
#include "src/protocol/types/data/game/interactive/StatedElement.h"
#include "src/protocol/types/data/game/interactive/MapObstacle.h"
#include "src/protocol/types/data/game/context/fight/FightCommonInformations.h"
#include "src/protocol/types/data/game/context/fight/FightStartingPositions.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/MapComplementaryInformationsDataMessage.h"

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