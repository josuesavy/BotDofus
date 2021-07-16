#ifndef GAMECONTEXTSUMMONSINFORMATION_H
#define GAMECONTEXTSUMMONSINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/SpawnInformation.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/data/game/context/fight/GameFightCharacteristics.h"
#include "src/protocol/types/data/game/context/fight/GameContextBasicSpawnInformation.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameContextSummonsInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextSummonsInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextSummonsInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextSummonsInformation(FuncTree tree);
  GameContextSummonsInformation();
  bool operator==(const GameContextSummonsInformation &compared);

  QSharedPointer<SpawnInformation> spawnInformation;
  uint wave;
  QSharedPointer<EntityLook> look;
  QSharedPointer<GameFightCharacteristics> stats;
  QList<QSharedPointer<GameContextBasicSpawnInformation>> summons;

private:
  void _spawnInformationtreeFunc(Reader *input);
  void _waveFunc(Reader *input);
  void _looktreeFunc(Reader *input);
  void _statstreeFunc(Reader *input);
  void _summonstreeFunc(Reader *input);
  void _summonsFunc(Reader *input);

  FuncTree _spawnInformationtree;
  FuncTree _looktree;
  FuncTree _statstree;
  FuncTree _summonstree;
};

#endif // GAMECONTEXTSUMMONSINFORMATION_H