#ifndef IGNOREDINFORMATIONS_H
#define IGNOREDINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/friend/AbstractContactInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class IgnoredInformations : public AbstractContactInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IgnoredInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IgnoredInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IgnoredInformations(FuncTree tree);
  IgnoredInformations();
  bool operator==(const IgnoredInformations &compared);
};

#endif // IGNOREDINFORMATIONS_H