#include "ExchangeRequestedMessage.h"

void ExchangeRequestedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeRequestedMessage(output);
}

void ExchangeRequestedMessage::serializeAs_ExchangeRequestedMessage(Writer *output)
{
  output->writeByte(this->exchangeType);
}

void ExchangeRequestedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeRequestedMessage(input);
}

void ExchangeRequestedMessage::deserializeAs_ExchangeRequestedMessage(Reader *input)
{
  this->_exchangeTypeFunc(input);
}

void ExchangeRequestedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeRequestedMessage(tree);
}

void ExchangeRequestedMessage::deserializeAsyncAs_ExchangeRequestedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeRequestedMessage::_exchangeTypeFunc, this, std::placeholders::_1));
}

void ExchangeRequestedMessage::_exchangeTypeFunc(Reader *input)
{
  this->exchangeType = input->readByte();
}

ExchangeRequestedMessage::ExchangeRequestedMessage()
{
  m_type = MessageEnum::EXCHANGEREQUESTEDMESSAGE;
}

