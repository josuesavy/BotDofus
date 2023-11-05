#include "AllianceFactSheetInformation.h"

void AllianceFactSheetInformation::serialize(Writer *output)
{
  this->serializeAs_AllianceFactSheetInformation(output);
}

void AllianceFactSheetInformation::serializeAs_AllianceFactSheetInformation(Writer *output)
{
  AllianceInformation::serializeAs_AllianceInformation(output);
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformation -"<<"Forbidden value (" << this->creationDate << ") on element creationDate.";
  }
  output->writeInt((int)this->creationDate);
  if(this->nbMembers < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformation -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
  }
  output->writeVarShort((int)this->nbMembers);
  if(this->nbSubarea < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformation -"<<"Forbidden value (" << this->nbSubarea << ") on element nbSubarea.";
  }
  output->writeVarShort((int)this->nbSubarea);
  if(this->nbTaxCollectors < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformation -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element nbTaxCollectors.";
  }
  output->writeVarShort((int)this->nbTaxCollectors);
  this->recruitment.serializeAs_AllianceRecruitmentInformation(output);
}

void AllianceFactSheetInformation::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFactSheetInformation(input);
}

void AllianceFactSheetInformation::deserializeAs_AllianceFactSheetInformation(Reader *input)
{
  AllianceInformation::deserialize(input);
  this->_creationDateFunc(input);
  this->_nbMembersFunc(input);
  this->_nbSubareaFunc(input);
  this->_nbTaxCollectorsFunc(input);
  this->recruitment = AllianceRecruitmentInformation();
  this->recruitment.deserialize(input);
}

void AllianceFactSheetInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFactSheetInformation(tree);
}

void AllianceFactSheetInformation::deserializeAsyncAs_AllianceFactSheetInformation(FuncTree tree)
{
  AllianceInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&AllianceFactSheetInformation::_creationDateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactSheetInformation::_nbMembersFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactSheetInformation::_nbSubareaFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactSheetInformation::_nbTaxCollectorsFunc, this, std::placeholders::_1));
  this->_recruitmenttree = tree.addChild(std::bind(&AllianceFactSheetInformation::_recruitmenttreeFunc, this, std::placeholders::_1));
}

void AllianceFactSheetInformation::_creationDateFunc(Reader *input)
{
  this->creationDate = input->readInt();
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformation -"<<"Forbidden value (" << this->creationDate << ") on element of AllianceFactSheetInformation.creationDate.";
  }
}

void AllianceFactSheetInformation::_nbMembersFunc(Reader *input)
{
  this->nbMembers = input->readVarUhShort();
  if(this->nbMembers < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformation -"<<"Forbidden value (" << this->nbMembers << ") on element of AllianceFactSheetInformation.nbMembers.";
  }
}

void AllianceFactSheetInformation::_nbSubareaFunc(Reader *input)
{
  this->nbSubarea = input->readVarUhShort();
  if(this->nbSubarea < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformation -"<<"Forbidden value (" << this->nbSubarea << ") on element of AllianceFactSheetInformation.nbSubarea.";
  }
}

void AllianceFactSheetInformation::_nbTaxCollectorsFunc(Reader *input)
{
  this->nbTaxCollectors = input->readVarUhShort();
  if(this->nbTaxCollectors < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformation -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element of AllianceFactSheetInformation.nbTaxCollectors.";
  }
}

void AllianceFactSheetInformation::_recruitmenttreeFunc(Reader *input)
{
  this->recruitment = AllianceRecruitmentInformation();
  this->recruitment.deserializeAsync(this->_recruitmenttree);
}

AllianceFactSheetInformation::AllianceFactSheetInformation()
{
  m_types<<ClassEnum::ALLIANCEFACTSHEETINFORMATION;
}

bool AllianceFactSheetInformation::operator==(const AllianceFactSheetInformation &compared)
{
  if(creationDate == compared.creationDate)
  if(nbMembers == compared.nbMembers)
  if(nbSubarea == compared.nbSubarea)
  if(nbTaxCollectors == compared.nbTaxCollectors)
  if(recruitment == compared.recruitment)
  if(_recruitmenttree == compared._recruitmenttree)
  return true;
  
  return false;
}

