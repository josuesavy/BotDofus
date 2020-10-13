#ifndef GAMECONTEXTBASICSPAWNINFORMATION_H
#define GAMECONTEXTBASICSPAWNINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/GameContextActorPositionInformations.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameContextBasicSpawnInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextBasicSpawnInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextBasicSpawnInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextBasicSpawnInformation(FuncTree tree);
  GameContextBasicSpawnInformation();
  bool operator==(const GameContextBasicSpawnInformation &compared);

  uint teamId;
  bool alive;
  QSharedPointer<GameContextActorPositionInformations> informations;

private:
  void _teamIdFunc(Reader *input);
  void _aliveFunc(Reader *input);
  void _informationstreeFunc(Reader *input);

  FuncTree _informationstree;
};

#endif // GAMECONTEXTBASICSPAWNINFORMATION_H