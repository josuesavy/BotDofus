#include "ExchangeErrorMessage.h"

void ExchangeErrorMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeErrorMessage(output);
}

void ExchangeErrorMessage::serializeAs_ExchangeErrorMessage(Writer *output)
{
  output->writeByte(this->errorType);
}

void ExchangeErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeErrorMessage(input);
}

void ExchangeErrorMessage::deserializeAs_ExchangeErrorMessage(Reader *input)
{
  this->_errorTypeFunc(input);
}

void ExchangeErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeErrorMessage(tree);
}

void ExchangeErrorMessage::deserializeAsyncAs_ExchangeErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeErrorMessage::_errorTypeFunc, this, std::placeholders::_1));
}

void ExchangeErrorMessage::_errorTypeFunc(Reader *input)
{
  this->errorType = input->readByte();
}

ExchangeErrorMessage::ExchangeErrorMessage()
{
  m_type = MessageEnum::EXCHANGEERRORMESSAGE;
}

