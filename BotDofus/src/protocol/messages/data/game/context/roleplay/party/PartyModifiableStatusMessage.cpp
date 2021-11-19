#include "PartyModifiableStatusMessage.h"

void PartyModifiableStatusMessage::serialize(Writer *output)
{
  this->serializeAs_PartyModifiableStatusMessage(output);
}

void PartyModifiableStatusMessage::serializeAs_PartyModifiableStatusMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeBool(this->enabled);
}

void PartyModifiableStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyModifiableStatusMessage(input);
}

void PartyModifiableStatusMessage::deserializeAs_PartyModifiableStatusMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_enabledFunc(input);
}

void PartyModifiableStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyModifiableStatusMessage(tree);
}

void PartyModifiableStatusMessage::deserializeAsyncAs_PartyModifiableStatusMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyModifiableStatusMessage::_enabledFunc, this, std::placeholders::_1));
}

void PartyModifiableStatusMessage::_enabledFunc(Reader *input)
{
  this->enabled = input->readBool();
}

PartyModifiableStatusMessage::PartyModifiableStatusMessage()
{
  m_type = MessageEnum::PARTYMODIFIABLESTATUSMESSAGE;
}

