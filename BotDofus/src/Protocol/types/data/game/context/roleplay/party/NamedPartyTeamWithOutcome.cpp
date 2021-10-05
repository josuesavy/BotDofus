#include "NamedPartyTeamWithOutcome.h"

void NamedPartyTeamWithOutcome::serialize(Writer *output)
{
  this->serializeAs_NamedPartyTeamWithOutcome(output);
}

void NamedPartyTeamWithOutcome::serializeAs_NamedPartyTeamWithOutcome(Writer *output)
{
  this->team.serializeAs_NamedPartyTeam(output);
  output->writeVarShort((int)this->outcome);
}

void NamedPartyTeamWithOutcome::deserialize(Reader *input)
{
  this->deserializeAs_NamedPartyTeamWithOutcome(input);
}

void NamedPartyTeamWithOutcome::deserializeAs_NamedPartyTeamWithOutcome(Reader *input)
{
  this->team = NamedPartyTeam();
  this->team.deserialize(input);
  this->_outcomeFunc(input);
}

void NamedPartyTeamWithOutcome::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NamedPartyTeamWithOutcome(tree);
}

void NamedPartyTeamWithOutcome::deserializeAsyncAs_NamedPartyTeamWithOutcome(FuncTree tree)
{
  this->_teamtree = tree.addChild(std::bind(&NamedPartyTeamWithOutcome::_teamtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&NamedPartyTeamWithOutcome::_outcomeFunc, this, std::placeholders::_1));
}

void NamedPartyTeamWithOutcome::_teamtreeFunc(Reader *input)
{
  this->team = NamedPartyTeam();
  this->team.deserializeAsync(this->_teamtree);
}

void NamedPartyTeamWithOutcome::_outcomeFunc(Reader *input)
{
  this->outcome = input->readVarUhShort();
  if(this->outcome < 0)
  {
    qDebug()<<"ERREUR - NamedPartyTeamWithOutcome -"<<"Forbidden value (" << this->outcome << ") on element of NamedPartyTeamWithOutcome.outcome.";
  }
}

NamedPartyTeamWithOutcome::NamedPartyTeamWithOutcome()
{
  m_types<<ClassEnum::NAMEDPARTYTEAMWITHOUTCOME;
}

bool NamedPartyTeamWithOutcome::operator==(const NamedPartyTeamWithOutcome &compared)
{
  if(team == compared.team)
  if(outcome == compared.outcome)
  if(_teamtree == compared._teamtree)
  return true;
  
  return false;
}

