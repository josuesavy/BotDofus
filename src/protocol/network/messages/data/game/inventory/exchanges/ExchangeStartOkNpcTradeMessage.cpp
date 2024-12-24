#include "ExchangeStartOkNpcTradeMessage.h"

void ExchangeStartOkNpcTradeMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkNpcTradeMessage(output);
}

void ExchangeStartOkNpcTradeMessage::serializeAs_ExchangeStartOkNpcTradeMessage(Writer *output)
{
  if(this->npcId < -9007199254740992 || this->npcId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcTradeMessage -"<<"Forbidden value (" << this->npcId << ") on element npcId.";
  }
  output->writeDouble(this->npcId);
}

void ExchangeStartOkNpcTradeMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkNpcTradeMessage(input);
}

void ExchangeStartOkNpcTradeMessage::deserializeAs_ExchangeStartOkNpcTradeMessage(Reader *input)
{
  this->_npcIdFunc(input);
}

void ExchangeStartOkNpcTradeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkNpcTradeMessage(tree);
}

void ExchangeStartOkNpcTradeMessage::deserializeAsyncAs_ExchangeStartOkNpcTradeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeStartOkNpcTradeMessage::_npcIdFunc, this, std::placeholders::_1));
}

void ExchangeStartOkNpcTradeMessage::_npcIdFunc(Reader *input)
{
  this->npcId = input->readDouble();
  if(this->npcId < -9007199254740992 || this->npcId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcTradeMessage -"<<"Forbidden value (" << this->npcId << ") on element of ExchangeStartOkNpcTradeMessage.npcId.";
  }
}

ExchangeStartOkNpcTradeMessage::ExchangeStartOkNpcTradeMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKNPCTRADEMESSAGE;
}

