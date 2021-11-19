#include "PartyPledgeLoyaltyRequestMessage.h"

void PartyPledgeLoyaltyRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyPledgeLoyaltyRequestMessage(output);
}

void PartyPledgeLoyaltyRequestMessage::serializeAs_PartyPledgeLoyaltyRequestMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  output->writeBool(this->loyal);
}

void PartyPledgeLoyaltyRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyPledgeLoyaltyRequestMessage(input);
}

void PartyPledgeLoyaltyRequestMessage::deserializeAs_PartyPledgeLoyaltyRequestMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_loyalFunc(input);
}

void PartyPledgeLoyaltyRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyPledgeLoyaltyRequestMessage(tree);
}

void PartyPledgeLoyaltyRequestMessage::deserializeAsyncAs_PartyPledgeLoyaltyRequestMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyPledgeLoyaltyRequestMessage::_loyalFunc, this, std::placeholders::_1));
}

void PartyPledgeLoyaltyRequestMessage::_loyalFunc(Reader *input)
{
  this->loyal = input->readBool();
}

PartyPledgeLoyaltyRequestMessage::PartyPledgeLoyaltyRequestMessage()
{
  m_type = MessageEnum::PARTYPLEDGELOYALTYREQUESTMESSAGE;
}

