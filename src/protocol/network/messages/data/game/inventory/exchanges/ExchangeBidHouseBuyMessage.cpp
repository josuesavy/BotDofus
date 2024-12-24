#include "ExchangeBidHouseBuyMessage.h"

void ExchangeBidHouseBuyMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseBuyMessage(output);
}

void ExchangeBidHouseBuyMessage::serializeAs_ExchangeBidHouseBuyMessage(Writer *output)
{
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  output->writeVarInt((int)this->uid);
  if(this->qty < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->qty << ") on element qty.";
  }
  output->writeVarInt((int)this->qty);
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
}

void ExchangeBidHouseBuyMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseBuyMessage(input);
}

void ExchangeBidHouseBuyMessage::deserializeAs_ExchangeBidHouseBuyMessage(Reader *input)
{
  this->_uidFunc(input);
  this->_qtyFunc(input);
  this->_priceFunc(input);
}

void ExchangeBidHouseBuyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseBuyMessage(tree);
}

void ExchangeBidHouseBuyMessage::deserializeAsyncAs_ExchangeBidHouseBuyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseBuyMessage::_uidFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseBuyMessage::_qtyFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseBuyMessage::_priceFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseBuyMessage::_uidFunc(Reader *input)
{
  this->uid = input->readVarUhInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->uid << ") on element of ExchangeBidHouseBuyMessage.uid.";
  }
}

void ExchangeBidHouseBuyMessage::_qtyFunc(Reader *input)
{
  this->qty = input->readVarUhInt();
  if(this->qty < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->qty << ") on element of ExchangeBidHouseBuyMessage.qty.";
  }
}

void ExchangeBidHouseBuyMessage::_priceFunc(Reader *input)
{
  this->price = input->readVarUhLong();
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseBuyMessage -"<<"Forbidden value (" << this->price << ") on element of ExchangeBidHouseBuyMessage.price.";
  }
}

ExchangeBidHouseBuyMessage::ExchangeBidHouseBuyMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEBUYMESSAGE;
  m_needsHash = true;
}

