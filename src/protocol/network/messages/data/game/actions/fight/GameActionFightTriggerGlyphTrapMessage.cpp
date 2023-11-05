#include "GameActionFightTriggerGlyphTrapMessage.h"

void GameActionFightTriggerGlyphTrapMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightTriggerGlyphTrapMessage(output);
}

void GameActionFightTriggerGlyphTrapMessage::serializeAs_GameActionFightTriggerGlyphTrapMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  output->writeShort((short)this->markId);
  if(this->markImpactCell < 0)
  {
    qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->markImpactCell << ") on element markImpactCell.";
  }
  output->writeVarShort((int)this->markImpactCell);
  if(this->triggeringCharacterId < -9007199254740992 || this->triggeringCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->triggeringCharacterId << ") on element triggeringCharacterId.";
  }
  output->writeDouble(this->triggeringCharacterId);
  if(this->triggeredSpellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->triggeredSpellId << ") on element triggeredSpellId.";
  }
  output->writeVarShort((int)this->triggeredSpellId);
}

void GameActionFightTriggerGlyphTrapMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightTriggerGlyphTrapMessage(input);
}

void GameActionFightTriggerGlyphTrapMessage::deserializeAs_GameActionFightTriggerGlyphTrapMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_markIdFunc(input);
  this->_markImpactCellFunc(input);
  this->_triggeringCharacterIdFunc(input);
  this->_triggeredSpellIdFunc(input);
}

void GameActionFightTriggerGlyphTrapMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightTriggerGlyphTrapMessage(tree);
}

void GameActionFightTriggerGlyphTrapMessage::deserializeAsyncAs_GameActionFightTriggerGlyphTrapMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightTriggerGlyphTrapMessage::_markIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightTriggerGlyphTrapMessage::_markImpactCellFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightTriggerGlyphTrapMessage::_triggeringCharacterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightTriggerGlyphTrapMessage::_triggeredSpellIdFunc, this, std::placeholders::_1));
}

void GameActionFightTriggerGlyphTrapMessage::_markIdFunc(Reader *input)
{
  this->markId = input->readShort();
}

void GameActionFightTriggerGlyphTrapMessage::_markImpactCellFunc(Reader *input)
{
  this->markImpactCell = input->readVarUhShort();
  if(this->markImpactCell < 0)
  {
    qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->markImpactCell << ") on element of GameActionFightTriggerGlyphTrapMessage.markImpactCell.";
  }
}

void GameActionFightTriggerGlyphTrapMessage::_triggeringCharacterIdFunc(Reader *input)
{
  this->triggeringCharacterId = input->readDouble();
  if(this->triggeringCharacterId < -9007199254740992 || this->triggeringCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->triggeringCharacterId << ") on element of GameActionFightTriggerGlyphTrapMessage.triggeringCharacterId.";
  }
}

void GameActionFightTriggerGlyphTrapMessage::_triggeredSpellIdFunc(Reader *input)
{
  this->triggeredSpellId = input->readVarUhShort();
  if(this->triggeredSpellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->triggeredSpellId << ") on element of GameActionFightTriggerGlyphTrapMessage.triggeredSpellId.";
  }
}

GameActionFightTriggerGlyphTrapMessage::GameActionFightTriggerGlyphTrapMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE;
}

