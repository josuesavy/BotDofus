#include "CharacterMinimalPlusLookInformations.h"

void CharacterMinimalPlusLookInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterMinimalPlusLookInformations(output);
}

void CharacterMinimalPlusLookInformations::serializeAs_CharacterMinimalPlusLookInformations(Writer *output)
{
  CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(output);
  this->entityLook.serializeAs_EntityLook(output);
  output->writeByte(this->breed);
}

void CharacterMinimalPlusLookInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterMinimalPlusLookInformations(input);
}

void CharacterMinimalPlusLookInformations::deserializeAs_CharacterMinimalPlusLookInformations(Reader *input)
{
  CharacterMinimalInformations::deserialize(input);
  this->entityLook = EntityLook();
  this->entityLook.deserialize(input);
  this->_breedFunc(input);
}

void CharacterMinimalPlusLookInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterMinimalPlusLookInformations(tree);
}

void CharacterMinimalPlusLookInformations::deserializeAsyncAs_CharacterMinimalPlusLookInformations(FuncTree tree)
{
  CharacterMinimalInformations::deserializeAsync(tree);
  this->_entityLooktree = tree.addChild(std::bind(&CharacterMinimalPlusLookInformations::_entityLooktreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterMinimalPlusLookInformations::_breedFunc, this, std::placeholders::_1));
}

void CharacterMinimalPlusLookInformations::_entityLooktreeFunc(Reader *input)
{
  this->entityLook = EntityLook();
  this->entityLook.deserializeAsync(this->_entityLooktree);
}

void CharacterMinimalPlusLookInformations::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
}

CharacterMinimalPlusLookInformations::CharacterMinimalPlusLookInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALPLUSLOOKINFORMATIONS;
}

bool CharacterMinimalPlusLookInformations::operator==(const CharacterMinimalPlusLookInformations &compared)
{
  if(entityLook == compared.entityLook)
  if(breed == compared.breed)
  if(_entityLooktree == compared._entityLooktree)
  return true;
  
  return false;
}

