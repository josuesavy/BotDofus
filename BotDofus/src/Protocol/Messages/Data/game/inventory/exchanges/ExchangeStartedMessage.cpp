#include "ExchangeStartedMessage.h"

void ExchangeStartedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartedMessage(output);
}

void ExchangeStartedMessage::serializeAs_ExchangeStartedMessage(Writer *output)
{
  output->writeByte(this->exchangeType);
}

void ExchangeStartedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartedMessage(input);
}

void ExchangeStartedMessage::deserializeAs_ExchangeStartedMessage(Reader *input)
{
  this->_exchangeTypeFunc(input);
}

void ExchangeStartedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartedMessage(tree);
}

void ExchangeStartedMessage::deserializeAsyncAs_ExchangeStartedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeStartedMessage::_exchangeTypeFunc, this, std::placeholders::_1));
}

void ExchangeStartedMessage::_exchangeTypeFunc(Reader *input)
{
  this->exchangeType = input->readByte();
}

ExchangeStartedMessage::ExchangeStartedMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDMESSAGE;
}

