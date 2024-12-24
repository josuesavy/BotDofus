#include "ActorAlignmentInformations.h"

void ActorAlignmentInformations::serialize(Writer *output)
{
  this->serializeAs_ActorAlignmentInformations(output);
}

void ActorAlignmentInformations::serializeAs_ActorAlignmentInformations(Writer *output)
{
  output->writeByte(this->alignmentSide);
  if(this->alignmentValue < 0)
  {
    qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->alignmentValue << ") on element alignmentValue.";
  }
  output->writeByte(this->alignmentValue);
  if(this->alignmentGrade < 0)
  {
    qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->alignmentGrade << ") on element alignmentGrade.";
  }
  output->writeByte(this->alignmentGrade);
  if(this->characterPower < -9007199254740992 || this->characterPower > 9007199254740992)
  {
    qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->characterPower << ") on element characterPower.";
  }
  output->writeDouble(this->characterPower);
}

void ActorAlignmentInformations::deserialize(Reader *input)
{
  this->deserializeAs_ActorAlignmentInformations(input);
}

void ActorAlignmentInformations::deserializeAs_ActorAlignmentInformations(Reader *input)
{
  this->_alignmentSideFunc(input);
  this->_alignmentValueFunc(input);
  this->_alignmentGradeFunc(input);
  this->_characterPowerFunc(input);
}

void ActorAlignmentInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ActorAlignmentInformations(tree);
}

void ActorAlignmentInformations::deserializeAsyncAs_ActorAlignmentInformations(FuncTree tree)
{
  tree.addChild(std::bind(&ActorAlignmentInformations::_alignmentSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActorAlignmentInformations::_alignmentValueFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActorAlignmentInformations::_alignmentGradeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActorAlignmentInformations::_characterPowerFunc, this, std::placeholders::_1));
}

void ActorAlignmentInformations::_alignmentSideFunc(Reader *input)
{
  this->alignmentSide = input->readByte();
}

void ActorAlignmentInformations::_alignmentValueFunc(Reader *input)
{
  this->alignmentValue = input->readByte();
  if(this->alignmentValue < 0)
  {
    qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->alignmentValue << ") on element of ActorAlignmentInformations.alignmentValue.";
  }
}

void ActorAlignmentInformations::_alignmentGradeFunc(Reader *input)
{
  this->alignmentGrade = input->readByte();
  if(this->alignmentGrade < 0)
  {
    qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->alignmentGrade << ") on element of ActorAlignmentInformations.alignmentGrade.";
  }
}

void ActorAlignmentInformations::_characterPowerFunc(Reader *input)
{
  this->characterPower = input->readDouble();
  if(this->characterPower < -9007199254740992 || this->characterPower > 9007199254740992)
  {
    qDebug()<<"ERREUR - ActorAlignmentInformations -"<<"Forbidden value (" << this->characterPower << ") on element of ActorAlignmentInformations.characterPower.";
  }
}

ActorAlignmentInformations::ActorAlignmentInformations()
{
  m_types<<ClassEnum::ACTORALIGNMENTINFORMATIONS;
}

bool ActorAlignmentInformations::operator==(const ActorAlignmentInformations &compared)
{
  if(alignmentSide == compared.alignmentSide)
  if(alignmentValue == compared.alignmentValue)
  if(alignmentGrade == compared.alignmentGrade)
  if(characterPower == compared.characterPower)
  return true;
  
  return false;
}

