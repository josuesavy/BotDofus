#ifndef SPAWNCHARACTERINFORMATION_H
#define SPAWNCHARACTERINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/SpawnInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class SpawnCharacterInformation : public SpawnInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpawnCharacterInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpawnCharacterInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpawnCharacterInformation(FuncTree tree);
  SpawnCharacterInformation();
  bool operator==(const SpawnCharacterInformation &compared);

  QString name;
  uint level;

private:
  void _nameFunc(Reader *input);
  void _levelFunc(Reader *input);
};

#endif // SPAWNCHARACTERINFORMATION_H