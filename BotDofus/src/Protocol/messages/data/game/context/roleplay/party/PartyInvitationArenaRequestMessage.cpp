#include "PartyInvitationArenaRequestMessage.h"

void PartyInvitationArenaRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationArenaRequestMessage(output);
}

void PartyInvitationArenaRequestMessage::serializeAs_PartyInvitationArenaRequestMessage(Writer *output)
{
  PartyInvitationRequestMessage::serializeAs_PartyInvitationRequestMessage(output);
}

void PartyInvitationArenaRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationArenaRequestMessage(input);
}

void PartyInvitationArenaRequestMessage::deserializeAs_PartyInvitationArenaRequestMessage(Reader *input)
{
  PartyInvitationRequestMessage::deserialize(input);
}

void PartyInvitationArenaRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationArenaRequestMessage(tree);
}

void PartyInvitationArenaRequestMessage::deserializeAsyncAs_PartyInvitationArenaRequestMessage(FuncTree tree)
{
  PartyInvitationRequestMessage::deserializeAsync(tree);
}

PartyInvitationArenaRequestMessage::PartyInvitationArenaRequestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONARENAREQUESTMESSAGE;
  m_needsHash = true;
}

