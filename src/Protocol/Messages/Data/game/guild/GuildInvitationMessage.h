#ifndef GUILDINVITATIONMESSAGE_H
#define GUILDINVITATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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