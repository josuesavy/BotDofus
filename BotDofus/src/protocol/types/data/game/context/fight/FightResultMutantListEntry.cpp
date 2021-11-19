#include "FightResultMutantListEntry.h"

void FightResultMutantListEntry::serialize(Writer *output)
{
  this->serializeAs_FightResultMutantListEntry(output);
}

void FightResultMutantListEntry::serializeAs_FightResultMutantListEntry(Writer *output)
{
  FightResultFighterListEntry::serializeAs_FightResultFighterListEntry(output);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FightResultMutantListEntry -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
}

void FightResultMutantListEntry::deserialize(Reader *input)
{
  this->deserializeAs_FightResultMutantListEntry(input);
}

void FightResultMutantListEntry::deserializeAs_FightResultMutantListEntry(Reader *input)
{
  FightResultFighterListEntry::deserialize(input);
  this->_levelFunc(input);
}

void FightResultMutantListEntry::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightResultMutantListEntry(tree);
}

void FightResultMutantListEntry::deserializeAsyncAs_FightResultMutantListEntry(FuncTree tree)
{
  FightResultFighterListEntry::deserializeAsync(tree);
  tree.addChild(std::bind(&FightResultMutantListEntry::_levelFunc, this, std::placeholders::_1));
}

void FightResultMutantListEntry::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FightResultMutantListEntry -"<<"Forbidden value (" << this->level << ") on element of FightResultMutantListEntry.level.";
  }
}

FightResultMutantListEntry::FightResultMutantListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTMUTANTLISTENTRY;
}

bool FightResultMutantListEntry::operator==(const FightResultMutantListEntry &compared)
{
  if(level == compared.level)
  return true;
  
  return false;
}

