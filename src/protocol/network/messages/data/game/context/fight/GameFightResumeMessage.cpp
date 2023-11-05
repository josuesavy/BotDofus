#include "GameFightResumeMessage.h"

void GameFightResumeMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightResumeMessage(output);
}

void GameFightResumeMessage::serializeAs_GameFightResumeMessage(Writer *output)
{
  GameFightSpectateMessage::serializeAs_GameFightSpectateMessage(output);
  output->writeShort((short)this->spellCooldowns.size());
  for(uint _i1 = 0; _i1 < this->spellCooldowns.size(); _i1++)
  {
    (this->spellCooldowns[_i1]).serializeAs_GameFightSpellCooldown(output);
  }
  if(this->summonCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeMessage -"<<"Forbidden value (" << this->summonCount << ") on element summonCount.";
  }
  output->writeByte(this->summonCount);
  if(this->bombCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeMessage -"<<"Forbidden value (" << this->bombCount << ") on element bombCount.";
  }
  output->writeByte(this->bombCount);
}

void GameFightResumeMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightResumeMessage(input);
}

void GameFightResumeMessage::deserializeAs_GameFightResumeMessage(Reader *input)
{
  GameFightSpellCooldown _item1 ;
  GameFightSpectateMessage::deserialize(input);
  uint _spellCooldownsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _spellCooldownsLen; _i1++)
  {
    _item1 = GameFightSpellCooldown();
    _item1.deserialize(input);
    this->spellCooldowns.append(_item1);
  }
  this->_summonCountFunc(input);
  this->_bombCountFunc(input);
}

void GameFightResumeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightResumeMessage(tree);
}

void GameFightResumeMessage::deserializeAsyncAs_GameFightResumeMessage(FuncTree tree)
{
  GameFightSpectateMessage::deserializeAsync(tree);
  this->_spellCooldownstree = tree.addChild(std::bind(&GameFightResumeMessage::_spellCooldownstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightResumeMessage::_summonCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightResumeMessage::_bombCountFunc, this, std::placeholders::_1));
}

void GameFightResumeMessage::_spellCooldownstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_spellCooldownstree.addChild(std::bind(&GameFightResumeMessage::_spellCooldownsFunc, this, std::placeholders::_1));
  }
}

void GameFightResumeMessage::_spellCooldownsFunc(Reader *input)
{
  GameFightSpellCooldown _item = GameFightSpellCooldown();
  _item.deserialize(input);
  this->spellCooldowns.append(_item);
}

void GameFightResumeMessage::_summonCountFunc(Reader *input)
{
  this->summonCount = input->readByte();
  if(this->summonCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeMessage -"<<"Forbidden value (" << this->summonCount << ") on element of GameFightResumeMessage.summonCount.";
  }
}

void GameFightResumeMessage::_bombCountFunc(Reader *input)
{
  this->bombCount = input->readByte();
  if(this->bombCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeMessage -"<<"Forbidden value (" << this->bombCount << ") on element of GameFightResumeMessage.bombCount.";
  }
}

GameFightResumeMessage::GameFightResumeMessage()
{
  m_type = MessageEnum::GAMEFIGHTRESUMEMESSAGE;
}

