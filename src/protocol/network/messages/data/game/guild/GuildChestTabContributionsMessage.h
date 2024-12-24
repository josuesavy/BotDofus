#ifndef GUILDCHESTTABCONTRIBUTIONSMESSAGE_H
#define GUILDCHESTTABCONTRIBUTIONSMESSAGE_H

#include "src/protocol/network/types/data/game/guild/Contribution.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildChestTabContributionsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildChestTabContributionsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildChestTabContributionsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildChestTabContributionsMessage(FuncTree tree);
  GuildChestTabContributionsMessage();

  QList<Contribution> contributions;

private:
  void _contributionstreeFunc(Reader *input);
  void _contributionsFunc(Reader *input);

  FuncTree _contributionstree;
};

#endif // GUILDCHESTTABCONTRIBUTIONSMESSAGE_H