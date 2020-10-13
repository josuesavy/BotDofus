#include "GuildInAllianceVersatileInformations.h"

void GuildInAllianceVersatileInformations::serialize(Writer *output)
{
  this->serializeAs_GuildInAllianceVersatileInformations(output);
}

void GuildInAllianceVersatileInformations::serializeAs_GuildInAllianceVersatileInformations(Writer *output)
{
  GuildVersatileInformations::serializeAs_GuildVersatileInformations(output);
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - GuildInAllianceVersatileInformations -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  output->writeVarInt((int)this->allianceId);
}

void GuildInAllianceVersatileInformations::deserialize(Reader *input)
{
  this->deserializeAs_GuildInAllianceVersatileInformations(input);
}

void GuildInAllianceVersatileInformations::deserializeAs_GuildInAllianceVersatileInformations(Reader *input)
{
  GuildVersatileInformations::deserialize(input);
  this->_allianceIdFunc(input);
}

void GuildInAllianceVersatileInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInAllianceVersatileInformations(tree);
}

void GuildInAllianceVersatileInformations::deserializeAsyncAs_GuildInAllianceVersatileInformations(FuncTree tree)
{
  GuildVersatileInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildInAllianceVersatileInformations::_allianceIdFunc, this, std::placeholders::_1));
}

void GuildInAllianceVersatileInformations::_allianceIdFunc(Reader *input)
{
  this->allianceId = input->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - GuildInAllianceVersatileInformations -"<<"Forbidden value (" << this->allianceId << ") on element of GuildInAllianceVersatileInformations.allianceId.";
  }
}

GuildInAllianceVersatileInformations::GuildInAllianceVersatileInformations()
{
  m_types<<ClassEnum::GUILDINALLIANCEVERSATILEINFORMATIONS;
}

bool GuildInAllianceVersatileInformations::operator==(const GuildInAllianceVersatileInformations &compared)
{
  if(allianceId == compared.allianceId)
  return true;
  
  return false;
}

