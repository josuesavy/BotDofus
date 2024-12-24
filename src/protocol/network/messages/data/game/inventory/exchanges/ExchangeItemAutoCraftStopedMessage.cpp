#include "ExchangeItemAutoCraftStopedMessage.h"

void ExchangeItemAutoCraftStopedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeItemAutoCraftStopedMessage(output);
}

void ExchangeItemAutoCraftStopedMessage::serializeAs_ExchangeItemAutoCraftStopedMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void ExchangeItemAutoCraftStopedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeItemAutoCraftStopedMessage(input);
}

void ExchangeItemAutoCraftStopedMessage::deserializeAs_ExchangeItemAutoCraftStopedMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void ExchangeItemAutoCraftStopedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeItemAutoCraftStopedMessage(tree);
}

void ExchangeItemAutoCraftStopedMessage::deserializeAsyncAs_ExchangeItemAutoCraftStopedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeItemAutoCraftStopedMessage::_reasonFunc, this, std::placeholders::_1));
}

void ExchangeItemAutoCraftStopedMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
}

ExchangeItemAutoCraftStopedMessage::ExchangeItemAutoCraftStopedMessage()
{
  m_type = MessageEnum::EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE;
}

