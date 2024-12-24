#ifndef MOUNTSTERILIZEREQUESTMESSAGE_H
#define MOUNTSTERILIZEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MountSterilizeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountSterilizeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountSterilizeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountSterilizeRequestMessage(FuncTree tree);
  MountSterilizeRequestMessage();
};

#endif // MOUNTSTERILIZEREQUESTMESSAGE_H