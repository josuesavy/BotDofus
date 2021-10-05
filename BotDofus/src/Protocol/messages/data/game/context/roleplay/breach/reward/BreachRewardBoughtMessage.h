#ifndef BREACHREWARDBOUGHTMESSAGE_H
#define BREACHREWARDBOUGHTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachRewardBoughtMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachRewardBoughtMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachRewardBoughtMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachRewardBoughtMessage(FuncTree tree);
  BreachRewardBoughtMessage();

  uint id;
  bool bought;

private:
  void _idFunc(Reader *input);
  void _boughtFunc(Reader *input);
};

#endif // BREACHREWARDBOUGHTMESSAGE_H