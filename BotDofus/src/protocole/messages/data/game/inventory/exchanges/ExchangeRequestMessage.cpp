#include "ExchangeRequestMessage.h"

void ExchangeRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeRequestMessage(output);
}

void ExchangeRequestMessage::serializeAs_ExchangeRequestMessage(Writer *output)
{
  output->writeByte(this->exchangeType);
}

void ExchangeRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeRequestMessage(input);
}

void ExchangeRequestMessage::deserializeAs_ExchangeRequestMessage(Reader *input)
{
  this->_exchangeTypeFunc(input);
}

void ExchangeRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeRequestMessage(tree);
}

void ExchangeRequestMessage::deserializeAsyncAs_ExchangeRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeRequestMessage::_exchangeTypeFunc, this, std::placeholders::_1));
}

void ExchangeRequestMessage::_exchangeTypeFunc(Reader *input)
{
  this->exchangeType = input->readByte();
}

ExchangeRequestMessage::ExchangeRequestMessage()
{
  m_type = MessageEnum::EXCHANGEREQUESTMESSAGE;
}

