#include "CharacterCharacteristicDetailed.h"

void CharacterCharacteristicDetailed::serialize(Writer *output)
{
  this->serializeAs_CharacterCharacteristicDetailed(output);
}

void CharacterCharacteristicDetailed::serializeAs_CharacterCharacteristicDetailed(Writer *output)
{
  CharacterCharacteristic::serializeAs_CharacterCharacteristic(output);
  output->writeVarInt((int)this->base);
  output->writeVarInt((int)this->additional);
  output->writeVarInt((int)this->objectsAndMountBonus);
  output->writeVarInt((int)this->alignGiftBonus);
  output->writeVarInt((int)this->contextModif);
}

void CharacterCharacteristicDetailed::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCharacteristicDetailed(input);
}

void CharacterCharacteristicDetailed::deserializeAs_CharacterCharacteristicDetailed(Reader *input)
{
  CharacterCharacteristic::deserialize(input);
  this->_baseFunc(input);
  this->_additionalFunc(input);
  this->_objectsAndMountBonusFunc(input);
  this->_alignGiftBonusFunc(input);
  this->_contextModifFunc(input);
}

void CharacterCharacteristicDetailed::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCharacteristicDetailed(tree);
}

void CharacterCharacteristicDetailed::deserializeAsyncAs_CharacterCharacteristicDetailed(FuncTree tree)
{
  CharacterCharacteristic::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterCharacteristicDetailed::_baseFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicDetailed::_additionalFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicDetailed::_objectsAndMountBonusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicDetailed::_alignGiftBonusFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicDetailed::_contextModifFunc, this, std::placeholders::_1));
}

void CharacterCharacteristicDetailed::_baseFunc(Reader *input)
{
  this->base = input->readVarInt();
}

void CharacterCharacteristicDetailed::_additionalFunc(Reader *input)
{
  this->additional = input->readVarInt();
}

void CharacterCharacteristicDetailed::_objectsAndMountBonusFunc(Reader *input)
{
  this->objectsAndMountBonus = input->readVarInt();
}

void CharacterCharacteristicDetailed::_alignGiftBonusFunc(Reader *input)
{
  this->alignGiftBonus = input->readVarInt();
}

void CharacterCharacteristicDetailed::_contextModifFunc(Reader *input)
{
  this->contextModif = input->readVarInt();
}

CharacterCharacteristicDetailed::CharacterCharacteristicDetailed()
{
  m_types<<ClassEnum::CHARACTERCHARACTERISTICDETAILED;
}

bool CharacterCharacteristicDetailed::operator==(const CharacterCharacteristicDetailed &compared)
{
  if(base == compared.base)
  if(additional == compared.additional)
  if(objectsAndMountBonus == compared.objectsAndMountBonus)
  if(alignGiftBonus == compared.alignGiftBonus)
  if(contextModif == compared.contextModif)
  return true;
  
  return false;
}

