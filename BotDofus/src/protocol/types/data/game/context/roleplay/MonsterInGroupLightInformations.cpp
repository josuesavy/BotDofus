#include "MonsterInGroupLightInformations.h"

void MonsterInGroupLightInformations::serialize(Writer *output)
{
  this->serializeAs_MonsterInGroupLightInformations(output);
}

void MonsterInGroupLightInformations::serializeAs_MonsterInGroupLightInformations(Writer *output)
{
  output->writeInt((int)this->genericId);
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - MonsterInGroupLightInformations -"<<"Forbidden value (" << this->grade << ") on element grade.";
  }
  output->writeByte(this->grade);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - MonsterInGroupLightInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeShort((short)this->level);
}

void MonsterInGroupLightInformations::deserialize(Reader *input)
{
  this->deserializeAs_MonsterInGroupLightInformations(input);
}

void MonsterInGroupLightInformations::deserializeAs_MonsterInGroupLightInformations(Reader *input)
{
  this->_genericIdFunc(input);
  this->_gradeFunc(input);
  this->_levelFunc(input);
}

void MonsterInGroupLightInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MonsterInGroupLightInformations(tree);
}

void MonsterInGroupLightInformations::deserializeAsyncAs_MonsterInGroupLightInformations(FuncTree tree)
{
  tree.addChild(std::bind(&MonsterInGroupLightInformations::_genericIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MonsterInGroupLightInformations::_gradeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MonsterInGroupLightInformations::_levelFunc, this, std::placeholders::_1));
}

void MonsterInGroupLightInformations::_genericIdFunc(Reader *input)
{
  this->genericId = input->readInt();
}

void MonsterInGroupLightInformations::_gradeFunc(Reader *input)
{
  this->grade = input->readByte();
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - MonsterInGroupLightInformations -"<<"Forbidden value (" << this->grade << ") on element of MonsterInGroupLightInformations.grade.";
  }
}

void MonsterInGroupLightInformations::_levelFunc(Reader *input)
{
  this->level = input->readShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - MonsterInGroupLightInformations -"<<"Forbidden value (" << this->level << ") on element of MonsterInGroupLightInformations.level.";
  }
}

MonsterInGroupLightInformations::MonsterInGroupLightInformations()
{
  m_types<<ClassEnum::MONSTERINGROUPLIGHTINFORMATIONS;
}

bool MonsterInGroupLightInformations::operator==(const MonsterInGroupLightInformations &compared)
{
  if(genericId == compared.genericId)
  if(grade == compared.grade)
  if(level == compared.level)
  return true;
  
  return false;
}

