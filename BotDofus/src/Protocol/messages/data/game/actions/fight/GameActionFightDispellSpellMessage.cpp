#include "GameActionFightDispellSpellMessage.h"

void GameActionFightDispellSpellMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightDispellSpellMessage(output);
}

void GameActionFightDispellSpellMessage::serializeAs_GameActionFightDispellSpellMessage(Writer *output)
{
  GameActionFightDispellMessage::serializeAs_GameActionFightDispellMessage(output);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDispellSpellMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
}

void GameActionFightDispellSpellMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightDispellSpellMessage(input);
}

void GameActionFightDispellSpellMessage::deserializeAs_GameActionFightDispellSpellMessage(Reader *input)
{
  GameActionFightDispellMessage::deserialize(input);
  this->_spellIdFunc(input);
}

void GameActionFightDispellSpellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightDispellSpellMessage(tree);
}

void GameActionFightDispellSpellMessage::deserializeAsyncAs_GameActionFightDispellSpellMessage(FuncTree tree)
{
  GameActionFightDispellMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightDispellSpellMessage::_spellIdFunc, this, std::placeholders::_1));
}

void GameActionFightDispellSpellMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDispellSpellMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightDispellSpellMessage.spellId.";
  }
}

GameActionFightDispellSpellMessage::GameActionFightDispellSpellMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDISPELLSPELLMESSAGE;
}

