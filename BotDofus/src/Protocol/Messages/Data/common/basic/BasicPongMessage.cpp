#include "BasicPongMessage.h"

void BasicPongMessage::serialize(Writer *output)
{
  this->serializeAs_BasicPongMessage(output);
}

void BasicPongMessage::serializeAs_BasicPongMessage(Writer *output)
{
  output->writeBool(this->quiet);
}

void BasicPongMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicPongMessage(input);
}

void BasicPongMessage::deserializeAs_BasicPongMessage(Reader *input)
{
  this->_quietFunc(input);
}

void BasicPongMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicPongMessage(tree);
}

void BasicPongMessage::deserializeAsyncAs_BasicPongMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicPongMessage::_quietFunc, this, std::placeholders::_1));
}

void BasicPongMessage::_quietFunc(Reader *input)
{
  this->quiet = input->readBool();
}

BasicPongMessage::BasicPongMessage()
{
  m_type = MessageEnum::BASICPONGMESSAGE;
}

