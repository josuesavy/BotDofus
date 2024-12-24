#include "GameRolePlayArenaRegisterMessage.h"

void GameRolePlayArenaRegisterMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaRegisterMessage(output);
}

void GameRolePlayArenaRegisterMessage::serializeAs_GameRolePlayArenaRegisterMessage(Writer *output)
{
  output->writeInt((int)this->arenaType);
}

void GameRolePlayArenaRegisterMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaRegisterMessage(input);
}

void GameRolePlayArenaRegisterMessage::deserializeAs_GameRolePlayArenaRegisterMessage(Reader *input)
{
  this->_arenaTypeFunc(input);
}

void GameRolePlayArenaRegisterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaRegisterMessage(tree);
}

void GameRolePlayArenaRegisterMessage::deserializeAsyncAs_GameRolePlayArenaRegisterMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaRegisterMessage::_arenaTypeFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaRegisterMessage::_arenaTypeFunc(Reader *input)
{
  this->arenaType = input->readInt();
  if(this->arenaType < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaRegisterMessage -"<<"Forbidden value (" << this->arenaType << ") on element of GameRolePlayArenaRegisterMessage.arenaType.";
  }
}

GameRolePlayArenaRegisterMessage::GameRolePlayArenaRegisterMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAREGISTERMESSAGE;
}

