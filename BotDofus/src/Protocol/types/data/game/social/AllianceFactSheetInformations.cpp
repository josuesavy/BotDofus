#include "AllianceFactSheetInformations.h"

void AllianceFactSheetInformations::serialize(Writer *output)
{
  this->serializeAs_AllianceFactSheetInformations(output);
}

void AllianceFactSheetInformations::serializeAs_AllianceFactSheetInformations(Writer *output)
{
  AllianceInformations::serializeAs_AllianceInformations(output);
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->creationDate << ") on element creationDate.";
  }
  output->writeInt((int)this->creationDate);
}

void AllianceFactSheetInformations::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFactSheetInformations(input);
}

void AllianceFactSheetInformations::deserializeAs_AllianceFactSheetInformations(Reader *input)
{
  AllianceInformations::deserialize(input);
  this->_creationDateFunc(input);
}

void AllianceFactSheetInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFactSheetInformations(tree);
}

void AllianceFactSheetInformations::deserializeAsyncAs_AllianceFactSheetInformations(FuncTree tree)
{
  AllianceInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&AllianceFactSheetInformations::_creationDateFunc, this, std::placeholders::_1));
}

void AllianceFactSheetInformations::_creationDateFunc(Reader *input)
{
  this->creationDate = input->readInt();
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->creationDate << ") on element of AllianceFactSheetInformations.creationDate.";
  }
}

AllianceFactSheetInformations::AllianceFactSheetInformations()
{
  m_types<<ClassEnum::ALLIANCEFACTSHEETINFORMATIONS;
}

bool AllianceFactSheetInformations::operator==(const AllianceFactSheetInformations &compared)
{
  if(creationDate == compared.creationDate)
  return true;
  
  return false;
}

