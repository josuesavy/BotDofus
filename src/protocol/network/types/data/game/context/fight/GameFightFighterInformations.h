#ifndef GAMEFIGHTFIGHTERINFORMATIONS_H
#define GAMEFIGHTFIGHTERINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/fight/GameContextBasicSpawnInformation.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightCharacteristics.h"
#include "src/protocol/network/types/data/game/context/GameContextActorInformations.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"

class GameFightFighterInformations : public GameContextActorInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightFighterInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightFighterInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightFighterInformations(FuncTree tree);
  GameFightFighterInformations();
  bool operator==(const GameFightFighterInformations &compared);

  QSharedPointer<GameContextBasicSpawnInformation> spawnInfo;
  uint wave;
  QSharedPointer<GameFightCharacteristics> stats;
  QList<uint> previousPositions;

private:
  void _spawnInfotreeFunc(Reader *input);
  void _waveFunc(Reader *input);
  void _statstreeFunc(Reader *input);
  void _previousPositionstreeFunc(Reader *input);
  void _previousPositionsFunc(Reader *input);

  FuncTree _spawnInfotree;
  FuncTree _statstree;
  FuncTree _previousPositionstree;
};

#endif // GAMEFIGHTFIGHTERINFORMATIONS_H