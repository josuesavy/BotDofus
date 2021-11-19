#include "SkillActionDescriptionCollect.h"

void SkillActionDescriptionCollect::serialize(Writer *output)
{
  this->serializeAs_SkillActionDescriptionCollect(output);
}

void SkillActionDescriptionCollect::serializeAs_SkillActionDescriptionCollect(Writer *output)
{
  SkillActionDescriptionTimed::serializeAs_SkillActionDescriptionTimed(output);
  if(this->min < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCollect -"<<"Forbidden value (" << this->min << ") on element min.";
  }
  output->writeVarShort((int)this->min);
  if(this->max < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCollect -"<<"Forbidden value (" << this->max << ") on element max.";
  }
  output->writeVarShort((int)this->max);
}

void SkillActionDescriptionCollect::deserialize(Reader *input)
{
  this->deserializeAs_SkillActionDescriptionCollect(input);
}

void SkillActionDescriptionCollect::deserializeAs_SkillActionDescriptionCollect(Reader *input)
{
  SkillActionDescriptionTimed::deserialize(input);
  this->_minFunc(input);
  this->_maxFunc(input);
}

void SkillActionDescriptionCollect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SkillActionDescriptionCollect(tree);
}

void SkillActionDescriptionCollect::deserializeAsyncAs_SkillActionDescriptionCollect(FuncTree tree)
{
  SkillActionDescriptionTimed::deserializeAsync(tree);
  tree.addChild(std::bind(&SkillActionDescriptionCollect::_minFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SkillActionDescriptionCollect::_maxFunc, this, std::placeholders::_1));
}

void SkillActionDescriptionCollect::_minFunc(Reader *input)
{
  this->min = input->readVarUhShort();
  if(this->min < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCollect -"<<"Forbidden value (" << this->min << ") on element of SkillActionDescriptionCollect.min.";
  }
}

void SkillActionDescriptionCollect::_maxFunc(Reader *input)
{
  this->max = input->readVarUhShort();
  if(this->max < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCollect -"<<"Forbidden value (" << this->max << ") on element of SkillActionDescriptionCollect.max.";
  }
}

SkillActionDescriptionCollect::SkillActionDescriptionCollect()
{
  m_types<<ClassEnum::SKILLACTIONDESCRIPTIONCOLLECT;
}

bool SkillActionDescriptionCollect::operator==(const SkillActionDescriptionCollect &compared)
{
  if(min == compared.min)
  if(max == compared.max)
  return true;
  
  return false;
}

