#include "InviteInHavenBagMessage.h"

void InviteInHavenBagMessage::serialize(Writer *output)
{
  this->serializeAs_InviteInHavenBagMessage(output);
}

void InviteInHavenBagMessage::serializeAs_InviteInHavenBagMessage(Writer *output)
{
  this->guestInformations.serializeAs_CharacterMinimalInformations(output);
  output->writeBool(this->accept);
}

void InviteInHavenBagMessage::deserialize(Reader *input)
{
  this->deserializeAs_InviteInHavenBagMessage(input);
}

void InviteInHavenBagMessage::deserializeAs_InviteInHavenBagMessage(Reader *input)
{
  this->guestInformations = CharacterMinimalInformations();
  this->guestInformations.deserialize(input);
  this->_acceptFunc(input);
}

void InviteInHavenBagMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InviteInHavenBagMessage(tree);
}

void InviteInHavenBagMessage::deserializeAsyncAs_InviteInHavenBagMessage(FuncTree tree)
{
  this->_guestInformationstree = tree.addChild(std::bind(&InviteInHavenBagMessage::_guestInformationstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InviteInHavenBagMessage::_acceptFunc, this, std::placeholders::_1));
}

void InviteInHavenBagMessage::_guestInformationstreeFunc(Reader *input)
{
  this->guestInformations = CharacterMinimalInformations();
  this->guestInformations.deserializeAsync(this->_guestInformationstree);
}

void InviteInHavenBagMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

InviteInHavenBagMessage::InviteInHavenBagMessage()
{
  m_type = MessageEnum::INVITEINHAVENBAGMESSAGE;
}

