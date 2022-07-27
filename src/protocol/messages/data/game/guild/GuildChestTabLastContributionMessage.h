#ifndef GUILDCHESTTABLASTCONTRIBUTIONMESSAGE_H
#define GUILDCHESTTABLASTCONTRIBUTIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildChestTabLastContributionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildChestTabLastContributionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildChestTabLastContributionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildChestTabLastContributionMessage(FuncTree tree);
  GuildChestTabLastContributionMessage();

  double lastContributionDate;

private:
  void _lastContributionDateFunc(Reader *input);
};

#endif // GUILDCHESTTABLASTCONTRIBUTIONMESSAGE_H