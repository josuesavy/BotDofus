#include "GameFightResumeSlaveInfo.h"

void GameFightResumeSlaveInfo::serialize(Writer *output)
{
  this->serializeAs_GameFightResumeSlaveInfo(output);
}

void GameFightResumeSlaveInfo::serializeAs_GameFightResumeSlaveInfo(Writer *output)
{
  if(this->slaveId < -9007199254740992 || this->slaveId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->slaveId << ") on element slaveId.";
  }
  output->writeDouble(this->slaveId);
  output->writeShort((short)this->spellCooldowns.size());
  for(uint _i2 = 0; _i2 < this->spellCooldowns.size(); _i2++)
  {
    (this->spellCooldowns[_i2]).serializeAs_GameFightSpellCooldown(output);
  }
  if(this->summonCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->summonCount << ") on element summonCount.";
  }
  output->writeByte(this->summonCount);
  if(this->bombCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->bombCount << ") on element bombCount.";
  }
  output->writeByte(this->bombCount);
}

void GameFightResumeSlaveInfo::deserialize(Reader *input)
{
  this->deserializeAs_GameFightResumeSlaveInfo(input);
}

void GameFightResumeSlaveInfo::deserializeAs_GameFightResumeSlaveInfo(Reader *input)
{
  GameFightSpellCooldown _item2 ;
  this->_slaveIdFunc(input);
  uint _spellCooldownsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _spellCooldownsLen; _i2++)
  {
    _item2 = GameFightSpellCooldown();
    _item2.deserialize(input);
    this->spellCooldowns.append(_item2);
  }
  this->_summonCountFunc(input);
  this->_bombCountFunc(input);
}

void GameFightResumeSlaveInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightResumeSlaveInfo(tree);
}

void GameFightResumeSlaveInfo::deserializeAsyncAs_GameFightResumeSlaveInfo(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightResumeSlaveInfo::_slaveIdFunc, this, std::placeholders::_1));
  this->_spellCooldownstree = tree.addChild(std::bind(&GameFightResumeSlaveInfo::_spellCooldownstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightResumeSlaveInfo::_summonCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightResumeSlaveInfo::_bombCountFunc, this, std::placeholders::_1));
}

void GameFightResumeSlaveInfo::_slaveIdFunc(Reader *input)
{
  this->slaveId = input->readDouble();
  if(this->slaveId < -9007199254740992 || this->slaveId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->slaveId << ") on element of GameFightResumeSlaveInfo.slaveId.";
  }
}

void GameFightResumeSlaveInfo::_spellCooldownstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_spellCooldownstree.addChild(std::bind(&GameFightResumeSlaveInfo::_spellCooldownsFunc, this, std::placeholders::_1));
  }
}

void GameFightResumeSlaveInfo::_spellCooldownsFunc(Reader *input)
{
  GameFightSpellCooldown _item = GameFightSpellCooldown();
  _item.deserialize(input);
  this->spellCooldowns.append(_item);
}

void GameFightResumeSlaveInfo::_summonCountFunc(Reader *input)
{
  this->summonCount = input->readByte();
  if(this->summonCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->summonCount << ") on element of GameFightResumeSlaveInfo.summonCount.";
  }
}

void GameFightResumeSlaveInfo::_bombCountFunc(Reader *input)
{
  this->bombCount = input->readByte();
  if(this->bombCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->bombCount << ") on element of GameFightResumeSlaveInfo.bombCount.";
  }
}

GameFightResumeSlaveInfo::GameFightResumeSlaveInfo()
{
  m_types<<ClassEnum::GAMEFIGHTRESUMESLAVEINFO;
}

bool GameFightResumeSlaveInfo::operator==(const GameFightResumeSlaveInfo &compared)
{
  if(slaveId == compared.slaveId)
  if(spellCooldowns == compared.spellCooldowns)
  if(summonCount == compared.summonCount)
  if(bombCount == compared.bombCount)
  if(_spellCooldownstree == compared._spellCooldownstree)
  return true;
  
  return false;
}

