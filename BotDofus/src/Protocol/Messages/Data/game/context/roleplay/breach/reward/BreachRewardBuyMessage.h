#ifndef BREACHREWARDBUYMESSAGE_H
#define BREACHREWARDBUYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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