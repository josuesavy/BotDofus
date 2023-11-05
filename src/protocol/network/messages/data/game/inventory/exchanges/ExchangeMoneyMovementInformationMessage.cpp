#include "ExchangeMoneyMovementInformationMessage.h"

void ExchangeMoneyMovementInformationMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMoneyMovementInformationMessage(output);
}

void ExchangeMoneyMovementInformationMessage::serializeAs_ExchangeMoneyMovementInformationMessage(Writer *output)
{
  if(this->limit < 0 || this->limit > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeMoneyMovementInformationMessage -"<<"Forbidden value (" << this->limit << ") on element limit.";
  }
  output->writeVarLong((double)this->limit);
}

void ExchangeMoneyMovementInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMoneyMovementInformationMessage(input);
}

void ExchangeMoneyMovementInformationMessage::deserializeAs_ExchangeMoneyMovementInformationMessage(Reader *input)
{
  this->_limitFunc(input);
}

void ExchangeMoneyMovementInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMoneyMovementInformationMessage(tree);
}

void ExchangeMoneyMovementInformationMessage::deserializeAsyncAs_ExchangeMoneyMovementInformationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeMoneyMovementInformationMessage::_limitFunc, this, std::placeholders::_1));
}

void ExchangeMoneyMovementInformationMessage::_limitFunc(Reader *input)
{
  this->limit = input->readVarUhLong();
  if(this->limit < 0 || this->limit > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeMoneyMovementInformationMessage -"<<"Forbidden value (" << this->limit << ") on element of ExchangeMoneyMovementInformationMessage.limit.";
  }
}

ExchangeMoneyMovementInformationMessage::ExchangeMoneyMovementInformationMessage()
{
  m_type = MessageEnum::EXCHANGEMONEYMOVEMENTINFORMATIONMESSAGE;
}

