#ifndef GUILDGETCHESTTABCONTRIBUTIONSREQUESTMESSAGE_H
#define GUILDGETCHESTTABCONTRIBUTIONSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildGetChestTabContributionsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildGetChestTabContributionsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildGetChestTabContributionsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildGetChestTabContributionsRequestMessage(FuncTree tree);
  GuildGetChestTabContributionsRequestMessage();
};

#endif // GUILDGETCHESTTABCONTRIBUTIONSREQUESTMESSAGE_H