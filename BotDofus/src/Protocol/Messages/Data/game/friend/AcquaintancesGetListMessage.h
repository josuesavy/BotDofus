#ifndef ACQUAINTANCESGETLISTMESSAGE_H
#define ACQUAINTANCESGETLISTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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