#ifndef SWITCHARENAXPREWARDSMODEMESSAGE_H
#define SWITCHARENAXPREWARDSMODEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SwitchArenaXpRewardsModeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SwitchArenaXpRewardsModeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SwitchArenaXpRewardsModeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SwitchArenaXpRewardsModeMessage(FuncTree tree);
  SwitchArenaXpRewardsModeMessage();

  bool xpRewards;

private:
  void _xpRewardsFunc(Reader *input);
};

#endif // SWITCHARENAXPREWARDSMODEMESSAGE_H