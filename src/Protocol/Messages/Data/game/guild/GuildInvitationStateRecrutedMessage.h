#ifndef GUILDINVITATIONSTATERECRUTEDMESSAGE_H
#define GUILDINVITATIONSTATERECRUTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildInvitationStateRecrutedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInvitationStateRecrutedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInvitationStateRecrutedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInvitationStateRecrutedMessage(FuncTree tree);
  GuildInvitationStateRecrutedMessage();

  uint invitationState;

private:
  void _invitationStateFunc(Reader *input);
};

#endif // GUILDINVITATIONSTATERECRUTEDMESSAGE_H