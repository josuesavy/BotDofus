#include "ExchangeBidPriceForSellerMessage.h"

void ExchangeBidPriceForSellerMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidPriceForSellerMessage(output);
}

void ExchangeBidPriceForSellerMessage::serializeAs_ExchangeBidPriceForSellerMessage(Writer *output)
{
  ExchangeBidPriceMessage::serializeAs_ExchangeBidPriceMessage(output);
  output->writeBool(this->allIdentical);
  output->writeShort((short)this->minimalPrices.size());
  for(uint _i2 = 0; _i2 < this->minimalPrices.size(); _i2++)
  {
    if(this->minimalPrices[_i2] < 0 || this->minimalPrices[_i2] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ExchangeBidPriceForSellerMessage -"<<"Forbidden value (" << this->minimalPrices[_i2] << ") on element 2 (starting at 1) of minimalPrices.";
    }
    output->writeVarLong((double)this->minimalPrices[_i2]);
  }
}

void ExchangeBidPriceForSellerMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidPriceForSellerMessage(input);
}

void ExchangeBidPriceForSellerMessage::deserializeAs_ExchangeBidPriceForSellerMessage(Reader *input)
{
  auto _val2 = NULL;
  ExchangeBidPriceMessage::deserialize(input);
  this->_allIdenticalFunc(input);
  uint _minimalPricesLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _minimalPricesLen; _i2++)
  {
    _val2 = input->readVarUhLong();
    if(_val2 < 0 || _val2 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ExchangeBidPriceForSellerMessage -"<<"Forbidden value (" << _val2 << ") on elements of minimalPrices.";
    }
    this->minimalPrices.append(_val2);
  }
}

void ExchangeBidPriceForSellerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidPriceForSellerMessage(tree);
}

void ExchangeBidPriceForSellerMessage::deserializeAsyncAs_ExchangeBidPriceForSellerMessage(FuncTree tree)
{
  ExchangeBidPriceMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeBidPriceForSellerMessage::_allIdenticalFunc, this, std::placeholders::_1));
  this->_minimalPricestree = tree.addChild(std::bind(&ExchangeBidPriceForSellerMessage::_minimalPricestreeFunc, this, std::placeholders::_1));
}

void ExchangeBidPriceForSellerMessage::_allIdenticalFunc(Reader *input)
{
  this->allIdentical = input->readBool();
}

void ExchangeBidPriceForSellerMessage::_minimalPricestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_minimalPricestree.addChild(std::bind(&ExchangeBidPriceForSellerMessage::_minimalPricesFunc, this, std::placeholders::_1));
  }
}

void ExchangeBidPriceForSellerMessage::_minimalPricesFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeBidPriceForSellerMessage -"<<"Forbidden value (" << _val << ") on elements of minimalPrices.";
  }
  this->minimalPrices.append(_val);
}

ExchangeBidPriceForSellerMessage::ExchangeBidPriceForSellerMessage()
{
  m_type = MessageEnum::EXCHANGEBIDPRICEFORSELLERMESSAGE;
}

