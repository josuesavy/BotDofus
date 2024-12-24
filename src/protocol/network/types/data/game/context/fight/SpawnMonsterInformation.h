#ifndef SPAWNMONSTERINFORMATION_H
#define SPAWNMONSTERINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/fight/BaseSpawnMonsterInformation.h"
#include "src/utils/io/type/FuncTree.h"

class SpawnMonsterInformation : public BaseSpawnMonsterInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpawnMonsterInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpawnMonsterInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpawnMonsterInformation(FuncTree tree);
  SpawnMonsterInformation();
  bool operator==(const SpawnMonsterInformation &compared);

  uint creatureGrade;

private:
  void _creatureGradeFunc(Reader *input);
};

#endif // SPAWNMONSTERINFORMATION_H