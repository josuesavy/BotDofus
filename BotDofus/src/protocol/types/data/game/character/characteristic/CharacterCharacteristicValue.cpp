#include "CharacterCharacteristicValue.h"

void CharacterCharacteristicValue::serialize(Writer *output)
{
  this->serializeAs_CharacterCharacteristicValue(output);
}

void CharacterCharacteristicValue::serializeAs_CharacterCharacteristicValue(Writer *output)
{
  CharacterCharacteristic::serializeAs_CharacterCharacteristic(output);
  output->writeInt((int)this->total);
}

void CharacterCharacteristicValue::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCharacteristicValue(input);
}

void CharacterCharacteristicValue::deserializeAs_CharacterCharacteristicValue(Reader *input)
{
  CharacterCharacteristic::deserialize(input);
  this->_totalFunc(input);
}

void CharacterCharacteristicValue::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCharacteristicValue(tree);
}

void CharacterCharacteristicValue::deserializeAsyncAs_CharacterCharacteristicValue(FuncTree tree)
{
  CharacterCharacteristic::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterCharacteristicValue::_totalFunc, this, std::placeholders::_1));
}

void CharacterCharacteristicValue::_totalFunc(Reader *input)
{
  this->total = input->readInt();
}

CharacterCharacteristicValue::CharacterCharacteristicValue()
{
  m_types<<ClassEnum::CHARACTERCHARACTERISTICVALUE;
}

bool CharacterCharacteristicValue::operator==(const CharacterCharacteristicValue &compared)
{
  if(total == compared.total)
  return true;
  
  return false;
}

