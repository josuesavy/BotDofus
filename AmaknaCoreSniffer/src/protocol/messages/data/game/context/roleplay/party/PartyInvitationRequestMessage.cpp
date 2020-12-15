#include "PartyInvitationRequestMessage.h"

void PartyInvitationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationRequestMessage(output);
}

void PartyInvitationRequestMessage::serializeAs_PartyInvitationRequestMessage(Writer *output)
{
  output->writeUTF(this->name);
}

void PartyInvitationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationRequestMessage(input);
}

void PartyInvitationRequestMessage::deserializeAs_PartyInvitationRequestMessage(Reader *input)
{
  this->_nameFunc(input);
}

void PartyInvitationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationRequestMessage(tree);
}

void PartyInvitationRequestMessage::deserializeAsyncAs_PartyInvitationRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PartyInvitationRequestMessage::_nameFunc, this, std::placeholders::_1));
}

void PartyInvitationRequestMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

PartyInvitationRequestMessage::PartyInvitationRequestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONREQUESTMESSAGE;
  m_needsHash = true;
}

