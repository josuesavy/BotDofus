#include "GameActionFightCloseCombatMessage.h"

void GameActionFightCloseCombatMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightCloseCombatMessage(output);
}

void GameActionFightCloseCombatMessage::serializeAs_GameActionFightCloseCombatMessage(Writer *output)
{
  AbstractGameActionFightTargetedAbilityMessage::serializeAs_AbstractGameActionFightTargetedAbilityMessage(output);
  if(this->weaponGenericId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCloseCombatMessage -"<<"Forbidden value (" << this->weaponGenericId << ") on element weaponGenericId.";
  }
  output->writeVarShort((int)this->weaponGenericId);
}

void GameActionFightCloseCombatMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightCloseCombatMessage(input);
}

void GameActionFightCloseCombatMessage::deserializeAs_GameActionFightCloseCombatMessage(Reader *input)
{
  AbstractGameActionFightTargetedAbilityMessage::deserialize(input);
  this->_weaponGenericIdFunc(input);
}

void GameActionFightCloseCombatMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightCloseCombatMessage(tree);
}

void GameActionFightCloseCombatMessage::deserializeAsyncAs_GameActionFightCloseCombatMessage(FuncTree tree)
{
  AbstractGameActionFightTargetedAbilityMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightCloseCombatMessage::_weaponGenericIdFunc, this, std::placeholders::_1));
}

void GameActionFightCloseCombatMessage::_weaponGenericIdFunc(Reader *input)
{
  this->weaponGenericId = input->readVarUhShort();
  if(this->weaponGenericId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCloseCombatMessage -"<<"Forbidden value (" << this->weaponGenericId << ") on element of GameActionFightCloseCombatMessage.weaponGenericId.";
  }
}

GameActionFightCloseCombatMessage::GameActionFightCloseCombatMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCLOSECOMBATMESSAGE;
}

