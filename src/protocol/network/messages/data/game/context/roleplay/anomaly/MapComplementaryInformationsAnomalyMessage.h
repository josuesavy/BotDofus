#ifndef MAPCOMPLEMENTARYINFORMATIONSANOMALYMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSANOMALYMESSAGE_H

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