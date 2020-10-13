#ifndef PARTYINVITATIONREQUESTMESSAGE_H
#define PARTYINVITATIONREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PartyInvitationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationRequestMessage(FuncTree tree);
  PartyInvitationRequestMessage();

  QString name;

private:
  void _nameFunc(Reader *input);
};

#endif // PARTYINVITATIONREQUESTMESSAGE_H