#include "PartyRefuseInvitationMessage.h"

void PartyRefuseInvitationMessage::serialize(Writer *output)
{
  this->serializeAs_PartyRefuseInvitationMessage(output);
}

void PartyRefuseInvitationMessage::serializeAs_PartyRefuseInvitationMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
}

void PartyRefuseInvitationMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyRefuseInvitationMessage(input);
}

void PartyRefuseInvitationMessage::deserializeAs_PartyRefuseInvitationMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
}

void PartyRefuseInvitationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyRefuseInvitationMessage(tree);
}

void PartyRefuseInvitationMessage::deserializeAsyncAs_PartyRefuseInvitationMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
}

PartyRefuseInvitationMessage::PartyRefuseInvitationMessage()
{
  m_type = MessageEnum::PARTYREFUSEINVITATIONMESSAGE;
}

