#include "AllianceVersatileInformations.h"

void AllianceVersatileInformations::serialize(Writer *output)
{
  this->serializeAs_AllianceVersatileInformations(output);
}

void AllianceVersatileInformations::serializeAs_AllianceVersatileInformations(Writer *output)
{
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  output->writeVarInt((int)this->allianceId);
  if(this->nbGuilds < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbGuilds << ") on element nbGuilds.";
  }
  output->writeVarShort((int)this->nbGuilds);
  if(this->nbMembers < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
  }
  output->writeVarShort((int)this->nbMembers);
  if(this->nbSubarea < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbSubarea << ") on element nbSubarea.";
  }
  output->writeVarShort((int)this->nbSubarea);
}

void AllianceVersatileInformations::deserialize(Reader *input)
{
  this->deserializeAs_AllianceVersatileInformations(input);
}

void AllianceVersatileInformations::deserializeAs_AllianceVersatileInformations(Reader *input)
{
  this->_allianceIdFunc(input);
  this->_nbGuildsFunc(input);
  this->_nbMembersFunc(input);
  this->_nbSubareaFunc(input);
}

void AllianceVersatileInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceVersatileInformations(tree);
}

void AllianceVersatileInformations::deserializeAsyncAs_AllianceVersatileInformations(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceVersatileInformations::_allianceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceVersatileInformations::_nbGuildsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceVersatileInformations::_nbMembersFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceVersatileInformations::_nbSubareaFunc, this, std::placeholders::_1));
}

void AllianceVersatileInformations::_allianceIdFunc(Reader *input)
{
  this->allianceId = input->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->allianceId << ") on element of AllianceVersatileInformations.allianceId.";
  }
}

void AllianceVersatileInformations::_nbGuildsFunc(Reader *input)
{
  this->nbGuilds = input->readVarUhShort();
  if(this->nbGuilds < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbGuilds << ") on element of AllianceVersatileInformations.nbGuilds.";
  }
}

void AllianceVersatileInformations::_nbMembersFunc(Reader *input)
{
  this->nbMembers = input->readVarUhShort();
  if(this->nbMembers < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbMembers << ") on element of AllianceVersatileInformations.nbMembers.";
  }
}

void AllianceVersatileInformations::_nbSubareaFunc(Reader *input)
{
  this->nbSubarea = input->readVarUhShort();
  if(this->nbSubarea < 0)
  {
    qDebug()<<"ERREUR - AllianceVersatileInformations -"<<"Forbidden value (" << this->nbSubarea << ") on element of AllianceVersatileInformations.nbSubarea.";
  }
}

AllianceVersatileInformations::AllianceVersatileInformations()
{
  m_types<<ClassEnum::ALLIANCEVERSATILEINFORMATIONS;
}

bool AllianceVersatileInformations::operator==(const AllianceVersatileInformations &compared)
{
  if(allianceId == compared.allianceId)
  if(nbGuilds == compared.nbGuilds)
  if(nbMembers == compared.nbMembers)
  if(nbSubarea == compared.nbSubarea)
  return true;
  
  return false;
}

