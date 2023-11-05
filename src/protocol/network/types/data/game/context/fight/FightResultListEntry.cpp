#include "FightResultListEntry.h"

void FightResultListEntry::serialize(Writer *output)
{
  this->serializeAs_FightResultListEntry(output);
}

void FightResultListEntry::serializeAs_FightResultListEntry(Writer *output)
{
  output->writeVarShort((int)this->outcome);
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - FightResultListEntry -"<<"Forbidden value (" << this->wave << ") on element wave.";
  }
  output->writeByte(this->wave);
  this->rewards.serializeAs_FightLoot(output);
}

void FightResultListEntry::deserialize(Reader *input)
{
  this->deserializeAs_FightResultListEntry(input);
}

void FightResultListEntry::deserializeAs_FightResultListEntry(Reader *input)
{
  this->_outcomeFunc(input);
  this->_waveFunc(input);
  this->rewards = new com.ankamagames.dofus.network.types.game.context.fight.FightLoot();
  this->rewards.deserialize(input);
}

void FightResultListEntry::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightResultListEntry(tree);
}

void FightResultListEntry::deserializeAsyncAs_FightResultListEntry(FuncTree tree)
{
  tree.addChild(std::bind(&FightResultListEntry::_outcomeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultListEntry::_waveFunc, this, std::placeholders::_1));
  this->_rewardstree = tree.addChild(std::bind(&FightResultListEntry::_rewardstreeFunc, this, std::placeholders::_1));
}

void FightResultListEntry::_outcomeFunc(Reader *input)
{
  this->outcome = input->readVarUhShort();
  if(this->outcome < 0)
  {
    qDebug()<<"ERREUR - FightResultListEntry -"<<"Forbidden value (" << this->outcome << ") on element of FightResultListEntry.outcome.";
  }
}

void FightResultListEntry::_waveFunc(Reader *input)
{
  this->wave = input->readByte();
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - FightResultListEntry -"<<"Forbidden value (" << this->wave << ") on element of FightResultListEntry.wave.";
  }
}

void FightResultListEntry::_rewardstreeFunc(Reader *input)
{
  this->rewards = new com.ankamagames.dofus.network.types.game.context.fight.FightLoot();
  this->rewards.deserializeAsync(this->_rewardstree);
}

FightResultListEntry::FightResultListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTLISTENTRY;
}

bool FightResultListEntry::operator==(const FightResultListEntry &compared)
{
  if(outcome == compared.outcome)
  if(wave == compared.wave)
  if(rewards == compared.rewards)
  if(_rewardstree == compared._rewardstree)
  return true;
  
  return false;
}

