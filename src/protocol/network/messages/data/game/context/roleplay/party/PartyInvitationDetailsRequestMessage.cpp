#include "PartyInvitationDetailsRequestMessage.h"

void PartyInvitationDetailsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationDetailsRequestMessage(output);
}

void PartyInvitationDetailsRequestMessage::serializeAs_PartyInvitationDetailsRequestMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
}

void PartyInvitationDetailsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationDetailsRequestMessage(input);
}

void PartyInvitationDetailsRequestMessage::deserializeAs_PartyInvitationDetailsRequestMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
}

void PartyInvitationDetailsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationDetailsRequestMessage(tree);
}

void PartyInvitationDetailsRequestMessage::deserializeAsyncAs_PartyInvitationDetailsRequestMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
}

PartyInvitationDetailsRequestMessage::PartyInvitationDetailsRequestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONDETAILSREQUESTMESSAGE;
}

