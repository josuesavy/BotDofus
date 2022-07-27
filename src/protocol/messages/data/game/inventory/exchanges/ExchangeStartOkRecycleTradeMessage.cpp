#include "ExchangeStartOkRecycleTradeMessage.h"

void ExchangeStartOkRecycleTradeMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkRecycleTradeMessage(output);
}

void ExchangeStartOkRecycleTradeMessage::serializeAs_ExchangeStartOkRecycleTradeMessage(Writer *output)
{
  if(this->percentToPrism < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPrism << ") on element percentToPrism.";
  }
  output->writeShort((short)this->percentToPrism);
  if(this->percentToPlayer < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPlayer << ") on element percentToPlayer.";
  }
  output->writeShort((short)this->percentToPlayer);
}

void ExchangeStartOkRecycleTradeMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkRecycleTradeMessage(input);
}

void ExchangeStartOkRecycleTradeMessage::deserializeAs_ExchangeStartOkRecycleTradeMessage(Reader *input)
{
  this->_percentToPrismFunc(input);
  this->_percentToPlayerFunc(input);
}

void ExchangeStartOkRecycleTradeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkRecycleTradeMessage(tree);
}

void ExchangeStartOkRecycleTradeMessage::deserializeAsyncAs_ExchangeStartOkRecycleTradeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeStartOkRecycleTradeMessage::_percentToPrismFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartOkRecycleTradeMessage::_percentToPlayerFunc, this, std::placeholders::_1));
}

void ExchangeStartOkRecycleTradeMessage::_percentToPrismFunc(Reader *input)
{
  this->percentToPrism = input->readShort();
  if(this->percentToPrism < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPrism << ") on element of ExchangeStartOkRecycleTradeMessage.percentToPrism.";
  }
}

void ExchangeStartOkRecycleTradeMessage::_percentToPlayerFunc(Reader *input)
{
  this->percentToPlayer = input->readShort();
  if(this->percentToPlayer < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkRecycleTradeMessage -"<<"Forbidden value (" << this->percentToPlayer << ") on element of ExchangeStartOkRecycleTradeMessage.percentToPlayer.";
  }
}

ExchangeStartOkRecycleTradeMessage::ExchangeStartOkRecycleTradeMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKRECYCLETRADEMESSAGE;
}

