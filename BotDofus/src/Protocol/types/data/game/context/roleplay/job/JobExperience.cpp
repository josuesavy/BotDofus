#include "JobExperience.h"

void JobExperience::serialize(Writer *output)
{
  this->serializeAs_JobExperience(output);
}

void JobExperience::serializeAs_JobExperience(Writer *output)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  output->writeByte(this->jobId);
  if(this->jobLevel < 0 || this->jobLevel > 255)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobLevel << ") on element jobLevel.";
  }
  output->writeByte(this->jobLevel);
  if(this->jobXP < 0 || this->jobXP > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXP << ") on element jobXP.";
  }
  output->writeVarLong((double)this->jobXP);
  if(this->jobXpLevelFloor < 0 || this->jobXpLevelFloor > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXpLevelFloor << ") on element jobXpLevelFloor.";
  }
  output->writeVarLong((double)this->jobXpLevelFloor);
  if(this->jobXpNextLevelFloor < 0 || this->jobXpNextLevelFloor > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXpNextLevelFloor << ") on element jobXpNextLevelFloor.";
  }
  output->writeVarLong((double)this->jobXpNextLevelFloor);
}

void JobExperience::deserialize(Reader *input)
{
  this->deserializeAs_JobExperience(input);
}

void JobExperience::deserializeAs_JobExperience(Reader *input)
{
  this->_jobIdFunc(input);
  this->_jobLevelFunc(input);
  this->_jobXPFunc(input);
  this->_jobXpLevelFloorFunc(input);
  this->_jobXpNextLevelFloorFunc(input);
}

void JobExperience::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobExperience(tree);
}

void JobExperience::deserializeAsyncAs_JobExperience(FuncTree tree)
{
  tree.addChild(std::bind(&JobExperience::_jobIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobExperience::_jobLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobExperience::_jobXPFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobExperience::_jobXpLevelFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobExperience::_jobXpNextLevelFloorFunc, this, std::placeholders::_1));
}

void JobExperience::_jobIdFunc(Reader *input)
{
  this->jobId = input->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobId << ") on element of JobExperience.jobId.";
  }
}

void JobExperience::_jobLevelFunc(Reader *input)
{
  this->jobLevel = input->readUByte();
  if(this->jobLevel < 0 || this->jobLevel > 255)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobLevel << ") on element of JobExperience.jobLevel.";
  }
}

void JobExperience::_jobXPFunc(Reader *input)
{
  this->jobXP = input->readVarUhLong();
  if(this->jobXP < 0 || this->jobXP > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXP << ") on element of JobExperience.jobXP.";
  }
}

void JobExperience::_jobXpLevelFloorFunc(Reader *input)
{
  this->jobXpLevelFloor = input->readVarUhLong();
  if(this->jobXpLevelFloor < 0 || this->jobXpLevelFloor > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXpLevelFloor << ") on element of JobExperience.jobXpLevelFloor.";
  }
}

void JobExperience::_jobXpNextLevelFloorFunc(Reader *input)
{
  this->jobXpNextLevelFloor = input->readVarUhLong();
  if(this->jobXpNextLevelFloor < 0 || this->jobXpNextLevelFloor > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXpNextLevelFloor << ") on element of JobExperience.jobXpNextLevelFloor.";
  }
}

JobExperience::JobExperience()
{
  m_types<<ClassEnum::JOBEXPERIENCE;
}

bool JobExperience::operator==(const JobExperience &compared)
{
  if(jobId == compared.jobId)
  if(jobLevel == compared.jobLevel)
  if(jobXP == compared.jobXP)
  if(jobXpLevelFloor == compared.jobXpLevelFloor)
  if(jobXpNextLevelFloor == compared.jobXpNextLevelFloor)
  return true;
  
  return false;
}

