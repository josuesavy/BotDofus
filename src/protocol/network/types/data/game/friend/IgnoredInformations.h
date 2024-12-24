#ifndef IGNOREDINFORMATIONS_H
#define IGNOREDINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/friend/AbstractContactInformations.h"
#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/utils/io/type/FuncTree.h"

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