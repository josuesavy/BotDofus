#include "SkillActionDescriptionCraft.h"

void SkillActionDescriptionCraft::serialize(Writer *output)
{
  this->serializeAs_SkillActionDescriptionCraft(output);
}

void SkillActionDescriptionCraft::serializeAs_SkillActionDescriptionCraft(Writer *output)
{
  SkillActionDescription::serializeAs_SkillActionDescription(output);
  if(this->probability < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCraft -"<<"Forbidden value (" << this->probability << ") on element probability.";
  }
  output->writeByte(this->probability);
}

void SkillActionDescriptionCraft::deserialize(Reader *input)
{
  this->deserializeAs_SkillActionDescriptionCraft(input);
}

void SkillActionDescriptionCraft::deserializeAs_SkillActionDescriptionCraft(Reader *input)
{
  SkillActionDescription::deserialize(input);
  this->_probabilityFunc(input);
}

void SkillActionDescriptionCraft::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SkillActionDescriptionCraft(tree);
}

void SkillActionDescriptionCraft::deserializeAsyncAs_SkillActionDescriptionCraft(FuncTree tree)
{
  SkillActionDescription::deserializeAsync(tree);
  tree.addChild(std::bind(&SkillActionDescriptionCraft::_probabilityFunc, this, std::placeholders::_1));
}

void SkillActionDescriptionCraft::_probabilityFunc(Reader *input)
{
  this->probability = input->readByte();
  if(this->probability < 0)
  {
    qDebug()<<"ERREUR - SkillActionDescriptionCraft -"<<"Forbidden value (" << this->probability << ") on element of SkillActionDescriptionCraft.probability.";
  }
}

SkillActionDescriptionCraft::SkillActionDescriptionCraft()
{
  m_types<<ClassEnum::SKILLACTIONDESCRIPTIONCRAFT;
}

bool SkillActionDescriptionCraft::operator==(const SkillActionDescriptionCraft &compared)
{
  if(probability == compared.probability)
  return true;
  
  return false;
}

