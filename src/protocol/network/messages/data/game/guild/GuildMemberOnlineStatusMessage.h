#ifndef GUILDMEMBERONLINESTATUSMESSAGE_H
#define GUILDMEMBERONLINESTATUSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildMemberOnlineStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMemberOnlineStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMemberOnlineStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMemberOnlineStatusMessage(FuncTree tree);
  GuildMemberOnlineStatusMessage();

  double memberId;
  bool online;

private:
  void _memberIdFunc(Reader *input);
  void _onlineFunc(Reader *input);
};

#endif // GUILDMEMBERONLINESTATUSMESSAGE_H