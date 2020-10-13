#include "SkillActionDescription.h"

void SkillActionDescription::serialize(Writer *output)
{
  this->serializeAs_SkillActionDescription(output);
}

void SkillActionDescription::serializeAs_SkillActionDescription(Writer *output)
{
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescription -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  output->writeVarShort((int)this->skillId);
}

void SkillActionDescription::deserialize(Reader *input)
{
  this->deserializeAs_SkillActionDescription(input);
}

void SkillActionDescription::deserializeAs_SkillActionDescription(Reader *input)
{
  this->_skillIdFunc(input);
}

void SkillActionDescription::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SkillActionDescription(tree);
}

void SkillActionDescription::deserializeAsyncAs_SkillActionDescription(FuncTree tree)
{
  tree.addChild(std::bind(&SkillActionDescription::_skillIdFunc, this, std::placeholders::_1));
}

void SkillActionDescription::_skillIdFunc(Reader *input)
{
  this->skillId = input->readVarUhShort();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescription -"<<"Forbidden value (" << this->skillId << ") on element of SkillActionDescription.skillId.";
  }
}

SkillActionDescription::SkillActionDescription()
{
  m_types<<ClassEnum::SKILLACTIONDESCRIPTION;
}

bool SkillActionDescription::operator==(const SkillActionDescription &compared)
{
  if(skillId == compared.skillId)
  return true;
  
  return false;
}

