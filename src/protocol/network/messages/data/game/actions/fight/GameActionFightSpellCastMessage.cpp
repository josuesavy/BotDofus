#include "GameActionFightSpellCastMessage.h"

void GameActionFightSpellCastMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightSpellCastMessage(output);
}

void GameActionFightSpellCastMessage::serializeAs_GameActionFightSpellCastMessage(Writer *output)
{
  AbstractGameActionFightTargetedAbilityMessage::serializeAs_AbstractGameActionFightTargetedAbilityMessage(output);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCastMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  if(this->spellLevel < 1 || this->spellLevel > 32767)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCastMessage -"<<"Forbidden value (" << this->spellLevel << ") on element spellLevel.";
  }
  output->writeShort((short)this->spellLevel);
  output->writeShort((short)this->portalsIds.size());
  for(uint _i3 = 0; _i3 < this->portalsIds.size(); _i3++)
  {
    output->writeShort((short)this->portalsIds[_i3]);
  }
}

void GameActionFightSpellCastMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightSpellCastMessage(input);
}

void GameActionFightSpellCastMessage::deserializeAs_GameActionFightSpellCastMessage(Reader *input)
{
  int _val3 = 0;
  AbstractGameActionFightTargetedAbilityMessage::deserialize(input);
  this->_spellIdFunc(input);
  this->_spellLevelFunc(input);
  uint _portalsIdsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _portalsIdsLen; _i3++)
  {
    _val3 = int(input->readShort());
    this->portalsIds.append(_val3);
  }
}

void GameActionFightSpellCastMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightSpellCastMessage(tree);
}

void GameActionFightSpellCastMessage::deserializeAsyncAs_GameActionFightSpellCastMessage(FuncTree tree)
{
  AbstractGameActionFightTargetedAbilityMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightSpellCastMessage::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightSpellCastMessage::_spellLevelFunc, this, std::placeholders::_1));
  this->_portalsIdstree = tree.addChild(std::bind(&GameActionFightSpellCastMessage::_portalsIdstreeFunc, this, std::placeholders::_1));
}

void GameActionFightSpellCastMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCastMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightSpellCastMessage.spellId.";
  }
}

void GameActionFightSpellCastMessage::_spellLevelFunc(Reader *input)
{
  this->spellLevel = input->readShort();
  if(this->spellLevel < 1 || this->spellLevel > 32767)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCastMessage -"<<"Forbidden value (" << this->spellLevel << ") on element of GameActionFightSpellCastMessage.spellLevel.";
  }
}

void GameActionFightSpellCastMessage::_portalsIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_portalsIdstree.addChild(std::bind(&GameActionFightSpellCastMessage::_portalsIdsFunc, this, std::placeholders::_1));
  }
}

void GameActionFightSpellCastMessage::_portalsIdsFunc(Reader *input)
{
  int _val = int(input->readShort());
  this->portalsIds.append(_val);
}

GameActionFightSpellCastMessage::GameActionFightSpellCastMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSPELLCASTMESSAGE;
}

