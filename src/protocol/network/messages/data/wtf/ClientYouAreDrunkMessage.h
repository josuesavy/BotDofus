#ifndef CLIENTYOUAREDRUNKMESSAGE_H
#define CLIENTYOUAREDRUNKMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/debug/DebugInClientMessage.h"

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