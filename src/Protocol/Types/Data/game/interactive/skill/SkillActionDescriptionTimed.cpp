#include "SkillActionDescriptionTimed.h"

void SkillActionDescriptionTimed::serialize(Writer *output)
{
  this->serializeAs_SkillActionDescriptionTimed(output);
}

void SkillActionDescriptionTimed::serializeAs_SkillActionDescriptionTimed(Writer *output)
{
  SkillActionDescription::serializeAs_SkillActionDescription(output);
  if(this->time < 0 || this->time > 255)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionTimed -"<<"Forbidden value (" << this->time << ") on element time.";
  }
  output->writeByte(this->time);
}

void SkillActionDescriptionTimed::deserialize(Reader *input)
{
  this->deserializeAs_SkillActionDescriptionTimed(input);
}

void SkillActionDescriptionTimed::deserializeAs_SkillActionDescriptionTimed(Reader *input)
{
  SkillActionDescription::deserialize(input);
  this->_timeFunc(input);
}

void SkillActionDescriptionTimed::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SkillActionDescriptionTimed(tree);
}

void SkillActionDescriptionTimed::deserializeAsyncAs_SkillActionDescriptionTimed(FuncTree tree)
{
  SkillActionDescription::deserializeAsync(tree);
  tree.addChild(std::bind(&SkillActionDescriptionTimed::_timeFunc, this, std::placeholders::_1));
}

void SkillActionDescriptionTimed::_timeFunc(Reader *input)
{
  this->time = input->readUByte();
  if(this->time < 0 || this->time > 255)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionTimed -"<<"Forbidden value (" << this->time << ") on element of SkillActionDescriptionTimed.time.";
  }
}

SkillActionDescriptionTimed::SkillActionDescriptionTimed()
{
  m_types<<ClassEnum::SKILLACTIONDESCRIPTIONTIMED;
}

bool SkillActionDescriptionTimed::operator==(const SkillActionDescriptionTimed &compared)
{
  if(time == compared.time)
  return true;
  
  return false;
}

