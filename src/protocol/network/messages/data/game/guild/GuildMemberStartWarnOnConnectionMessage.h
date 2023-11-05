#ifndef GUILDMEMBERSTARTWARNONCONNECTIONMESSAGE_H
#define GUILDMEMBERSTARTWARNONCONNECTIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildMemberStartWarnOnConnectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMemberStartWarnOnConnectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMemberStartWarnOnConnectionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMemberStartWarnOnConnectionMessage(FuncTree tree);
  GuildMemberStartWarnOnConnectionMessage();
};

#endif // GUILDMEMBERSTARTWARNONCONNECTIONMESSAGE_H