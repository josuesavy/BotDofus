#ifndef BREACHREWARDSMESSAGE_H
#define BREACHREWARDSMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/breach/BreachReward.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachRewardsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachRewardsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachRewardsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachRewardsMessage(FuncTree tree);
  BreachRewardsMessage();

  QList<BreachReward> rewards;

private:
  void _rewardstreeFunc(Reader *input);
  void _rewardsFunc(Reader *input);

  FuncTree _rewardstree;
};

#endif // BREACHREWARDSMESSAGE_H