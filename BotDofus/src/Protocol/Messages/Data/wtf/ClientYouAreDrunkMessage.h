#ifndef CLIENTYOUAREDRUNKMESSAGE_H
#define CLIENTYOUAREDRUNKMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/debug/DebugInClientMessage.h"

class ClientYouAreDrunkMessage : public DebugInClientMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ClientYouAreDrunkMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ClientYouAreDrunkMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ClientYouAreDrunkMessage(FuncTree tree);
  ClientYouAreDrunkMessage();
};

#endif // CLIENTYOUAREDRUNKMESSAGE_H