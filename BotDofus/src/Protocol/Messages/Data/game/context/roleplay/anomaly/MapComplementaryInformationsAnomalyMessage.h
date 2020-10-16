#ifndef MAPCOMPLEMENTARYINFORMATIONSANOMALYMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSANOMALYMESSAGE_H

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

class MapComplementaryInformationsAnomalyMessage : public MapComplementaryInformationsDataMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapComplementaryInformationsAnomalyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapComplementaryInformationsAnomalyMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapComplementaryInformationsAnomalyMessage(FuncTree tree);
  MapComplementaryInformationsAnomalyMessage();

  uint level;
  double closingTime;

private:
  void _levelFunc(Reader *input);
  void _closingTimeFunc(Reader *input);
};

#endif // MAPCOMPLEMENTARYINFORMATIONSANOMALYMESSAGE_H