#include "PartyNameSetRequestMessage.h"

void PartyNameSetRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyNameSetRequestMessage(output);
}

void PartyNameSetRequestMessage::serializeAs_PartyNameSetRequestMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeUTF(this->partyName);
}

void PartyNameSetRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyNameSetRequestMessage(input);
}

void PartyNameSetRequestMessage::deserializeAs_PartyNameSetRequestMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_partyNameFunc(input);
}

void PartyNameSetRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyNameSetRequestMessage(tree);
}

void PartyNameSetRequestMessage::deserializeAsyncAs_PartyNameSetRequestMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyNameSetRequestMessage::_partyNameFunc, this, std::placeholders::_1));
}

void PartyNameSetRequestMessage::_partyNameFunc(Reader *input)
{
  this->partyName = input->readUTF();
}

PartyNameSetRequestMessage::PartyNameSetRequestMessage()
{
  m_type = MessageEnum::PARTYNAMESETREQUESTMESSAGE;
}

