#include "CharacterMinimalPlusLookAndGradeInformations.h"

void CharacterMinimalPlusLookAndGradeInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterMinimalPlusLookAndGradeInformations(output);
}

void CharacterMinimalPlusLookAndGradeInformations::serializeAs_CharacterMinimalPlusLookAndGradeInformations(Writer *output)
{
  CharacterMinimalPlusLookInformations::serializeAs_CharacterMinimalPlusLookInformations(output);
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - CharacterMinimalPlusLookAndGradeInformations -"<<"Forbidden value (" << this->grade << ") on element grade.";
  }
  output->writeVarInt((int)this->grade);
}

void CharacterMinimalPlusLookAndGradeInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterMinimalPlusLookAndGradeInformations(input);
}

void CharacterMinimalPlusLookAndGradeInformations::deserializeAs_CharacterMinimalPlusLookAndGradeInformations(Reader *input)
{
  CharacterMinimalPlusLookInformations::deserialize(input);
  this->_gradeFunc(input);
}

void CharacterMinimalPlusLookAndGradeInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterMinimalPlusLookAndGradeInformations(tree);
}

void CharacterMinimalPlusLookAndGradeInformations::deserializeAsyncAs_CharacterMinimalPlusLookAndGradeInformations(FuncTree tree)
{
  CharacterMinimalPlusLookInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterMinimalPlusLookAndGradeInformations::_gradeFunc, this, std::placeholders::_1));
}

void CharacterMinimalPlusLookAndGradeInformations::_gradeFunc(Reader *input)
{
  this->grade = input->readVarUhInt();
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - CharacterMinimalPlusLookAndGradeInformations -"<<"Forbidden value (" << this->grade << ") on element of CharacterMinimalPlusLookAndGradeInformations.grade.";
  }
}

CharacterMinimalPlusLookAndGradeInformations::CharacterMinimalPlusLookAndGradeInformations()
{
  m_types<<ClassEnum::CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS;
}

bool CharacterMinimalPlusLookAndGradeInformations::operator==(const CharacterMinimalPlusLookAndGradeInformations &compared)
{
  if(grade == compared.grade)
  return true;
  
  return false;
}

