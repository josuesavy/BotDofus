#ifndef MOUNTTOGGLERIDINGREQUESTMESSAGE_H
#define MOUNTTOGGLERIDINGREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountToggleRidingRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountToggleRidingRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountToggleRidingRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountToggleRidingRequestMessage(FuncTree tree);
  MountToggleRidingRequestMessage();
};

#endif // MOUNTTOGGLERIDINGREQUESTMESSAGE_H