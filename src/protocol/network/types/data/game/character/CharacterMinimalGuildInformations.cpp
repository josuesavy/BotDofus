#include "CharacterMinimalGuildInformations.h"

void CharacterMinimalGuildInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterMinimalGuildInformations(output);
}

void CharacterMinimalGuildInformations::serializeAs_CharacterMinimalGuildInformations(Writer *output)
{
  CharacterMinimalPlusLookInformations::serializeAs_CharacterMinimalPlusLookInformations(output);
  this->guild->serializeAs_BasicGuildInformations(output);
}

void CharacterMinimalGuildInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterMinimalGuildInformations(input);
}

void CharacterMinimalGuildInformations::deserializeAs_CharacterMinimalGuildInformations(Reader *input)
{
  CharacterMinimalPlusLookInformations::deserialize(input);
  this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guild->deserialize(input);
}

void CharacterMinimalGuildInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterMinimalGuildInformations(tree);
}

void CharacterMinimalGuildInformations::deserializeAsyncAs_CharacterMinimalGuildInformations(FuncTree tree)
{
  CharacterMinimalPlusLookInformations::deserializeAsync(tree);
  this->_guildtree = tree.addChild(std::bind(&CharacterMinimalGuildInformations::_guildtreeFunc, this, std::placeholders::_1));
}

void CharacterMinimalGuildInformations::_guildtreeFunc(Reader *input)
{
  this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guild->deserializeAsync(this->_guildtree);
}

CharacterMinimalGuildInformations::CharacterMinimalGuildInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALGUILDINFORMATIONS;
}

bool CharacterMinimalGuildInformations::operator==(const CharacterMinimalGuildInformations &compared)
{
  if(guild == compared.guild)
  if(_guildtree == compared._guildtree)
  return true;
  
  return false;
}

