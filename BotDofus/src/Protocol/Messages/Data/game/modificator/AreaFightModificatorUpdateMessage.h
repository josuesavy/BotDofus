#ifndef AREAFIGHTMODIFICATORUPDATEMESSAGE_H
#define AREAFIGHTMODIFICATORUPDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AreaFightModificatorUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AreaFightModificatorUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AreaFightModificatorUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AreaFightModificatorUpdateMessage(FuncTree tree);
  AreaFightModificatorUpdateMessage();

  int spellPairId;

private:
  void _spellPairIdFunc(Reader *input);
};

#endif // AREAFIGHTMODIFICATORUPDATEMESSAGE_H