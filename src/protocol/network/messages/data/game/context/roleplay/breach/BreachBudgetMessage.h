#ifndef BREACHBUDGETMESSAGE_H
#define BREACHBUDGETMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BreachBudgetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachBudgetMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachBudgetMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachBudgetMessage(FuncTree tree);
  BreachBudgetMessage();

  uint bugdet;

private:
  void _bugdetFunc(Reader *input);
};

#endif // BREACHBUDGETMESSAGE_H