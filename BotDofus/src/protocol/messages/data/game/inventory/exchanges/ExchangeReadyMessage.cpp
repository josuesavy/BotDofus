#include "ExchangeReadyMessage.h"

void ExchangeReadyMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeReadyMessage(output);
}

void ExchangeReadyMessage::serializeAs_ExchangeReadyMessage(Writer *output)
{
  output->writeBool(this->ready);
  if(this->step < 0)
  {
    qDebug()<<"ERREUR - ExchangeReadyMessage -"<<"Forbidden value (" << this->step << ") on element step.";
  }
  output->writeVarShort((int)this->step);
}

void ExchangeReadyMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeReadyMessage(input);
}

void ExchangeReadyMessage::deserializeAs_ExchangeReadyMessage(Reader *input)
{
  this->_readyFunc(input);
  this->_stepFunc(input);
}

void ExchangeReadyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeReadyMessage(tree);
}

void ExchangeReadyMessage::deserializeAsyncAs_ExchangeReadyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeReadyMessage::_readyFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeReadyMessage::_stepFunc, this, std::placeholders::_1));
}

void ExchangeReadyMessage::_readyFunc(Reader *input)
{
  this->ready = input->readBool();
}

void ExchangeReadyMessage::_stepFunc(Reader *input)
{
  this->step = input->readVarUhShort();
  if(this->step < 0)
  {
    qDebug()<<"ERREUR - ExchangeReadyMessage -"<<"Forbidden value (" << this->step << ") on element of ExchangeReadyMessage.step.";
  }
}

ExchangeReadyMessage::ExchangeReadyMessage()
{
  m_type = MessageEnum::EXCHANGEREADYMESSAGE;
  m_needsHash = true;
}

