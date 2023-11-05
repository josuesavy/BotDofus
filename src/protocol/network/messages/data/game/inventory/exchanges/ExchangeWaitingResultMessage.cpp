#include "ExchangeWaitingResultMessage.h"

void ExchangeWaitingResultMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeWaitingResultMessage(output);
}

void ExchangeWaitingResultMessage::serializeAs_ExchangeWaitingResultMessage(Writer *output)
{
  output->writeBool(this->bwait);
}

void ExchangeWaitingResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeWaitingResultMessage(input);
}

void ExchangeWaitingResultMessage::deserializeAs_ExchangeWaitingResultMessage(Reader *input)
{
  this->_bwaitFunc(input);
}

void ExchangeWaitingResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeWaitingResultMessage(tree);
}

void ExchangeWaitingResultMessage::deserializeAsyncAs_ExchangeWaitingResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeWaitingResultMessage::_bwaitFunc, this, std::placeholders::_1));
}

void ExchangeWaitingResultMessage::_bwaitFunc(Reader *input)
{
  this->bwait = input->readBool();
}

ExchangeWaitingResultMessage::ExchangeWaitingResultMessage()
{
  m_type = MessageEnum::EXCHANGEWAITINGRESULTMESSAGE;
}

