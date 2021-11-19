#include "InteractiveElementNamedSkill.h"

void InteractiveElementNamedSkill::serialize(Writer *output)
{
  this->serializeAs_InteractiveElementNamedSkill(output);
}

void InteractiveElementNamedSkill::serializeAs_InteractiveElementNamedSkill(Writer *output)
{
  InteractiveElementSkill::serializeAs_InteractiveElementSkill(output);
  if(this->nameId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementNamedSkill -"<<"Forbidden value (" << this->nameId << ") on element nameId.";
  }
  output->writeVarInt((int)this->nameId);
}

void InteractiveElementNamedSkill::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveElementNamedSkill(input);
}

void InteractiveElementNamedSkill::deserializeAs_InteractiveElementNamedSkill(Reader *input)
{
  InteractiveElementSkill::deserialize(input);
  this->_nameIdFunc(input);
}

void InteractiveElementNamedSkill::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveElementNamedSkill(tree);
}

void InteractiveElementNamedSkill::deserializeAsyncAs_InteractiveElementNamedSkill(FuncTree tree)
{
  InteractiveElementSkill::deserializeAsync(tree);
  tree.addChild(std::bind(&InteractiveElementNamedSkill::_nameIdFunc, this, std::placeholders::_1));
}

void InteractiveElementNamedSkill::_nameIdFunc(Reader *input)
{
  this->nameId = input->readVarUhInt();
  if(this->nameId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElementNamedSkill -"<<"Forbidden value (" << this->nameId << ") on element of InteractiveElementNamedSkill.nameId.";
  }
}

InteractiveElementNamedSkill::InteractiveElementNamedSkill()
{
  m_types<<ClassEnum::INTERACTIVEELEMENTNAMEDSKILL;
}

bool InteractiveElementNamedSkill::operator==(const InteractiveElementNamedSkill &compared)
{
  if(nameId == compared.nameId)
  return true;
  
  return false;
}

