#include "BreachInvitationResponseMessage.h"

void BreachInvitationResponseMessage::serialize(Writer *output)
{
  this->serializeAs_BreachInvitationResponseMessage(output);
}

void BreachInvitationResponseMessage::serializeAs_BreachInvitationResponseMessage(Writer *output)
{
  this->guest.serializeAs_CharacterMinimalInformations(output);
  output->writeBool(this->accept);
}

void BreachInvitationResponseMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachInvitationResponseMessage(input);
}

void BreachInvitationResponseMessage::deserializeAs_BreachInvitationResponseMessage(Reader *input)
{
  this->guest = CharacterMinimalInformations();
  this->guest.deserialize(input);
  this->_acceptFunc(input);
}

void BreachInvitationResponseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachInvitationResponseMessage(tree);
}

void BreachInvitationResponseMessage::deserializeAsyncAs_BreachInvitationResponseMessage(FuncTree tree)
{
  this->_guesttree = tree.addChild(std::bind(&BreachInvitationResponseMessage::_guesttreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachInvitationResponseMessage::_acceptFunc, this, std::placeholders::_1));
}

void BreachInvitationResponseMessage::_guesttreeFunc(Reader *input)
{
  this->guest = CharacterMinimalInformations();
  this->guest.deserializeAsync(this->_guesttree);
}

void BreachInvitationResponseMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

BreachInvitationResponseMessage::BreachInvitationResponseMessage()
{
  m_type = MessageEnum::BREACHINVITATIONRESPONSEMESSAGE;
}

