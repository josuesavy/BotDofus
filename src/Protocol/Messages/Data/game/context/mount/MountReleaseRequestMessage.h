#ifndef MOUNTRELEASEREQUESTMESSAGE_H
#define MOUNTRELEASEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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