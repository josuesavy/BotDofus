#ifndef PARTYINVITATIONREQUESTMESSAGE_H
#define PARTYINVITATIONREQUESTMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  QSharedPointer<AbstractPlayerSearchInformation> target;

private:
  void _targettreeFunc(Reader *input);

  FuncTree _targettree;
};

#endif // PARTYINVITATIONREQUESTMESSAGE_H