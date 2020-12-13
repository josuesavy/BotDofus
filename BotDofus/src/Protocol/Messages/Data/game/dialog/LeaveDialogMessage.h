#ifndef LEAVEDIALOGMESSAGE_H
#define LEAVEDIALOGMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class LeaveDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_LeaveDialogMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_LeaveDialogMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_LeaveDialogMessage(FuncTree tree);
  LeaveDialogMessage();

  uint dialogType;

private:
  void _dialogTypeFunc(Reader *input);
};

#endif // LEAVEDIALOGMESSAGE_H