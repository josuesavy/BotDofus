#ifndef ACQUAINTANCESGETLISTMESSAGE_H
#define ACQUAINTANCESGETLISTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AcquaintancesGetListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AcquaintancesGetListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AcquaintancesGetListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AcquaintancesGetListMessage(FuncTree tree);
  AcquaintancesGetListMessage();
};

#endif // ACQUAINTANCESGETLISTMESSAGE_H