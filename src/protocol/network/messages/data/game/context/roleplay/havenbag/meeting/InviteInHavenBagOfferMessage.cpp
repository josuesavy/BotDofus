#include "InviteInHavenBagOfferMessage.h"

void InviteInHavenBagOfferMessage::serialize(Writer *output)
{
  this->serializeAs_InviteInHavenBagOfferMessage(output);
}

void InviteInHavenBagOfferMessage::serializeAs_InviteInHavenBagOfferMessage(Writer *output)
{
  this->hostInformations.serializeAs_CharacterMinimalInformations(output);
  output->writeVarInt((int)this->timeLeftBeforeCancel);
}

void InviteInHavenBagOfferMessage::deserialize(Reader *input)
{
  this->deserializeAs_InviteInHavenBagOfferMessage(input);
}

void InviteInHavenBagOfferMessage::deserializeAs_InviteInHavenBagOfferMessage(Reader *input)
{
  this->hostInformations = CharacterMinimalInformations();
  this->hostInformations.deserialize(input);
  this->_timeLeftBeforeCancelFunc(input);
}

void InviteInHavenBagOfferMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InviteInHavenBagOfferMessage(tree);
}

void InviteInHavenBagOfferMessage::deserializeAsyncAs_InviteInHavenBagOfferMessage(FuncTree tree)
{
  this->_hostInformationstree = tree.addChild(std::bind(&InviteInHavenBagOfferMessage::_hostInformationstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InviteInHavenBagOfferMessage::_timeLeftBeforeCancelFunc, this, std::placeholders::_1));
}

void InviteInHavenBagOfferMessage::_hostInformationstreeFunc(Reader *input)
{
  this->hostInformations = CharacterMinimalInformations();
  this->hostInformations.deserializeAsync(this->_hostInformationstree);
}

void InviteInHavenBagOfferMessage::_timeLeftBeforeCancelFunc(Reader *input)
{
  this->timeLeftBeforeCancel = input->readVarInt();
}

InviteInHavenBagOfferMessage::InviteInHavenBagOfferMessage()
{
  m_type = MessageEnum::INVITEINHAVENBAGOFFERMESSAGE;
}

