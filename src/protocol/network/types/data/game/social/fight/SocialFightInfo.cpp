#include "SocialFightInfo.h"

void SocialFightInfo::serialize(Writer *output)
{
  this->serializeAs_SocialFightInfo(output);
}

void SocialFightInfo::serializeAs_SocialFightInfo(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - SocialFightInfo -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeByte(this->fightType);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialFightInfo -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
}

void SocialFightInfo::deserialize(Reader *input)
{
  this->deserializeAs_SocialFightInfo(input);
}

void SocialFightInfo::deserializeAs_SocialFightInfo(Reader *input)
{
  this->_fightIdFunc(input);
  this->_fightTypeFunc(input);
  this->_mapIdFunc(input);
}

void SocialFightInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SocialFightInfo(tree);
}

void SocialFightInfo::deserializeAsyncAs_SocialFightInfo(FuncTree tree)
{
  tree.addChild(std::bind(&SocialFightInfo::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialFightInfo::_fightTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SocialFightInfo::_mapIdFunc, this, std::placeholders::_1));
}

void SocialFightInfo::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - SocialFightInfo -"<<"Forbidden value (" << this->fightId << ") on element of SocialFightInfo.fightId.";
  }
}

void SocialFightInfo::_fightTypeFunc(Reader *input)
{
  this->fightType = input->readByte();
  if(this->fightType < 0)
  {
    qDebug()<<"ERREUR - SocialFightInfo -"<<"Forbidden value (" << this->fightType << ") on element of SocialFightInfo.fightType.";
  }
}

void SocialFightInfo::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - SocialFightInfo -"<<"Forbidden value (" << this->mapId << ") on element of SocialFightInfo.mapId.";
  }
}

SocialFightInfo::SocialFightInfo()
{
  m_types<<ClassEnum::SOCIALFIGHTINFO;
}

bool SocialFightInfo::operator==(const SocialFightInfo &compared)
{
  if(fightId == compared.fightId)
  if(fightType == compared.fightType)
  if(mapId == compared.mapId)
  return true;
  
  return false;
}

