#include "HouseInformationsForSell.h"

void HouseInformationsForSell::serialize(Writer *output)
{
  this->serializeAs_HouseInformationsForSell(output);
}

void HouseInformationsForSell::serializeAs_HouseInformationsForSell(Writer *output)
{
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  output->writeBool(this->secondHand);
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
  }
  output->writeVarInt((int)this->modelId);
  output->writeUTF(this->ownerName);
  output->writeUTF(this->ownerCharacterName);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeByte(this->nbRoom);
  output->writeByte(this->nbChest);
  output->writeShort((short)this->skillListIds.size());
  for(uint _i11 = 0; _i11 < this->skillListIds.size(); _i11++)
  {
    output->writeInt((int)this->skillListIds[_i11]);
  }
  output->writeBool(this->isLocked);
  if(this->price < 0 || this->price > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
}

void HouseInformationsForSell::deserialize(Reader *input)
{
  this->deserializeAs_HouseInformationsForSell(input);
}

void HouseInformationsForSell::deserializeAs_HouseInformationsForSell(Reader *input)
{
  auto _val11 = 0;
  this->_instanceIdFunc(input);
  this->_secondHandFunc(input);
  this->_modelIdFunc(input);
  this->_ownerNameFunc(input);
  this->_ownerCharacterNameFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_subAreaIdFunc(input);
  this->_nbRoomFunc(input);
  this->_nbChestFunc(input);
  uint _skillListIdsLen = input->readUShort();
  for(uint _i11 = 0; _i11 < _skillListIdsLen; _i11++)
  {
    _val11 = input->readInt();
    this->skillListIds.append(_val11);
  }
  this->_isLockedFunc(input);
  this->_priceFunc(input);
}

void HouseInformationsForSell::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseInformationsForSell(tree);
}

void HouseInformationsForSell::deserializeAsyncAs_HouseInformationsForSell(FuncTree tree)
{
  tree.addChild(std::bind(&HouseInformationsForSell::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_secondHandFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_modelIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_ownerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_ownerCharacterNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_nbRoomFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_nbChestFunc, this, std::placeholders::_1));
  this->_skillListIdstree = tree.addChild(std::bind(&HouseInformationsForSell::_skillListIdstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_isLockedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForSell::_priceFunc, this, std::placeholders::_1));
}

void HouseInformationsForSell::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->instanceId << ") on element of HouseInformationsForSell.instanceId.";
  }
}

void HouseInformationsForSell::_secondHandFunc(Reader *input)
{
  this->secondHand = input->readBool();
}

void HouseInformationsForSell::_modelIdFunc(Reader *input)
{
  this->modelId = input->readVarUhInt();
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->modelId << ") on element of HouseInformationsForSell.modelId.";
  }
}

void HouseInformationsForSell::_ownerNameFunc(Reader *input)
{
  this->ownerName = input->readUTF();
}

void HouseInformationsForSell::_ownerCharacterNameFunc(Reader *input)
{
  this->ownerCharacterName = input->readUTF();
}

void HouseInformationsForSell::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->worldX << ") on element of HouseInformationsForSell.worldX.";
  }
}

void HouseInformationsForSell::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->worldY << ") on element of HouseInformationsForSell.worldY.";
  }
}

void HouseInformationsForSell::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->subAreaId << ") on element of HouseInformationsForSell.subAreaId.";
  }
}

void HouseInformationsForSell::_nbRoomFunc(Reader *input)
{
  this->nbRoom = input->readByte();
}

void HouseInformationsForSell::_nbChestFunc(Reader *input)
{
  this->nbChest = input->readByte();
}

void HouseInformationsForSell::_skillListIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_skillListIdstree.addChild(std::bind(&HouseInformationsForSell::_skillListIdsFunc, this, std::placeholders::_1));
  }
}

void HouseInformationsForSell::_skillListIdsFunc(Reader *input)
{
  int _val = input->readInt();
  this->skillListIds.append(_val);
}

void HouseInformationsForSell::_isLockedFunc(Reader *input)
{
  this->isLocked = input->readBool();
}

void HouseInformationsForSell::_priceFunc(Reader *input)
{
  this->price = input->readVarUhLong();
  if(this->price < 0 || this->price > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->price << ") on element of HouseInformationsForSell.price.";
  }
}

HouseInformationsForSell::HouseInformationsForSell()
{
  m_types<<ClassEnum::HOUSEINFORMATIONSFORSELL;
}

bool HouseInformationsForSell::operator==(const HouseInformationsForSell &compared)
{
  if(instanceId == compared.instanceId)
  if(secondHand == compared.secondHand)
  if(modelId == compared.modelId)
  if(ownerName == compared.ownerName)
  if(ownerCharacterName == compared.ownerCharacterName)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(subAreaId == compared.subAreaId)
  if(nbRoom == compared.nbRoom)
  if(nbChest == compared.nbChest)
  if(skillListIds == compared.skillListIds)
  if(isLocked == compared.isLocked)
  if(price == compared.price)
  if(_skillListIdstree == compared._skillListIdstree)
  return true;
  
  return false;
}

