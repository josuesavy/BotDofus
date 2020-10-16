#include "GameActionFightSpellCooldownVariationMessage.h"

void GameActionFightSpellCooldownVariationMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightSpellCooldownVariationMessage(output);
}

void GameActionFightSpellCooldownVariationMessage::serializeAs_GameActionFightSpellCooldownVariationMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCooldownVariationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCooldownVariationMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  output->writeVarShort((int)this->value);
}

void GameActionFightSpellCooldownVariationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightSpellCooldownVariationMessage(input);
}

void GameActionFightSpellCooldownVariationMessage::deserializeAs_GameActionFightSpellCooldownVariationMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_spellIdFunc(input);
  this->_valueFunc(input);
}

void GameActionFightSpellCooldownVariationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightSpellCooldownVariationMessage(tree);
}

void GameActionFightSpellCooldownVariationMessage::deserializeAsyncAs_GameActionFightSpellCooldownVariationMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightSpellCooldownVariationMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightSpellCooldownVariationMessage::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightSpellCooldownVariationMessage::_valueFunc, this, std::placeholders::_1));
}

void GameActionFightSpellCooldownVariationMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCooldownVariationMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightSpellCooldownVariationMessage.targetId.";
  }
}

void GameActionFightSpellCooldownVariationMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCooldownVariationMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightSpellCooldownVariationMessage.spellId.";
  }
}

void GameActionFightSpellCooldownVariationMessage::_valueFunc(Reader *input)
{
  this->value = input->readVarShort();
}

GameActionFightSpellCooldownVariationMessage::GameActionFightSpellCooldownVariationMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE;
}

