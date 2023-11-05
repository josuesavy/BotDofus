#ifndef GUILDINVITATIONSTATERECRUTERMESSAGE_H
#define GUILDINVITATIONSTATERECRUTERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildInvitationStateRecruterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInvitationStateRecruterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInvitationStateRecruterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInvitationStateRecruterMessage(FuncTree tree);
  GuildInvitationStateRecruterMessage();

  QString recrutedName;
  uint invitationState;

private:
  void _recrutedNameFunc(Reader *input);
  void _invitationStateFunc(Reader *input);
};

#endif // GUILDINVITATIONSTATERECRUTERMESSAGE_H