#include "CharacterCharacteristic.h"

void CharacterCharacteristic::serialize(Writer *output)
{
  this->serializeAs_CharacterCharacteristic(output);
}

void CharacterCharacteristic::serializeAs_CharacterCharacteristic(Writer *output)
{
  output->writeShort((short)this->characteristicId);
}

void CharacterCharacteristic::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCharacteristic(input);
}

void CharacterCharacteristic::deserializeAs_CharacterCharacteristic(Reader *input)
{
  this->_characteristicIdFunc(input);
}

void CharacterCharacteristic::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCharacteristic(tree);
}

void CharacterCharacteristic::deserializeAsyncAs_CharacterCharacteristic(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterCharacteristic::_characteristicIdFunc, this, std::placeholders::_1));
}

void CharacterCharacteristic::_characteristicIdFunc(Reader *input)
{
  this->characteristicId = input->readShort();
}

CharacterCharacteristic::CharacterCharacteristic()
{
  m_types<<ClassEnum::CHARACTERCHARACTERISTIC;
}

bool CharacterCharacteristic::operator==(const CharacterCharacteristic &compared)
{
  if(characteristicId == compared.characteristicId)
  return true;
  
  return false;
}

