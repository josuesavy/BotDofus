#include "PartyLoyaltyStatusMessage.h"

void PartyLoyaltyStatusMessage::serialize(Writer *output)
{
  this->serializeAs_PartyLoyaltyStatusMessage(output);
}

void PartyLoyaltyStatusMessage::serializeAs_PartyLoyaltyStatusMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeBool(this->loyal);
}

void PartyLoyaltyStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyLoyaltyStatusMessage(input);
}

void PartyLoyaltyStatusMessage::deserializeAs_PartyLoyaltyStatusMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_loyalFunc(input);
}

void PartyLoyaltyStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyLoyaltyStatusMessage(tree);
}

void PartyLoyaltyStatusMessage::deserializeAsyncAs_PartyLoyaltyStatusMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyLoyaltyStatusMessage::_loyalFunc, this, std::placeholders::_1));
}

void PartyLoyaltyStatusMessage::_loyalFunc(Reader *input)
{
  this->loyal = input->readBool();
}

PartyLoyaltyStatusMessage::PartyLoyaltyStatusMessage()
{
  m_type = MessageEnum::PARTYLOYALTYSTATUSMESSAGE;
}

