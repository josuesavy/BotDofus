#include "GuildInsiderFactSheetInformations.h"

void GuildInsiderFactSheetInformations::serialize(Writer *output)
{
  this->serializeAs_GuildInsiderFactSheetInformations(output);
}

void GuildInsiderFactSheetInformations::serializeAs_GuildInsiderFactSheetInformations(Writer *output)
{
  GuildFactSheetInformations::serializeAs_GuildFactSheetInformations(output);
  output->writeUTF(this->leaderName);
  if(this->nbConnectedMembers < 0)
  {
    qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->nbConnectedMembers << ") on element nbConnectedMembers.";
  }
  output->writeVarShort((int)this->nbConnectedMembers);
  if(this->nbTaxCollectors < 0)
  {
    qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element nbTaxCollectors.";
  }
  output->writeByte(this->nbTaxCollectors);
}

void GuildInsiderFactSheetInformations::deserialize(Reader *input)
{
  this->deserializeAs_GuildInsiderFactSheetInformations(input);
}

void GuildInsiderFactSheetInformations::deserializeAs_GuildInsiderFactSheetInformations(Reader *input)
{
  GuildFactSheetInformations::deserialize(input);
  this->_leaderNameFunc(input);
  this->_nbConnectedMembersFunc(input);
  this->_nbTaxCollectorsFunc(input);
}

void GuildInsiderFactSheetInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInsiderFactSheetInformations(tree);
}

void GuildInsiderFactSheetInformations::deserializeAsyncAs_GuildInsiderFactSheetInformations(FuncTree tree)
{
  GuildFactSheetInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildInsiderFactSheetInformations::_leaderNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInsiderFactSheetInformations::_nbConnectedMembersFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInsiderFactSheetInformations::_nbTaxCollectorsFunc, this, std::placeholders::_1));
}

void GuildInsiderFactSheetInformations::_leaderNameFunc(Reader *input)
{
  this->leaderName = input->readUTF();
}

void GuildInsiderFactSheetInformations::_nbConnectedMembersFunc(Reader *input)
{
  this->nbConnectedMembers = input->readVarUhShort();
  if(this->nbConnectedMembers < 0)
  {
    qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->nbConnectedMembers << ") on element of GuildInsiderFactSheetInformations.nbConnectedMembers.";
  }
}

void GuildInsiderFactSheetInformations::_nbTaxCollectorsFunc(Reader *input)
{
  this->nbTaxCollectors = input->readByte();
  if(this->nbTaxCollectors < 0)
  {
    qDebug()<<"ERREUR - GuildInsiderFactSheetInformations -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element of GuildInsiderFactSheetInformations.nbTaxCollectors.";
  }
}

GuildInsiderFactSheetInformations::GuildInsiderFactSheetInformations()
{
  m_types<<ClassEnum::GUILDINSIDERFACTSHEETINFORMATIONS;
}

bool GuildInsiderFactSheetInformations::operator==(const GuildInsiderFactSheetInformations &compared)
{
  if(leaderName == compared.leaderName)
  if(nbConnectedMembers == compared.nbConnectedMembers)
  if(nbTaxCollectors == compared.nbTaxCollectors)
  return true;
  
  return false;
}

