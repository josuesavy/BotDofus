#ifndef GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE_H
#define GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildMemberWarnOnConnectionStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMemberWarnOnConnectionStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMemberWarnOnConnectionStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMemberWarnOnConnectionStateMessage(FuncTree tree);
  GuildMemberWarnOnConnectionStateMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE_H