#include "HouseSellingUpdateMessage.h"

void HouseSellingUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_HouseSellingUpdateMessage(output);
}

void HouseSellingUpdateMessage::serializeAs_HouseSellingUpdateMessage(Writer *output)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseSellingUpdateMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  output->writeVarInt((int)this->houseId);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseSellingUpdateMessage -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  output->writeBool(this->secondHand);
  if(this->realPrice < 0 || this->realPrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - HouseSellingUpdateMessage -"<<"Forbidden value (" << this->realPrice << ") on element realPrice.";
  }
  output->writeVarLong((double)this->realPrice);
  this->buyerTag.serializeAs_AccountTagInformation(output);
}

void HouseSellingUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseSellingUpdateMessage(input);
}

void HouseSellingUpdateMessage::deserializeAs_HouseSellingUpdateMessage(Reader *input)
{
  this->_houseIdFunc(input);
  this->_instanceIdFunc(input);
  this->_secondHandFunc(input);
  this->_realPriceFunc(input);
  this->buyerTag = AccountTagInformation();
  this->buyerTag.deserialize(input);
}

void HouseSellingUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseSellingUpdateMessage(tree);
}

void HouseSellingUpdateMessage::deserializeAsyncAs_HouseSellingUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseSellingUpdateMessage::_houseIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseSellingUpdateMessage::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseSellingUpdateMessage::_secondHandFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseSellingUpdateMessage::_realPriceFunc, this, std::placeholders::_1));
  this->_buyerTagtree = tree.addChild(std::bind(&HouseSellingUpdateMessage::_buyerTagtreeFunc, this, std::placeholders::_1));
}

void HouseSellingUpdateMessage::_houseIdFunc(Reader *input)
{
  this->houseId = input->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseSellingUpdateMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseSellingUpdateMessage.houseId.";
  }
}

void HouseSellingUpdateMessage::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseSellingUpdateMessage -"<<"Forbidden value (" << this->instanceId << ") on element of HouseSellingUpdateMessage.instanceId.";
  }
}

void HouseSellingUpdateMessage::_secondHandFunc(Reader *input)
{
  this->secondHand = input->readBool();
}

void HouseSellingUpdateMessage::_realPriceFunc(Reader *input)
{
  this->realPrice = input->readVarUhLong();
  if(this->realPrice < 0 || this->realPrice > 9007199254740992)
  {
    qDebug()<<"ERREUR - HouseSellingUpdateMessage -"<<"Forbidden value (" << this->realPrice << ") on element of HouseSellingUpdateMessage.realPrice.";
  }
}

void HouseSellingUpdateMessage::_buyerTagtreeFunc(Reader *input)
{
  this->buyerTag = AccountTagInformation();
  this->buyerTag.deserializeAsync(this->_buyerTagtree);
}

HouseSellingUpdateMessage::HouseSellingUpdateMessage()
{
  m_type = MessageEnum::HOUSESELLINGUPDATEMESSAGE;
}

