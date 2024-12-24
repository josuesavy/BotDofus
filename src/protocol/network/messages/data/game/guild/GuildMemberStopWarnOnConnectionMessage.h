#ifndef GUILDMEMBERSTOPWARNONCONNECTIONMESSAGE_H
#define GUILDMEMBERSTOPWARNONCONNECTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildMemberStopWarnOnConnectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMemberStopWarnOnConnectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMemberStopWarnOnConnectionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMemberStopWarnOnConnectionMessage(FuncTree tree);
  GuildMemberStopWarnOnConnectionMessage();
};

#endif // GUILDMEMBERSTOPWARNONCONNECTIONMESSAGE_H