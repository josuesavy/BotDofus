#include "ExchangeBidHousePriceMessage.h"

void ExchangeBidHousePriceMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHousePriceMessage(output);
}

void ExchangeBidHousePriceMessage::serializeAs_ExchangeBidHousePriceMessage(Writer *output)
{
  if(this->genId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHousePriceMessage -"<<"Forbidden value (" << this->genId << ") on element genId.";
  }
  output->writeVarShort((int)this->genId);
}

void ExchangeBidHousePriceMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHousePriceMessage(input);
}

void ExchangeBidHousePriceMessage::deserializeAs_ExchangeBidHousePriceMessage(Reader *input)
{
  this->_genIdFunc(input);
}

void ExchangeBidHousePriceMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHousePriceMessage(tree);
}

void ExchangeBidHousePriceMessage::deserializeAsyncAs_ExchangeBidHousePriceMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHousePriceMessage::_genIdFunc, this, std::placeholders::_1));
}

void ExchangeBidHousePriceMessage::_genIdFunc(Reader *input)
{
  this->genId = input->readVarUhShort();
  if(this->genId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHousePriceMessage -"<<"Forbidden value (" << this->genId << ") on element of ExchangeBidHousePriceMessage.genId.";
  }
}

ExchangeBidHousePriceMessage::ExchangeBidHousePriceMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEPRICEMESSAGE;
}

