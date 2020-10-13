#include "FightTeamMemberWithAllianceCharacterInformations.h"

void FightTeamMemberWithAllianceCharacterInformations::serialize(Writer *output)
{
  this->serializeAs_FightTeamMemberWithAllianceCharacterInformations(output);
}

void FightTeamMemberWithAllianceCharacterInformations::serializeAs_FightTeamMemberWithAllianceCharacterInformations(Writer *output)
{
  FightTeamMemberCharacterInformations::serializeAs_FightTeamMemberCharacterInformations(output);
  this->allianceInfos->serializeAs_BasicAllianceInformations(output);
}

void FightTeamMemberWithAllianceCharacterInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightTeamMemberWithAllianceCharacterInformations(input);
}

void FightTeamMemberWithAllianceCharacterInformations::deserializeAs_FightTeamMemberWithAllianceCharacterInformations(Reader *input)
{
  FightTeamMemberCharacterInformations::deserialize(input);
  this->allianceInfos = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->allianceInfos->deserialize(input);
}

void FightTeamMemberWithAllianceCharacterInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTeamMemberWithAllianceCharacterInformations(tree);
}

void FightTeamMemberWithAllianceCharacterInformations::deserializeAsyncAs_FightTeamMemberWithAllianceCharacterInformations(FuncTree tree)
{
  FightTeamMemberCharacterInformations::deserializeAsync(tree);
  this->_allianceInfostree = tree.addChild(std::bind(&FightTeamMemberWithAllianceCharacterInformations::_allianceInfostreeFunc, this, std::placeholders::_1));
}

void FightTeamMemberWithAllianceCharacterInformations::_allianceInfostreeFunc(Reader *input)
{
  this->allianceInfos = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->allianceInfos->deserializeAsync(this->_allianceInfostree);
}

FightTeamMemberWithAllianceCharacterInformations::FightTeamMemberWithAllianceCharacterInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS;
}

bool FightTeamMemberWithAllianceCharacterInformations::operator==(const FightTeamMemberWithAllianceCharacterInformations &compared)
{
  if(allianceInfos == compared.allianceInfos)
  if(_allianceInfostree == compared._allianceInfostree)
  return true;
  
  return false;
}

