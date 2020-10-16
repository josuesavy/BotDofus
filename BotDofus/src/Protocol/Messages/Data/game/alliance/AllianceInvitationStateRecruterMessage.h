#ifndef ALLIANCEINVITATIONSTATERECRUTERMESSAGE_H
#define ALLIANCEINVITATIONSTATERECRUTERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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