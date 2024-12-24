#ifndef ALLIANCEINVITATIONSTATERECRUTERMESSAGE_H
#define ALLIANCEINVITATIONSTATERECRUTERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceInvitationStateRecruterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInvitationStateRecruterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInvitationStateRecruterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInvitationStateRecruterMessage(FuncTree tree);
  AllianceInvitationStateRecruterMessage();

  QString recrutedName;
  uint invitationState;

private:
  void _recrutedNameFunc(Reader *input);
  void _invitationStateFunc(Reader *input);
};

#endif // ALLIANCEINVITATIONSTATERECRUTERMESSAGE_H