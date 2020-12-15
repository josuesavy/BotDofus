#include "CharacterBaseCharacteristic.h"

void CharacterBaseCharacteristic::serialize(Writer *output)
{
  this->serializeAs_CharacterBaseCharacteristic(output);
}

void CharacterBaseCharacteristic::serializeAs_CharacterBaseCharacteristic(Writer *output)
{
  output->writeVarShort((int)this->base);
  output->writeVarShort((int)this->additionnal);
  output->writeVarShort((int)this->objectsAndMountBonus);
  output->writeVarShort((int)this->alignGiftBonus);
  output->writeVarShort((int)this->contextModif);
}

void CharacterBaseCharacteristic::deserialize(Reader *input)
{
  this->deserializeAs_CharacterBaseCharacteristic(input);
}

void CharacterBaseCharacteristic::deserializeAs_CharacterBaseCharacteristic(Reader *input)
{
  this->_baseFunc(input);
  this->_additionnalFunc(input);
  this->_objectsAndMountBonusFunc(input);
  this->_alignGiftBonusFunc(input);
  this->_contextModifFunc(input);
}

void CharacterBaseCharacteristic::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterBaseCharacteristic(tree);
}

void CharacterBaseCharacteristic::deserializeAsyncAs_CharacterBaseCharacteristic(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterBaseCharacteristic::_baseFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterBaseCharacteristic::_additionnalFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterBaseCharacteristic::_objectsAndMountBonusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterBaseCharacteristic::_alignGiftBonusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterBaseCharacteristic::_contextModifFunc, this, std::placeholders::_1));
}

void CharacterBaseCharacteristic::_baseFunc(Reader *input)
{
  this->base = input->readVarShort();
}

void CharacterBaseCharacteristic::_additionnalFunc(Reader *input)
{
  this->additionnal = input->readVarShort();
}

void CharacterBaseCharacteristic::_objectsAndMountBonusFunc(Reader *input)
{
  this->objectsAndMountBonus = input->readVarShort();
}

void CharacterBaseCharacteristic::_alignGiftBonusFunc(Reader *input)
{
  this->alignGiftBonus = input->readVarShort();
}

void CharacterBaseCharacteristic::_contextModifFunc(Reader *input)
{
  this->contextModif = input->readVarShort();
}

CharacterBaseCharacteristic::CharacterBaseCharacteristic()
{
  m_types<<ClassEnum::CHARACTERBASECHARACTERISTIC;
}

bool CharacterBaseCharacteristic::operator==(const CharacterBaseCharacteristic &compared)
{
  if(base == compared.base)
  if(additionnal == compared.additionnal)
  if(objectsAndMountBonus == compared.objectsAndMountBonus)
  if(alignGiftBonus == compared.alignGiftBonus)
  if(contextModif == compared.contextModif)
  return true;
  
  return false;
}

