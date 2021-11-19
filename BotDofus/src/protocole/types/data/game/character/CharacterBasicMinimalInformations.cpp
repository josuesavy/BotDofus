#include "CharacterBasicMinimalInformations.h"

void CharacterBasicMinimalInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterBasicMinimalInformations(output);
}

void CharacterBasicMinimalInformations::serializeAs_CharacterBasicMinimalInformations(Writer *output)
{
  AbstractCharacterInformation::serializeAs_AbstractCharacterInformation(output);
  output->writeUTF(this->name);
}

void CharacterBasicMinimalInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterBasicMinimalInformations(input);
}

void CharacterBasicMinimalInformations::deserializeAs_CharacterBasicMinimalInformations(Reader *input)
{
  AbstractCharacterInformation::deserialize(input);
  this->_nameFunc(input);
}

void CharacterBasicMinimalInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterBasicMinimalInformations(tree);
}

void CharacterBasicMinimalInformations::deserializeAsyncAs_CharacterBasicMinimalInformations(FuncTree tree)
{
  AbstractCharacterInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterBasicMinimalInformations::_nameFunc, this, std::placeholders::_1));
}

void CharacterBasicMinimalInformations::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

CharacterBasicMinimalInformations::CharacterBasicMinimalInformations()
{
  m_types<<ClassEnum::CHARACTERBASICMINIMALINFORMATIONS;
}

bool CharacterBasicMinimalInformations::operator==(const CharacterBasicMinimalInformations &compared)
{
  if(name == compared.name)
  return true;
  
  return false;
}

