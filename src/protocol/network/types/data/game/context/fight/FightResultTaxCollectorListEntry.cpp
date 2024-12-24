#include "FightResultTaxCollectorListEntry.h"

void FightResultTaxCollectorListEntry::serialize(Writer *output)
{
  this->serializeAs_FightResultTaxCollectorListEntry(output);
}

void FightResultTaxCollectorListEntry::serializeAs_FightResultTaxCollectorListEntry(Writer *output)
{
  FightResultFighterListEntry::serializeAs_FightResultFighterListEntry(output);
  this->allianceInfo->serializeAs_BasicAllianceInformations(output);
}

void FightResultTaxCollectorListEntry::deserialize(Reader *input)
{
  this->deserializeAs_FightResultTaxCollectorListEntry(input);
}

void FightResultTaxCollectorListEntry::deserializeAs_FightResultTaxCollectorListEntry(Reader *input)
{
  FightResultFighterListEntry::deserialize(input);
  this->allianceInfo = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->allianceInfo->deserialize(input);
}

void FightResultTaxCollectorListEntry::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightResultTaxCollectorListEntry(tree);
}

void FightResultTaxCollectorListEntry::deserializeAsyncAs_FightResultTaxCollectorListEntry(FuncTree tree)
{
  FightResultFighterListEntry::deserializeAsync(tree);
  this->_allianceInfotree = tree.addChild(std::bind(&FightResultTaxCollectorListEntry::_allianceInfotreeFunc, this, std::placeholders::_1));
}

void FightResultTaxCollectorListEntry::_allianceInfotreeFunc(Reader *input)
{
  this->allianceInfo = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->allianceInfo->deserializeAsync(this->_allianceInfotree);
}

FightResultTaxCollectorListEntry::FightResultTaxCollectorListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTTAXCOLLECTORLISTENTRY;
}

bool FightResultTaxCollectorListEntry::operator==(const FightResultTaxCollectorListEntry &compared)
{
  if(allianceInfo == compared.allianceInfo)
  if(_allianceInfotree == compared._allianceInfotree)
  return true;
  
  return false;
}

