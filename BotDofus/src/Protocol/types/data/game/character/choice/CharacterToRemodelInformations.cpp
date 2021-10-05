#include "CharacterToRemodelInformations.h"

void CharacterToRemodelInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterToRemodelInformations(output);
}

void CharacterToRemodelInformations::serializeAs_CharacterToRemodelInformations(Writer *output)
{
  CharacterRemodelingInformation::serializeAs_CharacterRemodelingInformation(output);
  if(this->possibleChangeMask < 0)
  {
    qDebug()<<"ERREUR - CharacterToRemodelInformations -"<<"Forbidden value (" << this->possibleChangeMask << ") on element possibleChangeMask.";
  }
  output->writeByte(this->possibleChangeMask);
  if(this->mandatoryChangeMask < 0)
  {
    qDebug()<<"ERREUR - CharacterToRemodelInformations -"<<"Forbidden value (" << this->mandatoryChangeMask << ") on element mandatoryChangeMask.";
  }
  output->writeByte(this->mandatoryChangeMask);
}

void CharacterToRemodelInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterToRemodelInformations(input);
}

void CharacterToRemodelInformations::deserializeAs_CharacterToRemodelInformations(Reader *input)
{
  CharacterRemodelingInformation::deserialize(input);
  this->_possibleChangeMaskFunc(input);
  this->_mandatoryChangeMaskFunc(input);
}

void CharacterToRemodelInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterToRemodelInformations(tree);
}

void CharacterToRemodelInformations::deserializeAsyncAs_CharacterToRemodelInformations(FuncTree tree)
{
  CharacterRemodelingInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterToRemodelInformations::_possibleChangeMaskFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterToRemodelInformations::_mandatoryChangeMaskFunc, this, std::placeholders::_1));
}

void CharacterToRemodelInformations::_possibleChangeMaskFunc(Reader *input)
{
  this->possibleChangeMask = input->readByte();
  if(this->possibleChangeMask < 0)
  {
    qDebug()<<"ERREUR - CharacterToRemodelInformations -"<<"Forbidden value (" << this->possibleChangeMask << ") on element of CharacterToRemodelInformations.possibleChangeMask.";
  }
}

void CharacterToRemodelInformations::_mandatoryChangeMaskFunc(Reader *input)
{
  this->mandatoryChangeMask = input->readByte();
  if(this->mandatoryChangeMask < 0)
  {
    qDebug()<<"ERREUR - CharacterToRemodelInformations -"<<"Forbidden value (" << this->mandatoryChangeMask << ") on element of CharacterToRemodelInformations.mandatoryChangeMask.";
  }
}

CharacterToRemodelInformations::CharacterToRemodelInformations()
{
  m_types<<ClassEnum::CHARACTERTOREMODELINFORMATIONS;
}

bool CharacterToRemodelInformations::operator==(const CharacterToRemodelInformations &compared)
{
  if(possibleChangeMask == compared.possibleChangeMask)
  if(mandatoryChangeMask == compared.mandatoryChangeMask)
  return true;
  
  return false;
}

