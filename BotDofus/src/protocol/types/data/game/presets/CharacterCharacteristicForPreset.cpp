#include "CharacterCharacteristicForPreset.h"

void CharacterCharacteristicForPreset::serialize(Writer *output)
{
  this->serializeAs_CharacterCharacteristicForPreset(output);
}

void CharacterCharacteristicForPreset::serializeAs_CharacterCharacteristicForPreset(Writer *output)
{
  SimpleCharacterCharacteristicForPreset::serializeAs_SimpleCharacterCharacteristicForPreset(output);
  output->writeVarShort((int)this->stuff);
}

void CharacterCharacteristicForPreset::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCharacteristicForPreset(input);
}

void CharacterCharacteristicForPreset::deserializeAs_CharacterCharacteristicForPreset(Reader *input)
{
  SimpleCharacterCharacteristicForPreset::deserialize(input);
  this->_stuffFunc(input);
}

void CharacterCharacteristicForPreset::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCharacteristicForPreset(tree);
}

void CharacterCharacteristicForPreset::deserializeAsyncAs_CharacterCharacteristicForPreset(FuncTree tree)
{
  SimpleCharacterCharacteristicForPreset::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterCharacteristicForPreset::_stuffFunc, this, std::placeholders::_1));
}

void CharacterCharacteristicForPreset::_stuffFunc(Reader *input)
{
  this->stuff = input->readVarShort();
}

CharacterCharacteristicForPreset::CharacterCharacteristicForPreset()
{
  m_types<<ClassEnum::CHARACTERCHARACTERISTICFORPRESET;
}

bool CharacterCharacteristicForPreset::operator==(const CharacterCharacteristicForPreset &compared)
{
  if(stuff == compared.stuff)
  return true;
  
  return false;
}

