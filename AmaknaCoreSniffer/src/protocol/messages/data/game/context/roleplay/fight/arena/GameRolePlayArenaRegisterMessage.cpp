#include "GameRolePlayArenaRegisterMessage.h"

void GameRolePlayArenaRegisterMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaRegisterMessage(output);
}

void GameRolePlayArenaRegisterMessage::serializeAs_GameRolePlayArenaRegisterMessage(Writer *output)
{
  output->writeInt((int)this->battleMode);
}

void GameRolePlayArenaRegisterMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaRegisterMessage(input);
}

void GameRolePlayArenaRegisterMessage::deserializeAs_GameRolePlayArenaRegisterMessage(Reader *input)
{
  this->_battleModeFunc(input);
}

void GameRolePlayArenaRegisterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaRegisterMessage(tree);
}

void GameRolePlayArenaRegisterMessage::deserializeAsyncAs_GameRolePlayArenaRegisterMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaRegisterMessage::_battleModeFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaRegisterMessage::_battleModeFunc(Reader *input)
{
  this->battleMode = input->readInt();
  if(this->battleMode < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaRegisterMessage -"<<"Forbidden value (" << this->battleMode << ") on element of GameRolePlayArenaRegisterMessage.battleMode.";
  }
}

GameRolePlayArenaRegisterMessage::GameRolePlayArenaRegisterMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAREGISTERMESSAGE;
}

