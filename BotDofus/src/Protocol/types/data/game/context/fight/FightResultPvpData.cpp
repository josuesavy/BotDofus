#include "FightResultPvpData.h"

void FightResultPvpData::serialize(Writer *output)
{
  this->serializeAs_FightResultPvpData(output);
}

void FightResultPvpData::serializeAs_FightResultPvpData(Writer *output)
{
  FightResultAdditionalData::serializeAs_FightResultAdditionalData(output);
  if(this->grade < 0 || this->grade > 255)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->grade << ") on element grade.";
  }
  output->writeByte(this->grade);
  if(this->minHonorForGrade < 0 || this->minHonorForGrade > 20000)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->minHonorForGrade << ") on element minHonorForGrade.";
  }
  output->writeVarShort((int)this->minHonorForGrade);
  if(this->maxHonorForGrade < 0 || this->maxHonorForGrade > 20000)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->maxHonorForGrade << ") on element maxHonorForGrade.";
  }
  output->writeVarShort((int)this->maxHonorForGrade);
  if(this->honor < 0 || this->honor > 20000)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->honor << ") on element honor.";
  }
  output->writeVarShort((int)this->honor);
  output->writeVarShort((int)this->honorDelta);
}

void FightResultPvpData::deserialize(Reader *input)
{
  this->deserializeAs_FightResultPvpData(input);
}

void FightResultPvpData::deserializeAs_FightResultPvpData(Reader *input)
{
  FightResultAdditionalData::deserialize(input);
  this->_gradeFunc(input);
  this->_minHonorForGradeFunc(input);
  this->_maxHonorForGradeFunc(input);
  this->_honorFunc(input);
  this->_honorDeltaFunc(input);
}

void FightResultPvpData::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightResultPvpData(tree);
}

void FightResultPvpData::deserializeAsyncAs_FightResultPvpData(FuncTree tree)
{
  FightResultAdditionalData::deserializeAsync(tree);
  tree.addChild(std::bind(&FightResultPvpData::_gradeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultPvpData::_minHonorForGradeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultPvpData::_maxHonorForGradeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultPvpData::_honorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultPvpData::_honorDeltaFunc, this, std::placeholders::_1));
}

void FightResultPvpData::_gradeFunc(Reader *input)
{
  this->grade = input->readUByte();
  if(this->grade < 0 || this->grade > 255)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->grade << ") on element of FightResultPvpData.grade.";
  }
}

void FightResultPvpData::_minHonorForGradeFunc(Reader *input)
{
  this->minHonorForGrade = input->readVarUhShort();
  if(this->minHonorForGrade < 0 || this->minHonorForGrade > 20000)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->minHonorForGrade << ") on element of FightResultPvpData.minHonorForGrade.";
  }
}

void FightResultPvpData::_maxHonorForGradeFunc(Reader *input)
{
  this->maxHonorForGrade = input->readVarUhShort();
  if(this->maxHonorForGrade < 0 || this->maxHonorForGrade > 20000)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->maxHonorForGrade << ") on element of FightResultPvpData.maxHonorForGrade.";
  }
}

void FightResultPvpData::_honorFunc(Reader *input)
{
  this->honor = input->readVarUhShort();
  if(this->honor < 0 || this->honor > 20000)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->honor << ") on element of FightResultPvpData.honor.";
  }
}

void FightResultPvpData::_honorDeltaFunc(Reader *input)
{
  this->honorDelta = input->readVarShort();
}

FightResultPvpData::FightResultPvpData()
{
  m_types<<ClassEnum::FIGHTRESULTPVPDATA;
}

bool FightResultPvpData::operator==(const FightResultPvpData &compared)
{
  if(grade == compared.grade)
  if(minHonorForGrade == compared.minHonorForGrade)
  if(maxHonorForGrade == compared.maxHonorForGrade)
  if(honor == compared.honor)
  if(honorDelta == compared.honorDelta)
  return true;
  
  return false;
}

