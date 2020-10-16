#ifndef TELEPORTHAVENBAGREQUESTMESSAGE_H
#define TELEPORTHAVENBAGREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TeleportHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportHavenBagRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportHavenBagRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportHavenBagRequestMessage(FuncTree tree);
  TeleportHavenBagRequestMessage();

  double guestId;

private:
  void _guestIdFunc(Reader *input);
};

#endif // TELEPORTHAVENBAGREQUESTMESSAGE_H