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
  if(this->nbGuilds < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->nbGuilds << ") on element nbGuilds.";
  }
  output->writeVarShort((int)this->nbGuilds);
  if(this->nbMembers < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
  }
  output->writeVarShort((int)this->nbMembers);
  if(this->nbSubarea < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->nbSubarea << ") on element nbSubarea.";
  }
  output->writeVarShort((int)this->nbSubarea);
}

void AllianceFactSheetInformations::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFactSheetInformations(input);
}

void AllianceFactSheetInformations::deserializeAs_AllianceFactSheetInformations(Reader *input)
{
  AllianceInformations::deserialize(input);
  this->_creationDateFunc(input);
  this->_nbGuildsFunc(input);
  this->_nbMembersFunc(input);
  this->_nbSubareaFunc(input);
}

void AllianceFactSheetInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFactSheetInformations(tree);
}

void AllianceFactSheetInformations::deserializeAsyncAs_AllianceFactSheetInformations(FuncTree tree)
{
  AllianceInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&AllianceFactSheetInformations::_creationDateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactSheetInformations::_nbGuildsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactSheetInformations::_nbMembersFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFactSheetInformations::_nbSubareaFunc, this, std::placeholders::_1));
}

void AllianceFactSheetInformations::_creationDateFunc(Reader *input)
{
  this->creationDate = input->readInt();
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->creationDate << ") on element of AllianceFactSheetInformations.creationDate.";
  }
}

void AllianceFactSheetInformations::_nbGuildsFunc(Reader *input)
{
  this->nbGuilds = input->readVarUhShort();
  if(this->nbGuilds < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->nbGuilds << ") on element of AllianceFactSheetInformations.nbGuilds.";
  }
}

void AllianceFactSheetInformations::_nbMembersFunc(Reader *input)
{
  this->nbMembers = input->readVarUhShort();
  if(this->nbMembers < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->nbMembers << ") on element of AllianceFactSheetInformations.nbMembers.";
  }
}

void AllianceFactSheetInformations::_nbSubareaFunc(Reader *input)
{
  this->nbSubarea = input->readVarUhShort();
  if(this->nbSubarea < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->nbSubarea << ") on element of AllianceFactSheetInformations.nbSubarea.";
  }
}

AllianceFactSheetInformations::AllianceFactSheetInformations()
{
  m_types<<ClassEnum::ALLIANCEFACTSHEETINFORMATIONS;
}

bool AllianceFactSheetInformations::operator==(const AllianceFactSheetInformations &compared)
{
  if(creationDate == compared.creationDate)
  if(nbGuilds == compared.nbGuilds)
  if(nbMembers == compared.nbMembers)
  if(nbSubarea == compared.nbSubarea)
  return true;
  
  return false;
}

