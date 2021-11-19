#include "GameRolePlayArenaRegistrationWarningMessage.h"

void GameRolePlayArenaRegistrationWarningMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaRegistrationWarningMessage(output);
}

void GameRolePlayArenaRegistrationWarningMessage::serializeAs_GameRolePlayArenaRegistrationWarningMessage(Writer *output)
{
  output->writeInt((int)this->battleMode);
}

void GameRolePlayArenaRegistrationWarningMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaRegistrationWarningMessage(input);
}

void GameRolePlayArenaRegistrationWarningMessage::deserializeAs_GameRolePlayArenaRegistrationWarningMessage(Reader *input)
{
  this->_battleModeFunc(input);
}

void GameRolePlayArenaRegistrationWarningMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaRegistrationWarningMessage(tree);
}

void GameRolePlayArenaRegistrationWarningMessage::deserializeAsyncAs_GameRolePlayArenaRegistrationWarningMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaRegistrationWarningMessage::_battleModeFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaRegistrationWarningMessage::_battleModeFunc(Reader *input)
{
  this->battleMode = input->readInt();
  if(this->battleMode < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaRegistrationWarningMessage -"<<"Forbidden value (" << this->battleMode << ") on element of GameRolePlayArenaRegistrationWarningMessage.battleMode.";
  }
}

GameRolePlayArenaRegistrationWarningMessage::GameRolePlayArenaRegistrationWarningMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAREGISTRATIONWARNINGMESSAGE;
}

