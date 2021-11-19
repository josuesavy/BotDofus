#ifndef MOUNTHARNESSDISSOCIATEREQUESTMESSAGE_H
#define MOUNTHARNESSDISSOCIATEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountHarnessDissociateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountHarnessDissociateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountHarnessDissociateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountHarnessDissociateRequestMessage(FuncTree tree);
  MountHarnessDissociateRequestMessage();
};

#endif // MOUNTHARNESSDISSOCIATEREQUESTMESSAGE_H