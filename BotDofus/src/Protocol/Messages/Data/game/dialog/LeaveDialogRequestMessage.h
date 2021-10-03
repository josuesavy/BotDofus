#ifndef LEAVEDIALOGREQUESTMESSAGE_H
#define LEAVEDIALOGREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class LeaveDialogRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LeaveDialogRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LeaveDialogRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LeaveDialogRequestMessage(FuncTree tree);
  LeaveDialogRequestMessage();
};

#endif // LEAVEDIALOGREQUESTMESSAGE_H