#include "CharacterHardcoreOrEpicInformations.h"

void CharacterHardcoreOrEpicInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterHardcoreOrEpicInformations(output);
}

void CharacterHardcoreOrEpicInformations::serializeAs_CharacterHardcoreOrEpicInformations(Writer *output)
{
  CharacterBaseInformations::serializeAs_CharacterBaseInformations(output);
  output->writeByte(this->deathState);
  if(this->deathCount < 0)
  {
    qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathCount << ") on element deathCount.";
  }
  output->writeVarShort((int)this->deathCount);
  if(this->deathMaxLevel < 0)
  {
    qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathMaxLevel << ") on element deathMaxLevel.";
  }
  output->writeVarShort((int)this->deathMaxLevel);
}

void CharacterHardcoreOrEpicInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterHardcoreOrEpicInformations(input);
}

void CharacterHardcoreOrEpicInformations::deserializeAs_CharacterHardcoreOrEpicInformations(Reader *input)
{
  CharacterBaseInformations::deserialize(input);
  this->_deathStateFunc(input);
  this->_deathCountFunc(input);
  this->_deathMaxLevelFunc(input);
}

void CharacterHardcoreOrEpicInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterHardcoreOrEpicInformations(tree);
}

void CharacterHardcoreOrEpicInformations::deserializeAsyncAs_CharacterHardcoreOrEpicInformations(FuncTree tree)
{
  CharacterBaseInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&CharacterHardcoreOrEpicInformations::_deathStateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterHardcoreOrEpicInformations::_deathCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterHardcoreOrEpicInformations::_deathMaxLevelFunc, this, std::placeholders::_1));
}

void CharacterHardcoreOrEpicInformations::_deathStateFunc(Reader *input)
{
  this->deathState = input->readByte();
  if(this->deathState < 0)
  {
    qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathState << ") on element of CharacterHardcoreOrEpicInformations.deathState.";
  }
}

void CharacterHardcoreOrEpicInformations::_deathCountFunc(Reader *input)
{
  this->deathCount = input->readVarUhShort();
  if(this->deathCount < 0)
  {
    qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathCount << ") on element of CharacterHardcoreOrEpicInformations.deathCount.";
  }
}

void CharacterHardcoreOrEpicInformations::_deathMaxLevelFunc(Reader *input)
{
  this->deathMaxLevel = input->readVarUhShort();
  if(this->deathMaxLevel < 0)
  {
    qDebug()<<"ERREUR - CharacterHardcoreOrEpicInformations -"<<"Forbidden value (" << this->deathMaxLevel << ") on element of CharacterHardcoreOrEpicInformations.deathMaxLevel.";
  }
}

CharacterHardcoreOrEpicInformations::CharacterHardcoreOrEpicInformations()
{
  m_types<<ClassEnum::CHARACTERHARDCOREOREPICINFORMATIONS;
}

bool CharacterHardcoreOrEpicInformations::operator==(const CharacterHardcoreOrEpicInformations &compared)
{
  if(deathState == compared.deathState)
  if(deathCount == compared.deathCount)
  if(deathMaxLevel == compared.deathMaxLevel)
  return true;
  
  return false;
}

