#ifndef GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE_H
#define GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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