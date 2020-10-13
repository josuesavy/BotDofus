#ifndef GUILDMEMBERSHIPMESSAGE_H
#define GUILDMEMBERSHIPMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/guild/GuildJoinedMessage.h"

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