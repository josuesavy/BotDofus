#ifndef ALLIANCEINVITATIONSTATERECRUTEDMESSAGE_H
#define ALLIANCEINVITATIONSTATERECRUTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AllianceInvitationStateRecrutedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInvitationStateRecrutedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInvitationStateRecrutedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInvitationStateRecrutedMessage(FuncTree tree);
  AllianceInvitationStateRecrutedMessage();

  uint invitationState;

private:
  void _invitationStateFunc(Reader *input);
};

#endif // ALLIANCEINVITATIONSTATERECRUTEDMESSAGE_H