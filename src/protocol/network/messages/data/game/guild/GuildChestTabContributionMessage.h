#ifndef GUILDCHESTTABCONTRIBUTIONMESSAGE_H
#define GUILDCHESTTABCONTRIBUTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildChestTabContributionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildChestTabContributionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildChestTabContributionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildChestTabContributionMessage(FuncTree tree);
  GuildChestTabContributionMessage();

  uint tabNumber;
  double requiredAmount;
  double currentAmount;
  double chestContributionEnrollmentDelay;
  double chestContributionDelay;

private:
  void _tabNumberFunc(Reader *input);
  void _requiredAmountFunc(Reader *input);
  void _currentAmountFunc(Reader *input);
  void _chestContributionEnrollmentDelayFunc(Reader *input);
  void _chestContributionDelayFunc(Reader *input);
};

#endif // GUILDCHESTTABCONTRIBUTIONMESSAGE_H