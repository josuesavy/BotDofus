#include "GameActionFightSpellImmunityMessage.h"

void GameActionFightSpellImmunityMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightSpellImmunityMessage(output);
}

void GameActionFightSpellImmunityMessage::serializeAs_GameActionFightSpellImmunityMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightSpellImmunityMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightSpellImmunityMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
}

void GameActionFightSpellImmunityMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightSpellImmunityMessage(input);
}

void GameActionFightSpellImmunityMessage::deserializeAs_GameActionFightSpellImmunityMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_spellIdFunc(input);
}

void GameActionFightSpellImmunityMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightSpellImmunityMessage(tree);
}

void GameActionFightSpellImmunityMessage::deserializeAsyncAs_GameActionFightSpellImmunityMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightSpellImmunityMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightSpellImmunityMessage::_spellIdFunc, this, std::placeholders::_1));
}

void GameActionFightSpellImmunityMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightSpellImmunityMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightSpellImmunityMessage.targetId.";
  }
}

void GameActionFightSpellImmunityMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightSpellImmunityMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightSpellImmunityMessage.spellId.";
  }
}

GameActionFightSpellImmunityMessage::GameActionFightSpellImmunityMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE;
}

