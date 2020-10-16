#include "InteractiveElementWithAgeBonus.h"

void InteractiveElementWithAgeBonus::serialize(Writer *output)
{
  this->serializeAs_InteractiveElementWithAgeBonus(output);
}

void InteractiveElementWithAgeBonus::serializeAs_InteractiveElementWithAgeBonus(Writer *output)
{
  InteractiveElement::serializeAs_InteractiveElement(output);
  if(this->ageBonus < -1 || this->ageBonus > 1000)
  {
    qDebug()<<"ERREUR - InteractiveElementWithAgeBonus -"<<"Forbidden value (" << this->ageBonus << ") on element ageBonus.";
  }
  output->writeShort((short)this->ageBonus);
}

void InteractiveElementWithAgeBonus::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveElementWithAgeBonus(input);
}

void InteractiveElementWithAgeBonus::deserializeAs_InteractiveElementWithAgeBonus(Reader *input)
{
  InteractiveElement::deserialize(input);
  this->_ageBonusFunc(input);
}

void InteractiveElementWithAgeBonus::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveElementWithAgeBonus(tree);
}

void InteractiveElementWithAgeBonus::deserializeAsyncAs_InteractiveElementWithAgeBonus(FuncTree tree)
{
  InteractiveElement::deserializeAsync(tree);
  tree.addChild(std::bind(&InteractiveElementWithAgeBonus::_ageBonusFunc, this, std::placeholders::_1));
}

void InteractiveElementWithAgeBonus::_ageBonusFunc(Reader *input)
{
  this->ageBonus = input->readShort();
  if(this->ageBonus < -1 || this->ageBonus > 1000)
  {
    qDebug()<<"ERREUR - InteractiveElementWithAgeBonus -"<<"Forbidden value (" << this->ageBonus << ") on element of InteractiveElementWithAgeBonus.ageBonus.";
  }
}

InteractiveElementWithAgeBonus::InteractiveElementWithAgeBonus()
{
  m_types<<ClassEnum::INTERACTIVEELEMENTWITHAGEBONUS;
}

bool InteractiveElementWithAgeBonus::operator==(const InteractiveElementWithAgeBonus &compared)
{
  if(ageBonus == compared.ageBonus)
  return true;
  
  return false;
}

