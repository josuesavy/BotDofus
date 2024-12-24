#include "ExchangeBidPriceMessage.h"

void ExchangeBidPriceMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidPriceMessage(output);
}

void ExchangeBidPriceMessage::serializeAs_ExchangeBidPriceMessage(Writer *output)
{
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidPriceMessage -"<<"Forbidden value (" << this->genericId << ") on element genericId.";
  }
  output->writeVarInt((int)this->genericId);
  if(this->averagePrice < -9007199254740992 || this->averagePrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeBidPriceMessage -"<<"Forbidden value (" << this->averagePrice << ") on element averagePrice.";
  }
  output->writeVarLong((double)this->averagePrice);
}

void ExchangeBidPriceMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidPriceMessage(input);
}

void ExchangeBidPriceMessage::deserializeAs_ExchangeBidPriceMessage(Reader *input)
{
  this->_genericIdFunc(input);
  this->_averagePriceFunc(input);
}

void ExchangeBidPriceMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidPriceMessage(tree);
}

void ExchangeBidPriceMessage::deserializeAsyncAs_ExchangeBidPriceMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidPriceMessage::_genericIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidPriceMessage::_averagePriceFunc, this, std::placeholders::_1));
}

void ExchangeBidPriceMessage::_genericIdFunc(Reader *input)
{
  this->genericId = input->readVarUhInt();
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidPriceMessage -"<<"Forbidden value (" << this->genericId << ") on element of ExchangeBidPriceMessage.genericId.";
  }
}

void ExchangeBidPriceMessage::_averagePriceFunc(Reader *input)
{
  this->averagePrice = input->readVarLong();
  if(this->averagePrice < -9007199254740992 || this->averagePrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeBidPriceMessage -"<<"Forbidden value (" << this->averagePrice << ") on element of ExchangeBidPriceMessage.averagePrice.";
  }
}

ExchangeBidPriceMessage::ExchangeBidPriceMessage()
{
  m_type = MessageEnum::EXCHANGEBIDPRICEMESSAGE;
}

