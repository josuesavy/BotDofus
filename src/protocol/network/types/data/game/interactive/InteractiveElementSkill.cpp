#include "InteractiveElementSkill.h"

void InteractiveElementSkill::serialize(Writer *output)
{
  this->serializeAs_InteractiveElementSkill(output);
}

void InteractiveElementSkill::serializeAs_InteractiveElementSkill(Writer *output)
{
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementSkill -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  output->writeVarInt((int)this->skillId);
  if(this->skillInstanceUid < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementSkill -"<<"Forbidden value (" << this->skillInstanceUid << ") on element skillInstanceUid.";
  }
  output->writeInt((int)this->skillInstanceUid);
}

void InteractiveElementSkill::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveElementSkill(input);
}

void InteractiveElementSkill::deserializeAs_InteractiveElementSkill(Reader *input)
{
  this->_skillIdFunc(input);
  this->_skillInstanceUidFunc(input);
}

void InteractiveElementSkill::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveElementSkill(tree);
}

void InteractiveElementSkill::deserializeAsyncAs_InteractiveElementSkill(FuncTree tree)
{
  tree.addChild(std::bind(&InteractiveElementSkill::_skillIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveElementSkill::_skillInstanceUidFunc, this, std::placeholders::_1));
}

void InteractiveElementSkill::_skillIdFunc(Reader *input)
{
  this->skillId = input->readVarUhInt();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementSkill -"<<"Forbidden value (" << this->skillId << ") on element of InteractiveElementSkill.skillId.";
  }
}

void InteractiveElementSkill::_skillInstanceUidFunc(Reader *input)
{
  this->skillInstanceUid = input->readInt();
  if(this->skillInstanceUid < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementSkill -"<<"Forbidden value (" << this->skillInstanceUid << ") on element of InteractiveElementSkill.skillInstanceUid.";
  }
}

InteractiveElementSkill::InteractiveElementSkill()
{
  m_types<<ClassEnum::INTERACTIVEELEMENTSKILL;
}

bool InteractiveElementSkill::operator==(const InteractiveElementSkill &compared)
{
  if(skillId == compared.skillId)
  if(skillInstanceUid == compared.skillInstanceUid)
  return true;
  
  return false;
}

