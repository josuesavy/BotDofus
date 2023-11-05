#include "FightTeamLightInformations.h"

void FightTeamLightInformations::serialize(Writer *output)
{
  this->serializeAs_FightTeamLightInformations(output);
}

void FightTeamLightInformations::serializeAs_FightTeamLightInformations(Writer *output)
{
  AbstractFightTeamInformations::serializeAs_AbstractFightTeamInformations(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->hasFriend);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->hasGuildMember);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->hasAllianceMember);
  _box0 = BooleanByteWrapper::setFlag(_box0, 3, this->hasGroupMember);
  _box0 = BooleanByteWrapper::setFlag(_box0, 4, this->hasMyTaxCollector);
  output->writeByte(_box0);
  if(this->teamMembersCount < 0)
  {
    qDebug()<<"ERREUR - FightTeamLightInformations -"<<"Forbidden value (" << this->teamMembersCount << ") on element teamMembersCount.";
  }
  output->writeByte(this->teamMembersCount);
  if(this->meanLevel < 0)
  {
    qDebug()<<"ERREUR - FightTeamLightInformations -"<<"Forbidden value (" << this->meanLevel << ") on element meanLevel.";
  }
  output->writeVarInt((int)this->meanLevel);
}

void FightTeamLightInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightTeamLightInformations(input);
}

void FightTeamLightInformations::deserializeAs_FightTeamLightInformations(Reader *input)
{
  AbstractFightTeamInformations::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_teamMembersCountFunc(input);
  this->_meanLevelFunc(input);
}

void FightTeamLightInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTeamLightInformations(tree);
}

void FightTeamLightInformations::deserializeAsyncAs_FightTeamLightInformations(FuncTree tree)
{
  AbstractFightTeamInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTeamLightInformations::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamLightInformations::_teamMembersCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamLightInformations::_meanLevelFunc, this, std::placeholders::_1));
}

void FightTeamLightInformations::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->hasFriend = BooleanByteWrapper::getFlag(_box0, 0);
  this->hasGuildMember = BooleanByteWrapper::getFlag(_box0, 1);
  this->hasAllianceMember = BooleanByteWrapper::getFlag(_box0, 2);
  this->hasGroupMember = BooleanByteWrapper::getFlag(_box0, 3);
  this->hasMyTaxCollector = BooleanByteWrapper::getFlag(_box0, 4);
}

void FightTeamLightInformations::_teamMembersCountFunc(Reader *input)
{
  this->teamMembersCount = input->readByte();
  if(this->teamMembersCount < 0)
  {
    qDebug()<<"ERREUR - FightTeamLightInformations -"<<"Forbidden value (" << this->teamMembersCount << ") on element of FightTeamLightInformations.teamMembersCount.";
  }
}

void FightTeamLightInformations::_meanLevelFunc(Reader *input)
{
  this->meanLevel = input->readVarUhInt();
  if(this->meanLevel < 0)
  {
    qDebug()<<"ERREUR - FightTeamLightInformations -"<<"Forbidden value (" << this->meanLevel << ") on element of FightTeamLightInformations.meanLevel.";
  }
}

FightTeamLightInformations::FightTeamLightInformations()
{
  m_types<<ClassEnum::FIGHTTEAMLIGHTINFORMATIONS;
}

bool FightTeamLightInformations::operator==(const FightTeamLightInformations &compared)
{
  if(teamMembersCount == compared.teamMembersCount)
  if(meanLevel == compared.meanLevel)
  if(hasFriend == compared.hasFriend)
  if(hasGuildMember == compared.hasGuildMember)
  if(hasAllianceMember == compared.hasAllianceMember)
  if(hasGroupMember == compared.hasGroupMember)
  if(hasMyTaxCollector == compared.hasMyTaxCollector)
  return true;
  
  return false;
}

