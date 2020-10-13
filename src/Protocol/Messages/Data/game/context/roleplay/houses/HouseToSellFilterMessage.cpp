#include "HouseToSellFilterMessage.h"

void HouseToSellFilterMessage::serialize(Writer *output)
{
  this->serializeAs_HouseToSellFilterMessage(output);
}

void HouseToSellFilterMessage::serializeAs_HouseToSellFilterMessage(Writer *output)
{
  output->writeInt((int)this->areaId);
  if(this->atLeastNbRoom < 0)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->atLeastNbRoom << ") on element atLeastNbRoom.";
  }
  output->writeByte(this->atLeastNbRoom);
  if(this->atLeastNbChest < 0)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->atLeastNbChest << ") on element atLeastNbChest.";
  }
  output->writeByte(this->atLeastNbChest);
  if(this->skillRequested < 0)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->skillRequested << ") on element skillRequested.";
  }
  output->writeVarShort((int)this->skillRequested);
  if(this->maxPrice < 0 || this->maxPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->maxPrice << ") on element maxPrice.";
  }
  output->writeVarLong((double)this->maxPrice);
  output->writeByte(this->orderBy);
}

void HouseToSellFilterMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseToSellFilterMessage(input);
}

void HouseToSellFilterMessage::deserializeAs_HouseToSellFilterMessage(Reader *input)
{
  this->_areaIdFunc(input);
  this->_atLeastNbRoomFunc(input);
  this->_atLeastNbChestFunc(input);
  this->_skillRequestedFunc(input);
  this->_maxPriceFunc(input);
  this->_orderByFunc(input);
}

void HouseToSellFilterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseToSellFilterMessage(tree);
}

void HouseToSellFilterMessage::deserializeAsyncAs_HouseToSellFilterMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseToSellFilterMessage::_areaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseToSellFilterMessage::_atLeastNbRoomFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseToSellFilterMessage::_atLeastNbChestFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseToSellFilterMessage::_skillRequestedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseToSellFilterMessage::_maxPriceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseToSellFilterMessage::_orderByFunc, this, std::placeholders::_1));
}

void HouseToSellFilterMessage::_areaIdFunc(Reader *input)
{
  this->areaId = input->readInt();
}

void HouseToSellFilterMessage::_atLeastNbRoomFunc(Reader *input)
{
  this->atLeastNbRoom = input->readByte();
  if(this->atLeastNbRoom < 0)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->atLeastNbRoom << ") on element of HouseToSellFilterMessage.atLeastNbRoom.";
  }
}

void HouseToSellFilterMessage::_atLeastNbChestFunc(Reader *input)
{
  this->atLeastNbChest = input->readByte();
  if(this->atLeastNbChest < 0)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->atLeastNbChest << ") on element of HouseToSellFilterMessage.atLeastNbChest.";
  }
}

void HouseToSellFilterMessage::_skillRequestedFunc(Reader *input)
{
  this->skillRequested = input->readVarUhShort();
  if(this->skillRequested < 0)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->skillRequested << ") on element of HouseToSellFilterMessage.skillRequested.";
  }
}

void HouseToSellFilterMessage::_maxPriceFunc(Reader *input)
{
  this->maxPrice = input->readVarUhLong();
  if(this->maxPrice < 0 || this->maxPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->maxPrice << ") on element of HouseToSellFilterMessage.maxPrice.";
  }
}

void HouseToSellFilterMessage::_orderByFunc(Reader *input)
{
  this->orderBy = input->readByte();
  if(this->orderBy < 0)
  {
    qDebug()<<"ERREUR - HouseToSellFilterMessage -"<<"Forbidden value (" << this->orderBy << ") on element of HouseToSellFilterMessage.orderBy.";
  }
}

HouseToSellFilterMessage::HouseToSellFilterMessage()
{
  m_type = MessageEnum::HOUSETOSELLFILTERMESSAGE;
}

