#include "ContactLookRequestByNameMessage.h"

void ContactLookRequestByNameMessage::serialize(Writer *output)
{
  this->serializeAs_ContactLookRequestByNameMessage(output);
}

void ContactLookRequestByNameMessage::serializeAs_ContactLookRequestByNameMessage(Writer *output)
{
  ContactLookRequestMessage::serializeAs_ContactLookRequestMessage(output);
  output->writeUTF(this->playerName);
}

void ContactLookRequestByNameMessage::deserialize(Reader *input)
{
  this->deserializeAs_ContactLookRequestByNameMessage(input);
}

void ContactLookRequestByNameMessage::deserializeAs_ContactLookRequestByNameMessage(Reader *input)
{
  ContactLookRequestMessage::deserialize(input);
  this->_playerNameFunc(input);
}

void ContactLookRequestByNameMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ContactLookRequestByNameMessage(tree);
}

void ContactLookRequestByNameMessage::deserializeAsyncAs_ContactLookRequestByNameMessage(FuncTree tree)
{
  ContactLookRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ContactLookRequestByNameMessage::_playerNameFunc, this, std::placeholders::_1));
}

void ContactLookRequestByNameMessage::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

ContactLookRequestByNameMessage::ContactLookRequestByNameMessage()
{
  m_type = MessageEnum::CONTACTLOOKREQUESTBYNAMEMESSAGE;
}

