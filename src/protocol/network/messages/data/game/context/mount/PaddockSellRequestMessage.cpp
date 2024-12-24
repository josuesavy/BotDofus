#include "PaddockSellRequestMessage.h"

void PaddockSellRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockSellRequestMessage(output);
}

void PaddockSellRequestMessage::serializeAs_PaddockSellRequestMessage(Writer *output)
{
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockSellRequestMessage -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
  output->writeBool(this->forSale);
}

void PaddockSellRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockSellRequestMessage(input);
}

void PaddockSellRequestMessage::deserializeAs_PaddockSellRequestMessage(Reader *input)
{
  this->_priceFunc(input);
  this->_forSaleFunc(input);
}

void PaddockSellRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockSellRequestMessage(tree);
}

void PaddockSellRequestMessage::deserializeAsyncAs_PaddockSellRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockSellRequestMessage::_priceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockSellRequestMessage::_forSaleFunc, this, std::placeholders::_1));
}

void PaddockSellRequestMessage::_priceFunc(Reader *input)
{
  this->price = input->readVarUhLong();
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockSellRequestMessage -"<<"Forbidden value (" << this->price << ") on element of PaddockSellRequestMessage.price.";
  }
}

void PaddockSellRequestMessage::_forSaleFunc(Reader *input)
{
  this->forSale = input->readBool();
}

PaddockSellRequestMessage::PaddockSellRequestMessage()
{
  m_type = MessageEnum::PADDOCKSELLREQUESTMESSAGE;
}

