#include "PartyRestrictedMessage.h"

void PartyRestrictedMessage::serialize(Writer *output)
{
  this->serializeAs_PartyRestrictedMessage(output);
}

void PartyRestrictedMessage::serializeAs_PartyRestrictedMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeBool(this->restricted);
}

void PartyRestrictedMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyRestrictedMessage(input);
}

void PartyRestrictedMessage::deserializeAs_PartyRestrictedMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_restrictedFunc(input);
}

void PartyRestrictedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyRestrictedMessage(tree);
}

void PartyRestrictedMessage::deserializeAsyncAs_PartyRestrictedMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyRestrictedMessage::_restrictedFunc, this, std::placeholders::_1));
}

void PartyRestrictedMessage::_restrictedFunc(Reader *input)
{
  this->restricted = input->readBool();
}

PartyRestrictedMessage::PartyRestrictedMessage()
{
  m_type = MessageEnum::PARTYRESTRICTEDMESSAGE;
}

