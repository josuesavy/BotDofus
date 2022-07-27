#include "GameRolePlaySpellAnimMessage.h"

void GameRolePlaySpellAnimMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlaySpellAnimMessage(output);
}

void GameRolePlaySpellAnimMessage::serializeAs_GameRolePlaySpellAnimMessage(Writer *output)
{
  if(this->casterId < 0 || this->casterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->casterId << ") on element casterId.";
  }
  output->writeVarLong((double)this->casterId);
  if(this->targetCellId < 0 || this->targetCellId > 559)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->targetCellId << ") on element targetCellId.";
  }
  output->writeVarShort((int)this->targetCellId);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  if(this->spellLevel < 1 || this->spellLevel > 32767)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->spellLevel << ") on element spellLevel.";
  }
  output->writeShort((short)this->spellLevel);
  if(this->direction < -1 || this->direction > 8)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->direction << ") on element direction.";
  }
  output->writeShort((short)this->direction);
}

void GameRolePlaySpellAnimMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlaySpellAnimMessage(input);
}

void GameRolePlaySpellAnimMessage::deserializeAs_GameRolePlaySpellAnimMessage(Reader *input)
{
  this->_casterIdFunc(input);
  this->_targetCellIdFunc(input);
  this->_spellIdFunc(input);
  this->_spellLevelFunc(input);
  this->_directionFunc(input);
}

void GameRolePlaySpellAnimMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlaySpellAnimMessage(tree);
}

void GameRolePlaySpellAnimMessage::deserializeAsyncAs_GameRolePlaySpellAnimMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlaySpellAnimMessage::_casterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlaySpellAnimMessage::_targetCellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlaySpellAnimMessage::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlaySpellAnimMessage::_spellLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlaySpellAnimMessage::_directionFunc, this, std::placeholders::_1));
}

void GameRolePlaySpellAnimMessage::_casterIdFunc(Reader *input)
{
  this->casterId = input->readVarUhLong();
  if(this->casterId < 0 || this->casterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->casterId << ") on element of GameRolePlaySpellAnimMessage.casterId.";
  }
}

void GameRolePlaySpellAnimMessage::_targetCellIdFunc(Reader *input)
{
  this->targetCellId = input->readVarUhShort();
  if(this->targetCellId < 0 || this->targetCellId > 559)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->targetCellId << ") on element of GameRolePlaySpellAnimMessage.targetCellId.";
  }
}

void GameRolePlaySpellAnimMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameRolePlaySpellAnimMessage.spellId.";
  }
}

void GameRolePlaySpellAnimMessage::_spellLevelFunc(Reader *input)
{
  this->spellLevel = input->readShort();
  if(this->spellLevel < 1 || this->spellLevel > 32767)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->spellLevel << ") on element of GameRolePlaySpellAnimMessage.spellLevel.";
  }
}

void GameRolePlaySpellAnimMessage::_directionFunc(Reader *input)
{
  this->direction = input->readShort();
  if(this->direction < -1 || this->direction > 8)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->direction << ") on element of GameRolePlaySpellAnimMessage.direction.";
  }
}

GameRolePlaySpellAnimMessage::GameRolePlaySpellAnimMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYSPELLANIMMESSAGE;
}

