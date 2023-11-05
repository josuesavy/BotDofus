#ifndef BREACHKICKREQUESTMESSAGE_H
#define BREACHKICKREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachKickRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachKickRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachKickRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachKickRequestMessage(FuncTree tree);
  BreachKickRequestMessage();

  double target;

private:
  void _targetFunc(Reader *input);
};

#endif // BREACHKICKREQUESTMESSAGE_H