#include "AbstractFightTeamInformations.h"

void AbstractFightTeamInformations::serialize(Writer *output)
{
  this->serializeAs_AbstractFightTeamInformations(output);
}

void AbstractFightTeamInformations::serializeAs_AbstractFightTeamInformations(Writer *output)
{
  output->writeByte(this->teamId);
  if(this->leaderId < -9.007199254740992E15 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->leaderId << ") on element leaderId.";
  }
  output->writeDouble(this->leaderId);
  output->writeByte(this->teamSide);
  output->writeByte(this->teamTypeId);
  if(this->nbWaves < 0)
  {
    qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->nbWaves << ") on element nbWaves.";
  }
  output->writeByte(this->nbWaves);
}

void AbstractFightTeamInformations::deserialize(Reader *input)
{
  this->deserializeAs_AbstractFightTeamInformations(input);
}

void AbstractFightTeamInformations::deserializeAs_AbstractFightTeamInformations(Reader *input)
{
  this->_teamIdFunc(input);
  this->_leaderIdFunc(input);
  this->_teamSideFunc(input);
  this->_teamTypeIdFunc(input);
  this->_nbWavesFunc(input);
}

void AbstractFightTeamInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractFightTeamInformations(tree);
}

void AbstractFightTeamInformations::deserializeAsyncAs_AbstractFightTeamInformations(FuncTree tree)
{
  tree.addChild(std::bind(&AbstractFightTeamInformations::_teamIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightTeamInformations::_leaderIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightTeamInformations::_teamSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightTeamInformations::_teamTypeIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractFightTeamInformations::_nbWavesFunc, this, std::placeholders::_1));
}

void AbstractFightTeamInformations::_teamIdFunc(Reader *input)
{
  this->teamId = input->readByte();
  if(this->teamId < 0)
  {
    qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->teamId << ") on element of AbstractFightTeamInformations.teamId.";
  }
}

void AbstractFightTeamInformations::_leaderIdFunc(Reader *input)
{
  this->leaderId = input->readDouble();
  if(this->leaderId < -9.007199254740992E15 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->leaderId << ") on element of AbstractFightTeamInformations.leaderId.";
  }
}

void AbstractFightTeamInformations::_teamSideFunc(Reader *input)
{
  this->teamSide = input->readByte();
}

void AbstractFightTeamInformations::_teamTypeIdFunc(Reader *input)
{
  this->teamTypeId = input->readByte();
  if(this->teamTypeId < 0)
  {
    qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->teamTypeId << ") on element of AbstractFightTeamInformations.teamTypeId.";
  }
}

void AbstractFightTeamInformations::_nbWavesFunc(Reader *input)
{
  this->nbWaves = input->readByte();
  if(this->nbWaves < 0)
  {
    qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->nbWaves << ") on element of AbstractFightTeamInformations.nbWaves.";
  }
}

AbstractFightTeamInformations::AbstractFightTeamInformations()
{
  m_types<<ClassEnum::ABSTRACTFIGHTTEAMINFORMATIONS;
}

bool AbstractFightTeamInformations::operator==(const AbstractFightTeamInformations &compared)
{
  if(teamId == compared.teamId)
  if(leaderId == compared.leaderId)
  if(teamSide == compared.teamSide)
  if(teamTypeId == compared.teamTypeId)
  if(nbWaves == compared.nbWaves)
  return true;
  
  return false;
}

