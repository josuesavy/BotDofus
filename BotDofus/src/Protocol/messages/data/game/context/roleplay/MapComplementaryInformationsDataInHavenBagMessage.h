#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE_H

#include "src/protocol/types/data/game/character/CharacterMinimalInformations.h"
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

class MapComplementaryInformationsDataInHavenBagMessage : public MapComplementaryInformationsDataMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapComplementaryInformationsDataInHavenBagMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapComplementaryInformationsDataInHavenBagMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapComplementaryInformationsDataInHavenBagMessage(FuncTree tree);
  MapComplementaryInformationsDataInHavenBagMessage();

  CharacterMinimalInformations ownerInformations;
  int theme;
  uint roomId;
  uint maxRoomId;

private:
  void _ownerInformationstreeFunc(Reader *input);
  void _themeFunc(Reader *input);
  void _roomIdFunc(Reader *input);
  void _maxRoomIdFunc(Reader *input);

  FuncTree _ownerInformationstree;
};

#endif // MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE_H