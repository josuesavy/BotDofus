#include "CharacterMinimalGuildPublicInformations.h"

void CharacterMinimalGuildPublicInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterMinimalGuildPublicInformations(output);
}

void CharacterMinimalGuildPublicInformations::serializeAs_CharacterMinimalGuildPublicInformations(Writer *output)
{
  CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(output);
  if(this->rank < 0)
  {
    qDebug()<<"ERREUR - CharacterMinimalGuildPublicInformations -"<<"Forbidden value (" << this->rank << ") on element rank.";
  }
  output->writeVarInt((int)this->rank);
}

void CharacterMinimalGuildPublicInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterMinimalGuildPublicInformations(input);
}

void CharacterMinimalGuildPublicInformations::deserializeAs_CharacterMinimalGuildPublicInformations(Reader *input)
{
  CharacterMinimalInformations::deserialize(input);
  this->_rankFunc(input);
}

void CharacterMinimalGuildPublicInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterMinimalGuildPublicInformations(tree);
}

void CharacterMinimalGuildPublicInformations::deserializeAsyncAs_CharacterMinimalGuildPublicInformations(FuncTree tree)
{
  CharacterMinimalInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterMinimalGuildPublicInformations::_rankFunc, this, std::placeholders::_1));
}

void CharacterMinimalGuildPublicInformations::_rankFunc(Reader *input)
{
  this->rank = input->readVarUhInt();
  if(this->rank < 0)
  {
    qDebug()<<"ERREUR - CharacterMinimalGuildPublicInformations -"<<"Forbidden value (" << this->rank << ") on element of CharacterMinimalGuildPublicInformations.rank.";
  }
}

CharacterMinimalGuildPublicInformations::CharacterMinimalGuildPublicInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALGUILDPUBLICINFORMATIONS;
}

bool CharacterMinimalGuildPublicInformations::operator==(const CharacterMinimalGuildPublicInformations &compared)
{
  if(rank == compared.rank)
  return true;
  
  return false;
}

