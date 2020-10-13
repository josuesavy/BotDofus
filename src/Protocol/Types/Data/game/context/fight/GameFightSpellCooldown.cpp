#include "GameFightSpellCooldown.h"

void GameFightSpellCooldown::serialize(Writer *output)
{
  this->serializeAs_GameFightSpellCooldown(output);
}

void GameFightSpellCooldown::serializeAs_GameFightSpellCooldown(Writer *output)
{
  output->writeInt((int)this->spellId);
  if(this->cooldown < 0)
  {
    qDebug()<<"ERREUR - GameFightSpellCooldown -"<<"Forbidden value (" << this->cooldown << ") on element cooldown.";
  }
  output->writeByte(this->cooldown);
}

void GameFightSpellCooldown::deserialize(Reader *input)
{
  this->deserializeAs_GameFightSpellCooldown(input);
}

void GameFightSpellCooldown::deserializeAs_GameFightSpellCooldown(Reader *input)
{
  this->_spellIdFunc(input);
  this->_cooldownFunc(input);
}

void GameFightSpellCooldown::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightSpellCooldown(tree);
}

void GameFightSpellCooldown::deserializeAsyncAs_GameFightSpellCooldown(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightSpellCooldown::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightSpellCooldown::_cooldownFunc, this, std::placeholders::_1));
}

void GameFightSpellCooldown::_spellIdFunc(Reader *input)
{
  this->spellId = input->readInt();
}

void GameFightSpellCooldown::_cooldownFunc(Reader *input)
{
  this->cooldown = input->readByte();
  if(this->cooldown < 0)
  {
    qDebug()<<"ERREUR - GameFightSpellCooldown -"<<"Forbidden value (" << this->cooldown << ") on element of GameFightSpellCooldown.cooldown.";
  }
}

GameFightSpellCooldown::GameFightSpellCooldown()
{
  m_types<<ClassEnum::GAMEFIGHTSPELLCOOLDOWN;
}

bool GameFightSpellCooldown::operator==(const GameFightSpellCooldown &compared)
{
  if(spellId == compared.spellId)
  if(cooldown == compared.cooldown)
  return true;
  
  return false;
}

