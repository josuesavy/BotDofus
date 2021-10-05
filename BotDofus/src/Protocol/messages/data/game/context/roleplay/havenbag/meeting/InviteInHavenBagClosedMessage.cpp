#include "InviteInHavenBagClosedMessage.h"

void InviteInHavenBagClosedMessage::serialize(Writer *output)
{
  this->serializeAs_InviteInHavenBagClosedMessage(output);
}

void InviteInHavenBagClosedMessage::serializeAs_InviteInHavenBagClosedMessage(Writer *output)
{
  this->hostInformations.serializeAs_CharacterMinimalInformations(output);
}

void InviteInHavenBagClosedMessage::deserialize(Reader *input)
{
  this->deserializeAs_InviteInHavenBagClosedMessage(input);
}

void InviteInHavenBagClosedMessage::deserializeAs_InviteInHavenBagClosedMessage(Reader *input)
{
  this->hostInformations = CharacterMinimalInformations();
  this->hostInformations.deserialize(input);
}

void InviteInHavenBagClosedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InviteInHavenBagClosedMessage(tree);
}

void InviteInHavenBagClosedMessage::deserializeAsyncAs_InviteInHavenBagClosedMessage(FuncTree tree)
{
  this->_hostInformationstree = tree.addChild(std::bind(&InviteInHavenBagClosedMessage::_hostInformationstreeFunc, this, std::placeholders::_1));
}

void InviteInHavenBagClosedMessage::_hostInformationstreeFunc(Reader *input)
{
  this->hostInformations = CharacterMinimalInformations();
  this->hostInformations.deserializeAsync(this->_hostInformationstree);
}

InviteInHavenBagClosedMessage::InviteInHavenBagClosedMessage()
{
  m_type = MessageEnum::INVITEINHAVENBAGCLOSEDMESSAGE;
}

