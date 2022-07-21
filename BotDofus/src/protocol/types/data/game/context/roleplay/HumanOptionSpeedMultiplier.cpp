#include "HumanOptionSpeedMultiplier.h"

void HumanOptionSpeedMultiplier::serialize(Writer *output)
{
  this->serializeAs_HumanOptionSpeedMultiplier(output);
}

void HumanOptionSpeedMultiplier::serializeAs_HumanOptionSpeedMultiplier(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  if(this->speedMultiplier < 0)
  {
    qDebug()<<"ERREUR - HumanOptionSpeedMultiplier -"<<"Forbidden value (" << this->speedMultiplier << ") on element speedMultiplier.";
  }
  output->writeVarInt((int)this->speedMultiplier);
}

void HumanOptionSpeedMultiplier::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionSpeedMultiplier(input);
}

void HumanOptionSpeedMultiplier::deserializeAs_HumanOptionSpeedMultiplier(Reader *input)
{
  HumanOption::deserialize(input);
  this->_speedMultiplierFunc(input);
}

void HumanOptionSpeedMultiplier::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionSpeedMultiplier(tree);
}

void HumanOptionSpeedMultiplier::deserializeAsyncAs_HumanOptionSpeedMultiplier(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  tree.addChild(std::bind(&HumanOptionSpeedMultiplier::_speedMultiplierFunc, this, std::placeholders::_1));
}

void HumanOptionSpeedMultiplier::_speedMultiplierFunc(Reader *input)
{
  this->speedMultiplier = input->readVarUhInt();
  if(this->speedMultiplier < 0)
  {
    qDebug()<<"ERREUR - HumanOptionSpeedMultiplier -"<<"Forbidden value (" << this->speedMultiplier << ") on element of HumanOptionSpeedMultiplier.speedMultiplier.";
  }
}

HumanOptionSpeedMultiplier::HumanOptionSpeedMultiplier()
{
  m_types<<ClassEnum::HUMANOPTIONSPEEDMULTIPLIER;
}

bool HumanOptionSpeedMultiplier::operator==(const HumanOptionSpeedMultiplier &compared)
{
  if(speedMultiplier == compared.speedMultiplier)
  return true;
  
  return false;
}

