#include "NamedPartyTeam.h"

void NamedPartyTeam::serialize(Writer *output)
{
  this->serializeAs_NamedPartyTeam(output);
}

void NamedPartyTeam::serializeAs_NamedPartyTeam(Writer *output)
{
  output->writeByte(this->teamId);
  output->writeUTF(this->partyName);
}

void NamedPartyTeam::deserialize(Reader *input)
{
  this->deserializeAs_NamedPartyTeam(input);
}

void NamedPartyTeam::deserializeAs_NamedPartyTeam(Reader *input)
{
  this->_teamIdFunc(input);
  this->_partyNameFunc(input);
}

void NamedPartyTeam::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NamedPartyTeam(tree);
}

void NamedPartyTeam::deserializeAsyncAs_NamedPartyTeam(FuncTree tree)
{
  tree.addChild(std::bind(&NamedPartyTeam::_teamIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&NamedPartyTeam::_partyNameFunc, this, std::placeholders::_1));
}

void NamedPartyTeam::_teamIdFunc(Reader *input)
{
  this->teamId = input->readByte();
  if(this->teamId < 0)
  {
    qDebug()<<"ERREUR - NamedPartyTeam -"<<"Forbidden value (" << this->teamId << ") on element of NamedPartyTeam.teamId.";
  }
}

void NamedPartyTeam::_partyNameFunc(Reader *input)
{
  this->partyName = input->readUTF();
}

NamedPartyTeam::NamedPartyTeam()
{
  m_types<<ClassEnum::NAMEDPARTYTEAM;
}

bool NamedPartyTeam::operator==(const NamedPartyTeam &compared)
{
  if(teamId == compared.teamId)
  if(partyName == compared.partyName)
  return true;
  
  return false;
}

