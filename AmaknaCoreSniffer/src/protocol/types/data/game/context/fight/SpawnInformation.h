#ifndef SPAWNINFORMATION_H
#define SPAWNINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class SpawnInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpawnInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpawnInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpawnInformation(FuncTree tree);
  SpawnInformation();
  bool operator==(const SpawnInformation &compared);
};

#endif // SPAWNINFORMATION_H