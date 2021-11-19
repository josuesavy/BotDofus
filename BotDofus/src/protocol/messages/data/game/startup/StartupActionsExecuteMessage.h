#ifndef STARTUPACTIONSEXECUTEMESSAGE_H
#define STARTUPACTIONSEXECUTEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartupActionsExecuteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartupActionsExecuteMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartupActionsExecuteMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartupActionsExecuteMessage(FuncTree tree);
  StartupActionsExecuteMessage();
};

#endif // STARTUPACTIONSEXECUTEMESSAGE_H