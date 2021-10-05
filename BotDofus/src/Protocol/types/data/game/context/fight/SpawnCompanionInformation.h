#ifndef SPAWNCOMPANIONINFORMATION_H
#define SPAWNCOMPANIONINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/SpawnInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class SpawnCompanionInformation : public SpawnInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpawnCompanionInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpawnCompanionInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpawnCompanionInformation(FuncTree tree);
  SpawnCompanionInformation();
  bool operator==(const SpawnCompanionInformation &compared);

  uint modelId;
  uint level;
  double summonerId;
  double ownerId;

private:
  void _modelIdFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _summonerIdFunc(Reader *input);
  void _ownerIdFunc(Reader *input);
};

#endif // SPAWNCOMPANIONINFORMATION_H