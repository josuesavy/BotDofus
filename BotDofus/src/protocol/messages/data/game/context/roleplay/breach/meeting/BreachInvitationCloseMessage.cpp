#include "BreachInvitationCloseMessage.h"

void BreachInvitationCloseMessage::serialize(Writer *output)
{
  this->serializeAs_BreachInvitationCloseMessage(output);
}

void BreachInvitationCloseMessage::serializeAs_BreachInvitationCloseMessage(Writer *output)
{
  this->host.serializeAs_CharacterMinimalInformations(output);
}

void BreachInvitationCloseMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachInvitationCloseMessage(input);
}

void BreachInvitationCloseMessage::deserializeAs_BreachInvitationCloseMessage(Reader *input)
{
  this->host = CharacterMinimalInformations();
  this->host.deserialize(input);
}

void BreachInvitationCloseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachInvitationCloseMessage(tree);
}

void BreachInvitationCloseMessage::deserializeAsyncAs_BreachInvitationCloseMessage(FuncTree tree)
{
  this->_hosttree = tree.addChild(std::bind(&BreachInvitationCloseMessage::_hosttreeFunc, this, std::placeholders::_1));
}

void BreachInvitationCloseMessage::_hosttreeFunc(Reader *input)
{
  this->host = CharacterMinimalInformations();
  this->host.deserializeAsync(this->_hosttree);
}

BreachInvitationCloseMessage::BreachInvitationCloseMessage()
{
  m_type = MessageEnum::BREACHINVITATIONCLOSEMESSAGE;
}

