#include "PartyInvitationRequestMessage.h"

void PartyInvitationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationRequestMessage(output);
}

void PartyInvitationRequestMessage::serializeAs_PartyInvitationRequestMessage(Writer *output)
{
  output->writeShort((short)this->target->getTypes().last());
  this->target->serialize(output);
}

void PartyInvitationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationRequestMessage(input);
}

void PartyInvitationRequestMessage::deserializeAs_PartyInvitationRequestMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->target->deserialize(input);
}

void PartyInvitationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationRequestMessage(tree);
}

void PartyInvitationRequestMessage::deserializeAsyncAs_PartyInvitationRequestMessage(FuncTree tree)
{
  this->_targettree = tree.addChild(std::bind(&PartyInvitationRequestMessage::_targettreeFunc, this, std::placeholders::_1));
}

void PartyInvitationRequestMessage::_targettreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->target->deserializeAsync(this->_targettree);
}

PartyInvitationRequestMessage::PartyInvitationRequestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONREQUESTMESSAGE;
  m_needsHash = true;
}

