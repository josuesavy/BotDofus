#include "BreachInvitationAnswerMessage.h"

void BreachInvitationAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_BreachInvitationAnswerMessage(output);
}

void BreachInvitationAnswerMessage::serializeAs_BreachInvitationAnswerMessage(Writer *output)
{
  output->writeBool(this->accept);
}

void BreachInvitationAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachInvitationAnswerMessage(input);
}

void BreachInvitationAnswerMessage::deserializeAs_BreachInvitationAnswerMessage(Reader *input)
{
  this->_acceptFunc(input);
}

void BreachInvitationAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachInvitationAnswerMessage(tree);
}

void BreachInvitationAnswerMessage::deserializeAsyncAs_BreachInvitationAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachInvitationAnswerMessage::_acceptFunc, this, std::placeholders::_1));
}

void BreachInvitationAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

BreachInvitationAnswerMessage::BreachInvitationAnswerMessage()
{
  m_type = MessageEnum::BREACHINVITATIONANSWERMESSAGE;
}

