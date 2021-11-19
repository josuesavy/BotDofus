#include "GameActionFightNoSpellCastMessage.h"

void GameActionFightNoSpellCastMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightNoSpellCastMessage(output);
}

void GameActionFightNoSpellCastMessage::serializeAs_GameActionFightNoSpellCastMessage(Writer *output)
{
  if(this->spellLevelId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightNoSpellCastMessage -"<<"Forbidden value (" << this->spellLevelId << ") on element spellLevelId.";
  }
  output->writeVarInt((int)this->spellLevelId);
}

void GameActionFightNoSpellCastMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightNoSpellCastMessage(input);
}

void GameActionFightNoSpellCastMessage::deserializeAs_GameActionFightNoSpellCastMessage(Reader *input)
{
  this->_spellLevelIdFunc(input);
}

void GameActionFightNoSpellCastMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightNoSpellCastMessage(tree);
}

void GameActionFightNoSpellCastMessage::deserializeAsyncAs_GameActionFightNoSpellCastMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameActionFightNoSpellCastMessage::_spellLevelIdFunc, this, std::placeholders::_1));
}

void GameActionFightNoSpellCastMessage::_spellLevelIdFunc(Reader *input)
{
  this->spellLevelId = input->readVarUhInt();
  if(this->spellLevelId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightNoSpellCastMessage -"<<"Forbidden value (" << this->spellLevelId << ") on element of GameActionFightNoSpellCastMessage.spellLevelId.";
  }
}

GameActionFightNoSpellCastMessage::GameActionFightNoSpellCastMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTNOSPELLCASTMESSAGE;
}

