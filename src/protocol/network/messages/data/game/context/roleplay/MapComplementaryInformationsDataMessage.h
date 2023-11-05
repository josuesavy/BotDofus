#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/context/fight/FightCommonInformations.h"
#include "src/protocol/types/data/game/context/fight/FightStartingPositions.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/types/data/game/house/HouseInformations.h"
#include "src/protocol/types/data/game/interactive/InteractiveElement.h"
#include "src/protocol/types/data/game/interactive/MapObstacle.h"
#include "src/protocol/types/data/game/interactive/StatedElement.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MapComplementaryInformationsDataMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapComplementaryInformationsDataMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapComplementaryInformationsDataMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapComplementaryInformationsDataMessage(FuncTree tree);
  MapComplementaryInformationsDataMessage();

  uint subAreaId;
  double mapId;
  QList<QSharedPointer<HouseInformations>> houses;
  QList<QSharedPointer<GameRolePlayActorInformations>> actors;
  QList<QSharedPointer<InteractiveElement>> interactiveElements;
  QList<StatedElement> statedElements;
  QList<MapObstacle> obstacles;
  QList<FightCommonInformations> fights;
  bool hasAggressiveMonsters;
  FightStartingPositions fightStartPositions;

private:
  void _subAreaIdFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _housestreeFunc(Reader *input);
  void _housesFunc(Reader *input);
  void _actorstreeFunc(Reader *input);
  void _actorsFunc(Reader *input);
  void _interactiveElementstreeFunc(Reader *input);
  void _interactiveElementsFunc(Reader *input);
  void _statedElementstreeFunc(Reader *input);
  void _statedElementsFunc(Reader *input);
  void _obstaclestreeFunc(Reader *input);
  void _obstaclesFunc(Reader *input);
  void _fightstreeFunc(Reader *input);
  void _fightsFunc(Reader *input);
  void _hasAggressiveMonstersFunc(Reader *input);
  void _fightStartPositionstreeFunc(Reader *input);

  FuncTree _housestree;
  FuncTree _actorstree;
  FuncTree _interactiveElementstree;
  FuncTree _statedElementstree;
  FuncTree _obstaclestree;
  FuncTree _fightstree;
  FuncTree _fightStartPositionstree;
};

#endif // MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_H