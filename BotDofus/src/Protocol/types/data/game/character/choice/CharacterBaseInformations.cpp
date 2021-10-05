#include "CharacterBaseInformations.h"

void CharacterBaseInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterBaseInformations(output);
}

void CharacterBaseInformations::serializeAs_CharacterBaseInformations(Writer *output)
{
  CharacterMinimalPlusLookInformations::serializeAs_CharacterMinimalPlusLookInformations(output);
  output->writeBool(this->sex);
}

void CharacterBaseInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterBaseInformations(input);
}

void CharacterBaseInformations::deserializeAs_CharacterBaseInformations(Reader *input)
{
  CharacterMinimalPlusLookInformations::deserialize(input);
  this->_sexFunc(input);
}

void CharacterBaseInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterBaseInformations(tree);
}

void CharacterBaseInformations::deserializeAsyncAs_CharacterBaseInformations(FuncTree tree)
{
  CharacterMinimalPlusLookInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterBaseInformations::_sexFunc, this, std::placeholders::_1));
}

void CharacterBaseInformations::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

CharacterBaseInformations::CharacterBaseInformations()
{
  m_types<<ClassEnum::CHARACTERBASEINFORMATIONS;
}

bool CharacterBaseInformations::operator==(const CharacterBaseInformations &compared)
{
  if(sex == compared.sex)
  return true;
  
  return false;
}

