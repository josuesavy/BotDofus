#include "ExchangeCraftPaymentModifiedMessage.h"

void ExchangeCraftPaymentModifiedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCraftPaymentModifiedMessage(output);
}

void ExchangeCraftPaymentModifiedMessage::serializeAs_ExchangeCraftPaymentModifiedMessage(Writer *output)
{
  if(this->goldSum < 0 || this->goldSum > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeCraftPaymentModifiedMessage -"<<"Forbidden value (" << this->goldSum << ") on element goldSum.";
  }
  output->writeVarLong((double)this->goldSum);
}

void ExchangeCraftPaymentModifiedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCraftPaymentModifiedMessage(input);
}

void ExchangeCraftPaymentModifiedMessage::deserializeAs_ExchangeCraftPaymentModifiedMessage(Reader *input)
{
  this->_goldSumFunc(input);
}

void ExchangeCraftPaymentModifiedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCraftPaymentModifiedMessage(tree);
}

void ExchangeCraftPaymentModifiedMessage::deserializeAsyncAs_ExchangeCraftPaymentModifiedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeCraftPaymentModifiedMessage::_goldSumFunc, this, std::placeholders::_1));
}

void ExchangeCraftPaymentModifiedMessage::_goldSumFunc(Reader *input)
{
  this->goldSum = input->readVarUhLong();
  if(this->goldSum < 0 || this->goldSum > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeCraftPaymentModifiedMessage -"<<"Forbidden value (" << this->goldSum << ") on element of ExchangeCraftPaymentModifiedMessage.goldSum.";
  }
}

ExchangeCraftPaymentModifiedMessage::ExchangeCraftPaymentModifiedMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE;
}

