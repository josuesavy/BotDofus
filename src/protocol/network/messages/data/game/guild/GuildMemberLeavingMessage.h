#ifndef GUILDMEMBERLEAVINGMESSAGE_H
#define GUILDMEMBERLEAVINGMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildMemberLeavingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMemberLeavingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMemberLeavingMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMemberLeavingMessage(FuncTree tree);
  GuildMemberLeavingMessage();

  bool kicked;
  double memberId;

private:
  void _kickedFunc(Reader *input);
  void _memberIdFunc(Reader *input);
};

#endif // GUILDMEMBERLEAVINGMESSAGE_H