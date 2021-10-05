#include "PartyLocateMembersRequestMessage.h"

void PartyLocateMembersRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyLocateMembersRequestMessage(output);
}

void PartyLocateMembersRequestMessage::serializeAs_PartyLocateMembersRequestMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
}

void PartyLocateMembersRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyLocateMembersRequestMessage(input);
}

void PartyLocateMembersRequestMessage::deserializeAs_PartyLocateMembersRequestMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
}

void PartyLocateMembersRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyLocateMembersRequestMessage(tree);
}

void PartyLocateMembersRequestMessage::deserializeAsyncAs_PartyLocateMembersRequestMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
}

PartyLocateMembersRequestMessage::PartyLocateMembersRequestMessage()
{
  m_type = MessageEnum::PARTYLOCATEMEMBERSREQUESTMESSAGE;
}

