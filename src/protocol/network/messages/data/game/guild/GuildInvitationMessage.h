#ifndef GUILDINVITATIONMESSAGE_H
#define GUILDINVITATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildInvitationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInvitationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInvitationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInvitationMessage(FuncTree tree);
  GuildInvitationMessage();

  double targetId;

private:
  void _targetIdFunc(Reader *input);
};

#endif // GUILDINVITATIONMESSAGE_H