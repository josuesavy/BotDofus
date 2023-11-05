#include "GuildRecruitmentInformation.h"

void GuildRecruitmentInformation::serialize(Writer *output)
{
  this->serializeAs_GuildRecruitmentInformation(output);
}

void GuildRecruitmentInformation::serializeAs_GuildRecruitmentInformation(Writer *output)
{
  SocialRecruitmentInformation::serializeAs_SocialRecruitmentInformation(output);
  if(this->minSuccess < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->minSuccess << ") on element minSuccess.";
  }
  output->writeVarInt((int)this->minSuccess);
  output->writeBool(this->minSuccessFacultative);
}

void GuildRecruitmentInformation::deserialize(Reader *input)
{
  this->deserializeAs_GuildRecruitmentInformation(input);
}

void GuildRecruitmentInformation::deserializeAs_GuildRecruitmentInformation(Reader *input)
{
  SocialRecruitmentInformation::deserialize(input);
  this->_minSuccessFunc(input);
  this->_minSuccessFacultativeFunc(input);
}

void GuildRecruitmentInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildRecruitmentInformation(tree);
}

void GuildRecruitmentInformation::deserializeAsyncAs_GuildRecruitmentInformation(FuncTree tree)
{
  SocialRecruitmentInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildRecruitmentInformation::_minSuccessFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRecruitmentInformation::_minSuccessFacultativeFunc, this, std::placeholders::_1));
}

void GuildRecruitmentInformation::_minSuccessFunc(Reader *input)
{
  this->minSuccess = input->readVarUhInt();
  if(this->minSuccess < 0)
  {
    qDebug()<<"ERREUR - GuildRecruitmentInformation -"<<"Forbidden value (" << this->minSuccess << ") on element of GuildRecruitmentInformation.minSuccess.";
  }
}

void GuildRecruitmentInformation::_minSuccessFacultativeFunc(Reader *input)
{
  this->minSuccessFacultative = input->readBool();
}

GuildRecruitmentInformation::GuildRecruitmentInformation()
{
  m_types<<ClassEnum::GUILDRECRUITMENTINFORMATION;
}

bool GuildRecruitmentInformation::operator==(const GuildRecruitmentInformation &compared)
{
  if(minSuccess == compared.minSuccess)
  if(minSuccessFacultative == compared.minSuccessFacultative)
  return true;
  
  return false;
}

