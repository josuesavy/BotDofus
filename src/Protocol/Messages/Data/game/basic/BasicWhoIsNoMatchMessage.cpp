#include "BasicWhoIsNoMatchMessage.h"

void BasicWhoIsNoMatchMessage::serialize(Writer *output)
{
  this->serializeAs_BasicWhoIsNoMatchMessage(output);
}

void BasicWhoIsNoMatchMessage::serializeAs_BasicWhoIsNoMatchMessage(Writer *output)
{
  output->writeUTF(this->search);
}

void BasicWhoIsNoMatchMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicWhoIsNoMatchMessage(input);
}

void BasicWhoIsNoMatchMessage::deserializeAs_BasicWhoIsNoMatchMessage(Reader *input)
{
  this->_searchFunc(input);
}

void BasicWhoIsNoMatchMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicWhoIsNoMatchMessage(tree);
}

void BasicWhoIsNoMatchMessage::deserializeAsyncAs_BasicWhoIsNoMatchMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicWhoIsNoMatchMessage::_searchFunc, this, std::placeholders::_1));
}

void BasicWhoIsNoMatchMessage::_searchFunc(Reader *input)
{
  this->search = input->readUTF();
}

BasicWhoIsNoMatchMessage::BasicWhoIsNoMatchMessage()
{
  m_type = MessageEnum::BASICWHOISNOMATCHMESSAGE;
}

