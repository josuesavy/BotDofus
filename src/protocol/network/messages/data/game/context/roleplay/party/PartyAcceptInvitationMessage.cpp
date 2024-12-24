#include "PartyAcceptInvitationMessage.h"

void PartyAcceptInvitationMessage::serialize(Writer *output)
{
  this->serializeAs_PartyAcceptInvitationMessage(output);
}

void PartyAcceptInvitationMessage::serializeAs_PartyAcceptInvitationMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
}

void PartyAcceptInvitationMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyAcceptInvitationMessage(input);
}

void PartyAcceptInvitationMessage::deserializeAs_PartyAcceptInvitationMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
}

void PartyAcceptInvitationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyAcceptInvitationMessage(tree);
}

void PartyAcceptInvitationMessage::deserializeAsyncAs_PartyAcceptInvitationMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
}

PartyAcceptInvitationMessage::PartyAcceptInvitationMessage()
{
  m_type = MessageEnum::PARTYACCEPTINVITATIONMESSAGE;
}

