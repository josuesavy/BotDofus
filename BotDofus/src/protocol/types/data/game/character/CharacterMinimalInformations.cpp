#include "CharacterMinimalInformations.h"

void CharacterMinimalInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterMinimalInformations(output);
}

void CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(Writer *output)
{
  CharacterBasicMinimalInformations::serializeAs_CharacterBasicMinimalInformations(output);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - CharacterMinimalInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
}

void CharacterMinimalInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterMinimalInformations(input);
}

void CharacterMinimalInformations::deserializeAs_CharacterMinimalInformations(Reader *input)
{
  CharacterBasicMinimalInformations::deserialize(input);
  this->_levelFunc(input);
}

void CharacterMinimalInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterMinimalInformations(tree);
}

void CharacterMinimalInformations::deserializeAsyncAs_CharacterMinimalInformations(FuncTree tree)
{
  CharacterBasicMinimalInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterMinimalInformations::_levelFunc, this, std::placeholders::_1));
}

void CharacterMinimalInformations::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - CharacterMinimalInformations -"<<"Forbidden value (" << this->level << ") on element of CharacterMinimalInformations.level.";
  }
}

CharacterMinimalInformations::CharacterMinimalInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALINFORMATIONS;
}

bool CharacterMinimalInformations::operator==(const CharacterMinimalInformations &compared)
{
  if(level == compared.level)
  return true;
  
  return false;
}

