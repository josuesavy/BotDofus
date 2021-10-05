#include "BasicPingMessage.h"

void BasicPingMessage::serialize(Writer *output)
{
  this->serializeAs_BasicPingMessage(output);
}

void BasicPingMessage::serializeAs_BasicPingMessage(Writer *output)
{
  output->writeBool(this->quiet);
}

void BasicPingMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicPingMessage(input);
}

void BasicPingMessage::deserializeAs_BasicPingMessage(Reader *input)
{
  this->_quietFunc(input);
}

void BasicPingMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicPingMessage(tree);
}

void BasicPingMessage::deserializeAsyncAs_BasicPingMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicPingMessage::_quietFunc, this, std::placeholders::_1));
}

void BasicPingMessage::_quietFunc(Reader *input)
{
  this->quiet = input->readBool();
}

BasicPingMessage::BasicPingMessage()
{
  m_type = MessageEnum::BASICPINGMESSAGE;
}

