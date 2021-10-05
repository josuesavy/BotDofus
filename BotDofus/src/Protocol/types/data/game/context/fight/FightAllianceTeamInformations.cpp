#include "FightAllianceTeamInformations.h"

void FightAllianceTeamInformations::serialize(Writer *output)
{
  this->serializeAs_FightAllianceTeamInformations(output);
}

void FightAllianceTeamInformations::serializeAs_FightAllianceTeamInformations(Writer *output)
{
  FightTeamInformations::serializeAs_FightTeamInformations(output);
  output->writeByte(this->relation);
}

void FightAllianceTeamInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightAllianceTeamInformations(input);
}

void FightAllianceTeamInformations::deserializeAs_FightAllianceTeamInformations(Reader *input)
{
  FightTeamInformations::deserialize(input);
  this->_relationFunc(input);
}

void FightAllianceTeamInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightAllianceTeamInformations(tree);
}

void FightAllianceTeamInformations::deserializeAsyncAs_FightAllianceTeamInformations(FuncTree tree)
{
  FightTeamInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FightAllianceTeamInformations::_relationFunc, this, std::placeholders::_1));
}

void FightAllianceTeamInformations::_relationFunc(Reader *input)
{
  this->relation = input->readByte();
  if(this->relation < 0)
  {
    qDebug()<<"ERREUR - FightAllianceTeamInformations -"<<"Forbidden value (" << this->relation << ") on element of FightAllianceTeamInformations.relation.";
  }
}

FightAllianceTeamInformations::FightAllianceTeamInformations()
{
  m_types<<ClassEnum::FIGHTALLIANCETEAMINFORMATIONS;
}

bool FightAllianceTeamInformations::operator==(const FightAllianceTeamInformations &compared)
{
  if(relation == compared.relation)
  return true;
  
  return false;
}

