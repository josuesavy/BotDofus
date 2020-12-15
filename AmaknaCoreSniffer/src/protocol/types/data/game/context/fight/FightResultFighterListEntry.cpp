#include "FightResultFighterListEntry.h"

void FightResultFighterListEntry::serialize(Writer *output)
{
  this->serializeAs_FightResultFighterListEntry(output);
}

void FightResultFighterListEntry::serializeAs_FightResultFighterListEntry(Writer *output)
{
  FightResultListEntry::serializeAs_FightResultListEntry(output);
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightResultFighterListEntry -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
  output->writeBool(this->alive);
}

void FightResultFighterListEntry::deserialize(Reader *input)
{
  this->deserializeAs_FightResultFighterListEntry(input);
}

void FightResultFighterListEntry::deserializeAs_FightResultFighterListEntry(Reader *input)
{
  FightResultListEntry::deserialize(input);
  this->_idFunc(input);
  this->_aliveFunc(input);
}

void FightResultFighterListEntry::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightResultFighterListEntry(tree);
}

void FightResultFighterListEntry::deserializeAsyncAs_FightResultFighterListEntry(FuncTree tree)
{
  FightResultListEntry::deserializeAsync(tree);
  tree.addChild(std::bind(&FightResultFighterListEntry::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultFighterListEntry::_aliveFunc, this, std::placeholders::_1));
}

void FightResultFighterListEntry::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightResultFighterListEntry -"<<"Forbidden value (" << this->id << ") on element of FightResultFighterListEntry.id.";
  }
}

void FightResultFighterListEntry::_aliveFunc(Reader *input)
{
  this->alive = input->readBool();
}

FightResultFighterListEntry::FightResultFighterListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTFIGHTERLISTENTRY;
}

bool FightResultFighterListEntry::operator==(const FightResultFighterListEntry &compared)
{
  if(id == compared.id)
  if(alive == compared.alive)
  return true;
  
  return false;
}

