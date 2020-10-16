#include "PartyUpdateMessage.h"

void PartyUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_PartyUpdateMessage(output);
}

void PartyUpdateMessage::serializeAs_PartyUpdateMessage(Writer *output)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(output);
  output->writeShort((short)this->memberInformations->getTypes().last());
  this->memberInformations->serialize(output);
}

void PartyUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyUpdateMessage(input);
}

void PartyUpdateMessage::deserializeAs_PartyUpdateMessage(Reader *input)
{
  AbstractPartyEventMessage::deserialize(input);
  uint _id1 = input->readUShort();
  this->memberInformations = qSharedPointerCast<PartyMemberInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->memberInformations->deserialize(input);
}

void PartyUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyUpdateMessage(tree);
}

void PartyUpdateMessage::deserializeAsyncAs_PartyUpdateMessage(FuncTree tree)
{
  AbstractPartyEventMessage::deserializeAsync(tree);
  this->_memberInformationstree = tree.addChild(std::bind(&PartyUpdateMessage::_memberInformationstreeFunc, this, std::placeholders::_1));
}

void PartyUpdateMessage::_memberInformationstreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->memberInformations = qSharedPointerCast<PartyMemberInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->memberInformations->deserializeAsync(this->_memberInformationstree);
}

PartyUpdateMessage::PartyUpdateMessage()
{
  m_type = MessageEnum::PARTYUPDATEMESSAGE;
}

