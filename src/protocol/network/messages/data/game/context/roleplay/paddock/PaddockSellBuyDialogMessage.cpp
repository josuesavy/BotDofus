#include "PaddockSellBuyDialogMessage.h"

void PaddockSellBuyDialogMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockSellBuyDialogMessage(output);
}

void PaddockSellBuyDialogMessage::serializeAs_PaddockSellBuyDialogMessage(Writer *output)
{
  output->writeBool(this->bsell);
  if(this->ownerId < 0)
  {
    qDebug()<<"ERREUR - PaddockSellBuyDialogMessage -"<<"Forbidden value (" << this->ownerId << ") on element ownerId.";
  }
  output->writeVarInt((int)this->ownerId);
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockSellBuyDialogMessage -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
}

void PaddockSellBuyDialogMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockSellBuyDialogMessage(input);
}

void PaddockSellBuyDialogMessage::deserializeAs_PaddockSellBuyDialogMessage(Reader *input)
{
  this->_bsellFunc(input);
  this->_ownerIdFunc(input);
  this->_priceFunc(input);
}

void PaddockSellBuyDialogMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockSellBuyDialogMessage(tree);
}

void PaddockSellBuyDialogMessage::deserializeAsyncAs_PaddockSellBuyDialogMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockSellBuyDialogMessage::_bsellFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockSellBuyDialogMessage::_ownerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockSellBuyDialogMessage::_priceFunc, this, std::placeholders::_1));
}

void PaddockSellBuyDialogMessage::_bsellFunc(Reader *input)
{
  this->bsell = input->readBool();
}

void PaddockSellBuyDialogMessage::_ownerIdFunc(Reader *input)
{
  this->ownerId = input->readVarUhInt();
  if(this->ownerId < 0)
  {
    qDebug()<<"ERREUR - PaddockSellBuyDialogMessage -"<<"Forbidden value (" << this->ownerId << ") on element of PaddockSellBuyDialogMessage.ownerId.";
  }
}

void PaddockSellBuyDialogMessage::_priceFunc(Reader *input)
{
  this->price = input->readVarUhLong();
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - PaddockSellBuyDialogMessage -"<<"Forbidden value (" << this->price << ") on element of PaddockSellBuyDialogMessage.price.";
  }
}

PaddockSellBuyDialogMessage::PaddockSellBuyDialogMessage()
{
  m_type = MessageEnum::PADDOCKSELLBUYDIALOGMESSAGE;
}

