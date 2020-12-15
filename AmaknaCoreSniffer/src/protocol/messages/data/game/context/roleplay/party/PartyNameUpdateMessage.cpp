#include "PartyNameUpdateMessage.h"

void PartyNameUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_PartyNameUpdateMessage(output);
}

void PartyNameUpdateMessage::serializeAs_PartyNameUpdateMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeUTF(this->partyName);
}

void PartyNameUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyNameUpdateMessage(input);
}

void PartyNameUpdateMessage::deserializeAs_PartyNameUpdateMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_partyNameFunc(input);
}

void PartyNameUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyNameUpdateMessage(tree);
}

void PartyNameUpdateMessage::deserializeAsyncAs_PartyNameUpdateMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyNameUpdateMessage::_partyNameFunc, this, std::placeholders::_1));
}

void PartyNameUpdateMessage::_partyNameFunc(Reader *input)
{
  this->partyName = input->readUTF();
}

PartyNameUpdateMessage::PartyNameUpdateMessage()
{
  m_type = MessageEnum::PARTYNAMEUPDATEMESSAGE;
}

