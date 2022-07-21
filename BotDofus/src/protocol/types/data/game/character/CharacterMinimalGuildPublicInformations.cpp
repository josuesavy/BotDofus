#include "CharacterMinimalGuildPublicInformations.h"

void CharacterMinimalGuildPublicInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterMinimalGuildPublicInformations(output);
}

void CharacterMinimalGuildPublicInformations::serializeAs_CharacterMinimalGuildPublicInformations(Writer *output)
{
  CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(output);
  this->rank.serializeAs_GuildRankPublicInformation(output);
}

void CharacterMinimalGuildPublicInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterMinimalGuildPublicInformations(input);
}

void CharacterMinimalGuildPublicInformations::deserializeAs_CharacterMinimalGuildPublicInformations(Reader *input)
{
  CharacterMinimalInformations::deserialize(input);
  this->rank = GuildRankPublicInformation();
  this->rank.deserialize(input);
}

void CharacterMinimalGuildPublicInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterMinimalGuildPublicInformations(tree);
}

void CharacterMinimalGuildPublicInformations::deserializeAsyncAs_CharacterMinimalGuildPublicInformations(FuncTree tree)
{
  CharacterMinimalInformations::deserializeAsync(tree);
  this->_ranktree = tree.addChild(std::bind(&CharacterMinimalGuildPublicInformations::_ranktreeFunc, this, std::placeholders::_1));
}

void CharacterMinimalGuildPublicInformations::_ranktreeFunc(Reader *input)
{
  this->rank = GuildRankPublicInformation();
  this->rank.deserializeAsync(this->_ranktree);
}

CharacterMinimalGuildPublicInformations::CharacterMinimalGuildPublicInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALGUILDPUBLICINFORMATIONS;
}

bool CharacterMinimalGuildPublicInformations::operator==(const CharacterMinimalGuildPublicInformations &compared)
{
  if(rank == compared.rank)
  if(_ranktree == compared._ranktree)
  return true;
  
  return false;
}

