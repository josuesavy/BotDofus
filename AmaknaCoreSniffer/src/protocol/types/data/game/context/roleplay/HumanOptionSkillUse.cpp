#include "HumanOptionSkillUse.h"

void HumanOptionSkillUse::serialize(Writer *output)
{
  this->serializeAs_HumanOptionSkillUse(output);
}

void HumanOptionSkillUse::serializeAs_HumanOptionSkillUse(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->elementId << ") on element elementId.";
  }
  output->writeVarInt((int)this->elementId);
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  output->writeVarShort((int)this->skillId);
  if(this->skillEndTime < -9.007199254740992E15 || this->skillEndTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->skillEndTime << ") on element skillEndTime.";
  }
  output->writeDouble(this->skillEndTime);
}

void HumanOptionSkillUse::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionSkillUse(input);
}

void HumanOptionSkillUse::deserializeAs_HumanOptionSkillUse(Reader *input)
{
  HumanOption::deserialize(input);
  this->_elementIdFunc(input);
  this->_skillIdFunc(input);
  this->_skillEndTimeFunc(input);
}

void HumanOptionSkillUse::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionSkillUse(tree);
}

void HumanOptionSkillUse::deserializeAsyncAs_HumanOptionSkillUse(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  tree.addChild(std::bind(&HumanOptionSkillUse::_elementIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionSkillUse::_skillIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanOptionSkillUse::_skillEndTimeFunc, this, std::placeholders::_1));
}

void HumanOptionSkillUse::_elementIdFunc(Reader *input)
{
  this->elementId = input->readVarUhInt();
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->elementId << ") on element of HumanOptionSkillUse.elementId.";
  }
}

void HumanOptionSkillUse::_skillIdFunc(Reader *input)
{
  this->skillId = input->readVarUhShort();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->skillId << ") on element of HumanOptionSkillUse.skillId.";
  }
}

void HumanOptionSkillUse::_skillEndTimeFunc(Reader *input)
{
  this->skillEndTime = input->readDouble();
  if(this->skillEndTime < -9.007199254740992E15 || this->skillEndTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HumanOptionSkillUse -"<<"Forbidden value (" << this->skillEndTime << ") on element of HumanOptionSkillUse.skillEndTime.";
  }
}

HumanOptionSkillUse::HumanOptionSkillUse()
{
  m_types<<ClassEnum::HUMANOPTIONSKILLUSE;
}

bool HumanOptionSkillUse::operator==(const HumanOptionSkillUse &compared)
{
  if(elementId == compared.elementId)
  if(skillId == compared.skillId)
  if(skillEndTime == compared.skillEndTime)
  return true;
  
  return false;
}

