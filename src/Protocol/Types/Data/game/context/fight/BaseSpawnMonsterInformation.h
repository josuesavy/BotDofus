#ifndef BASESPAWNMONSTERINFORMATION_H
#define BASESPAWNMONSTERINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/SpawnInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class BaseSpawnMonsterInformation : public SpawnInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BaseSpawnMonsterInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BaseSpawnMonsterInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BaseSpawnMonsterInformation(FuncTree tree);
  BaseSpawnMonsterInformation();
  bool operator==(const BaseSpawnMonsterInformation &compared);

  uint creatureGenericId;

private:
  void _creatureGenericIdFunc(Reader *input);
};

#endif // BASESPAWNMONSTERINFORMATION_H