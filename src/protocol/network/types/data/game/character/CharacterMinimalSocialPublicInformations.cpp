#include "CharacterMinimalSocialPublicInformations.h"

void CharacterMinimalSocialPublicInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterMinimalSocialPublicInformations(output);
}

void CharacterMinimalSocialPublicInformations::serializeAs_CharacterMinimalSocialPublicInformations(Writer *output)
{
  CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(output);
  this->rank.serializeAs_RankPublicInformation(output);
}

void CharacterMinimalSocialPublicInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterMinimalSocialPublicInformations(input);
}

void CharacterMinimalSocialPublicInformations::deserializeAs_CharacterMinimalSocialPublicInformations(Reader *input)
{
  CharacterMinimalInformations::deserialize(input);
  this->rank = RankPublicInformation();
  this->rank.deserialize(input);
}

void CharacterMinimalSocialPublicInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterMinimalSocialPublicInformations(tree);
}

void CharacterMinimalSocialPublicInformations::deserializeAsyncAs_CharacterMinimalSocialPublicInformations(FuncTree tree)
{
  CharacterMinimalInformations::deserializeAsync(tree);
  this->_ranktree = tree.addChild(std::bind(&CharacterMinimalSocialPublicInformations::_ranktreeFunc, this, std::placeholders::_1));
}

void CharacterMinimalSocialPublicInformations::_ranktreeFunc(Reader *input)
{
  this->rank = RankPublicInformation();
  this->rank.deserializeAsync(this->_ranktree);
}

CharacterMinimalSocialPublicInformations::CharacterMinimalSocialPublicInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALSOCIALPUBLICINFORMATIONS;
}

bool CharacterMinimalSocialPublicInformations::operator==(const CharacterMinimalSocialPublicInformations &compared)
{
  if(rank == compared.rank)
  if(_ranktree == compared._ranktree)
  return true;
  
  return false;
}

