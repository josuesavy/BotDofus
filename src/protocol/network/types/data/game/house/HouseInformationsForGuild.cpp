#include "HouseInformationsForGuild.h"

void HouseInformationsForGuild::serialize(Writer *output)
{
  this->serializeAs_HouseInformationsForGuild(output);
}

void HouseInformationsForGuild::serializeAs_HouseInformationsForGuild(Writer *output)
{
  HouseInformations::serializeAs_HouseInformations(output);
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->instanceId << ") on element instanceId.";
  }
  output->writeInt((int)this->instanceId);
  output->writeBool(this->secondHand);
  this->ownerTag.serializeAs_AccountTagInformation(output);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeShort((short)this->skillListIds.size());
  for(uint _i8 = 0; _i8 < this->skillListIds.size(); _i8++)
  {
    output->writeInt((int)this->skillListIds[_i8]);
  }
  if(this->guildshareParams < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->guildshareParams << ") on element guildshareParams.";
  }
  output->writeVarInt((int)this->guildshareParams);
}

void HouseInformationsForGuild::deserialize(Reader *input)
{
  this->deserializeAs_HouseInformationsForGuild(input);
}

void HouseInformationsForGuild::deserializeAs_HouseInformationsForGuild(Reader *input)
{
  int _val8 = 0;
  HouseInformations::deserialize(input);
  this->_instanceIdFunc(input);
  this->_secondHandFunc(input);
  this->ownerTag = AccountTagInformation();
  this->ownerTag.deserialize(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
  uint _skillListIdsLen = uint(input->readUShort());
  for(uint _i8 = 0; _i8 < _skillListIdsLen; _i8++)
  {
    _val8 = int(input->readInt());
    this->skillListIds.append(_val8);
  }
  this->_guildshareParamsFunc(input);
}

void HouseInformationsForGuild::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseInformationsForGuild(tree);
}

void HouseInformationsForGuild::deserializeAsyncAs_HouseInformationsForGuild(FuncTree tree)
{
  HouseInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&HouseInformationsForGuild::_instanceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForGuild::_secondHandFunc, this, std::placeholders::_1));
  this->_ownerTagtree = tree.addChild(std::bind(&HouseInformationsForGuild::_ownerTagtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForGuild::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForGuild::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForGuild::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForGuild::_subAreaIdFunc, this, std::placeholders::_1));
  this->_skillListIdstree = tree.addChild(std::bind(&HouseInformationsForGuild::_skillListIdstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsForGuild::_guildshareParamsFunc, this, std::placeholders::_1));
}

void HouseInformationsForGuild::_instanceIdFunc(Reader *input)
{
  this->instanceId = input->readInt();
  if(this->instanceId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->instanceId << ") on element of HouseInformationsForGuild.instanceId.";
  }
}

void HouseInformationsForGuild::_secondHandFunc(Reader *input)
{
  this->secondHand = input->readBool();
}

void HouseInformationsForGuild::_ownerTagtreeFunc(Reader *input)
{
  this->ownerTag = AccountTagInformation();
  this->ownerTag.deserializeAsync(this->_ownerTagtree);
}

void HouseInformationsForGuild::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->worldX << ") on element of HouseInformationsForGuild.worldX.";
  }
}

void HouseInformationsForGuild::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->worldY << ") on element of HouseInformationsForGuild.worldY.";
  }
}

void HouseInformationsForGuild::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->mapId << ") on element of HouseInformationsForGuild.mapId.";
  }
}

void HouseInformationsForGuild::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->subAreaId << ") on element of HouseInformationsForGuild.subAreaId.";
  }
}

void HouseInformationsForGuild::_skillListIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_skillListIdstree.addChild(std::bind(&HouseInformationsForGuild::_skillListIdsFunc, this, std::placeholders::_1));
  }
}

void HouseInformationsForGuild::_skillListIdsFunc(Reader *input)
{
  int _val = int(input->readInt());
  this->skillListIds.append(_val);
}

void HouseInformationsForGuild::_guildshareParamsFunc(Reader *input)
{
  this->guildshareParams = input->readVarUhInt();
  if(this->guildshareParams < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->guildshareParams << ") on element of HouseInformationsForGuild.guildshareParams.";
  }
}

HouseInformationsForGuild::HouseInformationsForGuild()
{
  m_types<<ClassEnum::HOUSEINFORMATIONSFORGUILD;
}

bool HouseInformationsForGuild::operator==(const HouseInformationsForGuild &compared)
{
  if(instanceId == compared.instanceId)
  if(secondHand == compared.secondHand)
  if(ownerTag == compared.ownerTag)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(skillListIds == compared.skillListIds)
  if(guildshareParams == compared.guildshareParams)
  if(_ownerTagtree == compared._ownerTagtree)
  if(_skillListIdstree == compared._skillListIdstree)
  return true;
  
  return false;
}

