#ifndef MOUNTRELEASEREQUESTMESSAGE_H
#define MOUNTRELEASEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MountReleaseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountReleaseRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountReleaseRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountReleaseRequestMessage(FuncTree tree);
  MountReleaseRequestMessage();
};

#endif // MOUNTRELEASEREQUESTMESSAGE_H