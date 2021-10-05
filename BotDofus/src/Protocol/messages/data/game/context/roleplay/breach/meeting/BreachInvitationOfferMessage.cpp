#include "BreachInvitationOfferMessage.h"

void BreachInvitationOfferMessage::serialize(Writer *output)
{
  this->serializeAs_BreachInvitationOfferMessage(output);
}

void BreachInvitationOfferMessage::serializeAs_BreachInvitationOfferMessage(Writer *output)
{
  this->host.serializeAs_CharacterMinimalInformations(output);
  if(this->timeLeftBeforeCancel < 0)
  {
    qDebug()<<"ERREUR - BreachInvitationOfferMessage -"<<"Forbidden value (" << this->timeLeftBeforeCancel << ") on element timeLeftBeforeCancel.";
  }
  output->writeVarInt((int)this->timeLeftBeforeCancel);
}

void BreachInvitationOfferMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachInvitationOfferMessage(input);
}

void BreachInvitationOfferMessage::deserializeAs_BreachInvitationOfferMessage(Reader *input)
{
  this->host = CharacterMinimalInformations();
  this->host.deserialize(input);
  this->_timeLeftBeforeCancelFunc(input);
}

void BreachInvitationOfferMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachInvitationOfferMessage(tree);
}

void BreachInvitationOfferMessage::deserializeAsyncAs_BreachInvitationOfferMessage(FuncTree tree)
{
  this->_hosttree = tree.addChild(std::bind(&BreachInvitationOfferMessage::_hosttreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachInvitationOfferMessage::_timeLeftBeforeCancelFunc, this, std::placeholders::_1));
}

void BreachInvitationOfferMessage::_hosttreeFunc(Reader *input)
{
  this->host = CharacterMinimalInformations();
  this->host.deserializeAsync(this->_hosttree);
}

void BreachInvitationOfferMessage::_timeLeftBeforeCancelFunc(Reader *input)
{
  this->timeLeftBeforeCancel = input->readVarUhInt();
  if(this->timeLeftBeforeCancel < 0)
  {
    qDebug()<<"ERREUR - BreachInvitationOfferMessage -"<<"Forbidden value (" << this->timeLeftBeforeCancel << ") on element of BreachInvitationOfferMessage.timeLeftBeforeCancel.";
  }
}

BreachInvitationOfferMessage::BreachInvitationOfferMessage()
{
  m_type = MessageEnum::BREACHINVITATIONOFFERMESSAGE;
}

