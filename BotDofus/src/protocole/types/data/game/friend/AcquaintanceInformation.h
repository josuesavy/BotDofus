#ifndef ACQUAINTANCEINFORMATION_H
#define ACQUAINTANCEINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/friend/AbstractContactInformations.h"
#include "src/protocol/types/data/common/AccountTagInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AcquaintanceInformation : public AbstractContactInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AcquaintanceInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AcquaintanceInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AcquaintanceInformation(FuncTree tree);
  AcquaintanceInformation();
  bool operator==(const AcquaintanceInformation &compared);

  uint playerState;

private:
  void _playerStateFunc(Reader *input);
};

#endif // ACQUAINTANCEINFORMATION_H