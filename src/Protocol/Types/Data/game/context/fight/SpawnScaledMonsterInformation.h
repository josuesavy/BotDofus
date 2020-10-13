#ifndef SPAWNSCALEDMONSTERINFORMATION_H
#define SPAWNSCALEDMONSTERINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/BaseSpawnMonsterInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class SpawnScaledMonsterInformation : public BaseSpawnMonsterInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpawnScaledMonsterInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpawnScaledMonsterInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpawnScaledMonsterInformation(FuncTree tree);
  SpawnScaledMonsterInformation();
  bool operator==(const SpawnScaledMonsterInformation &compared);

  uint creatureLevel;

private:
  void _creatureLevelFunc(Reader *input);
};

#endif // SPAWNSCALEDMONSTERINFORMATION_H