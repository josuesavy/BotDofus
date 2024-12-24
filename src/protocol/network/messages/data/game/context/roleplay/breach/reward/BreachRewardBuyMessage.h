#ifndef BREACHREWARDBUYMESSAGE_H
#define BREACHREWARDBUYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BreachRewardBuyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachRewardBuyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachRewardBuyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachRewardBuyMessage(FuncTree tree);
  BreachRewardBuyMessage();

  uint id;

private:
  void _idFunc(Reader *input);
};

#endif // BREACHREWARDBUYMESSAGE_H