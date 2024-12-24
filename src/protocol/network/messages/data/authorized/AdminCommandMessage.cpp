#include "AdminCommandMessage.h"

void AdminCommandMessage::serialize(Writer *output)
{
  this->serializeAs_AdminCommandMessage(output);
}

void AdminCommandMessage::serializeAs_AdminCommandMessage(Writer *output)
{
  this->messageUuid.serializeAs_Uuid(output);
  output->writeUTF(this->content);
}

void AdminCommandMessage::deserialize(Reader *input)
{
  this->deserializeAs_AdminCommandMessage(input);
}

void AdminCommandMessage::deserializeAs_AdminCommandMessage(Reader *input)
{
  this->messageUuid = Uuid();
  this->messageUuid.deserialize(input);
  this->_contentFunc(input);
}

void AdminCommandMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AdminCommandMessage(tree);
}

void AdminCommandMessage::deserializeAsyncAs_AdminCommandMessage(FuncTree tree)
{
  this->_messageUuidtree = tree.addChild(std::bind(&AdminCommandMessage::_messageUuidtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AdminCommandMessage::_contentFunc, this, std::placeholders::_1));
}

void AdminCommandMessage::_messageUuidtreeFunc(Reader *input)
{
  this->messageUuid = Uuid();
  this->messageUuid.deserializeAsync(this->_messageUuidtree);
}

void AdminCommandMessage::_contentFunc(Reader *input)
{
  this->content = input->readUTF();
}

AdminCommandMessage::AdminCommandMessage()
{
  m_type = MessageEnum::ADMINCOMMANDMESSAGE;
}

