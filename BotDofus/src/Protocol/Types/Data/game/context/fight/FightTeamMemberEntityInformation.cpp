#include "FightTeamMemberEntityInformation.h"

void FightTeamMemberEntityInformation::serialize(Writer *output)
{
  this->serializeAs_FightTeamMemberEntityInformation(output);
}

void FightTeamMemberEntityInformation::serializeAs_FightTeamMemberEntityInformation(Writer *output)
{
  FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(output);
  if(this->entityModelId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberEntityInformation -"<<"Forbidden value (" << this->entityModelId << ") on element entityModelId.";
  }
  output->writeByte(this->entityModelId);
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - FightTeamMemberEntityInformation -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightTeamMemberEntityInformation -"<<"Forbidden value (" << this->masterId << ") on element masterId.";
  }
  output->writeDouble(this->masterId);
}

void FightTeamMemberEntityInformation::deserialize(Reader *input)
{
  this->deserializeAs_FightTeamMemberEntityInformation(input);
}

void FightTeamMemberEntityInformation::deserializeAs_FightTeamMemberEntityInformation(Reader *input)
{
  FightTeamMemberInformations::deserialize(input);
  this->_entityModelIdFunc(input);
  this->_levelFunc(input);
  this->_masterIdFunc(input);
}

void FightTeamMemberEntityInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTeamMemberEntityInformation(tree);
}

void FightTeamMemberEntityInformation::deserializeAsyncAs_FightTeamMemberEntityInformation(FuncTree tree)
{
  FightTeamMemberInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTeamMemberEntityInformation::_entityModelIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamMemberEntityInformation::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamMemberEntityInformation::_masterIdFunc, this, std::placeholders::_1));
}

void FightTeamMemberEntityInformation::_entityModelIdFunc(Reader *input)
{
  this->entityModelId = input->readByte();
  if(this->entityModelId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberEntityInformation -"<<"Forbidden value (" << this->entityModelId << ") on element of FightTeamMemberEntityInformation.entityModelId.";
  }
}

void FightTeamMemberEntityInformation::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - FightTeamMemberEntityInformation -"<<"Forbidden value (" << this->level << ") on element of FightTeamMemberEntityInformation.level.";
  }
}

void FightTeamMemberEntityInformation::_masterIdFunc(Reader *input)
{
  this->masterId = input->readDouble();
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightTeamMemberEntityInformation -"<<"Forbidden value (" << this->masterId << ") on element of FightTeamMemberEntityInformation.masterId.";
  }
}

FightTeamMemberEntityInformation::FightTeamMemberEntityInformation()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERENTITYINFORMATION;
}

bool FightTeamMemberEntityInformation::operator==(const FightTeamMemberEntityInformation &compared)
{
  if(entityModelId == compared.entityModelId)
  if(level == compared.level)
  if(masterId == compared.masterId)
  return true;
  
  return false;
}

