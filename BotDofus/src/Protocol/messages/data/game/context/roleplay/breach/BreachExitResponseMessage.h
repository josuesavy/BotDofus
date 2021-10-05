#ifndef BREACHEXITRESPONSEMESSAGE_H
#define BREACHEXITRESPONSEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachExitResponseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachExitResponseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachExitResponseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachExitResponseMessage(FuncTree tree);
  BreachExitResponseMessage();

  bool exited;

private:
  void _exitedFunc(Reader *input);
};

#endif // BREACHEXITRESPONSEMESSAGE_H