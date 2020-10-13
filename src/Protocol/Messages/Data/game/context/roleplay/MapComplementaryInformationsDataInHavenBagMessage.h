#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE_H

#include "src/Protocol/Types/Data/game/character/CharacterMinimalInformations.h"
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