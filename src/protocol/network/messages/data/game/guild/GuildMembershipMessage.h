#ifndef GUILDMEMBERSHIPMESSAGE_H
#define GUILDMEMBERSHIPMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/GuildInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/guild/GuildJoinedMessage.h"

class GuildMembershipMessage : public GuildJoinedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMembershipMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMembershipMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMembershipMessage(FuncTree tree);
  GuildMembershipMessage();
};

#endif // GUILDMEMBERSHIPMESSAGE_H