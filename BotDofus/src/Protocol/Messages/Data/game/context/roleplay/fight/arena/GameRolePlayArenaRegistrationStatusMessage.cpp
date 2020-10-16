#include "GameRolePlayArenaRegistrationStatusMessage.h"

void GameRolePlayArenaRegistrationStatusMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaRegistrationStatusMessage(output);
}

void GameRolePlayArenaRegistrationStatusMessage::serializeAs_GameRolePlayArenaRegistrationStatusMessage(Writer *output)
{
  output->writeBool(this->registered);
  output->writeByte(this->step);
  output->writeInt((int)this->battleMode);
}

void GameRolePlayArenaRegistrationStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaRegistrationStatusMessage(input);
}

void GameRolePlayArenaRegistrationStatusMessage::deserializeAs_GameRolePlayArenaRegistrationStatusMessage(Reader *input)
{
  this->_registeredFunc(input);
  this->_stepFunc(input);
  this->_battleModeFunc(input);
}

void GameRolePlayArenaRegistrationStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaRegistrationStatusMessage(tree);
}

void GameRolePlayArenaRegistrationStatusMessage::deserializeAsyncAs_GameRolePlayArenaRegistrationStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaRegistrationStatusMessage::_registeredFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaRegistrationStatusMessage::_stepFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaRegistrationStatusMessage::_battleModeFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaRegistrationStatusMessage::_registeredFunc(Reader *input)
{
  this->registered = input->readBool();
}

void GameRolePlayArenaRegistrationStatusMessage::_stepFunc(Reader *input)
{
  this->step = input->readByte();
  if(this->step < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaRegistrationStatusMessage -"<<"Forbidden value (" << this->step << ") on element of GameRolePlayArenaRegistrationStatusMessage.step.";
  }
}

void GameRolePlayArenaRegistrationStatusMessage::_battleModeFunc(Reader *input)
{
  this->battleMode = input->readInt();
  if(this->battleMode < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaRegistrationStatusMessage -"<<"Forbidden value (" << this->battleMode << ") on element of GameRolePlayArenaRegistrationStatusMessage.battleMode.";
  }
}

GameRolePlayArenaRegistrationStatusMessage::GameRolePlayArenaRegistrationStatusMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE;
}

