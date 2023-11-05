#include "GameRolePlayMonsterAngryAtPlayerMessage.h"

void GameRolePlayMonsterAngryAtPlayerMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayMonsterAngryAtPlayerMessage(output);
}

void GameRolePlayMonsterAngryAtPlayerMessage::serializeAs_GameRolePlayMonsterAngryAtPlayerMessage(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterAngryAtPlayerMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  if(this->monsterGroupId < -9007199254740992 || this->monsterGroupId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterAngryAtPlayerMessage -"<<"Forbidden value (" << this->monsterGroupId << ") on element monsterGroupId.";
  }
  output->writeDouble(this->monsterGroupId);
  if(this->angryStartTime < 0 || this->angryStartTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterAngryAtPlayerMessage -"<<"Forbidden value (" << this->angryStartTime << ") on element angryStartTime.";
  }
  output->writeDouble(this->angryStartTime);
  if(this->attackTime < 0 || this->attackTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterAngryAtPlayerMessage -"<<"Forbidden value (" << this->attackTime << ") on element attackTime.";
  }
  output->writeDouble(this->attackTime);
}

void GameRolePlayMonsterAngryAtPlayerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayMonsterAngryAtPlayerMessage(input);
}

void GameRolePlayMonsterAngryAtPlayerMessage::deserializeAs_GameRolePlayMonsterAngryAtPlayerMessage(Reader *input)
{
  this->_playerIdFunc(input);
  this->_monsterGroupIdFunc(input);
  this->_angryStartTimeFunc(input);
  this->_attackTimeFunc(input);
}

void GameRolePlayMonsterAngryAtPlayerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayMonsterAngryAtPlayerMessage(tree);
}

void GameRolePlayMonsterAngryAtPlayerMessage::deserializeAsyncAs_GameRolePlayMonsterAngryAtPlayerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayMonsterAngryAtPlayerMessage::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayMonsterAngryAtPlayerMessage::_monsterGroupIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayMonsterAngryAtPlayerMessage::_angryStartTimeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayMonsterAngryAtPlayerMessage::_attackTimeFunc, this, std::placeholders::_1));
}

void GameRolePlayMonsterAngryAtPlayerMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterAngryAtPlayerMessage -"<<"Forbidden value (" << this->playerId << ") on element of GameRolePlayMonsterAngryAtPlayerMessage.playerId.";
  }
}

void GameRolePlayMonsterAngryAtPlayerMessage::_monsterGroupIdFunc(Reader *input)
{
  this->monsterGroupId = input->readDouble();
  if(this->monsterGroupId < -9007199254740992 || this->monsterGroupId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterAngryAtPlayerMessage -"<<"Forbidden value (" << this->monsterGroupId << ") on element of GameRolePlayMonsterAngryAtPlayerMessage.monsterGroupId.";
  }
}

void GameRolePlayMonsterAngryAtPlayerMessage::_angryStartTimeFunc(Reader *input)
{
  this->angryStartTime = input->readDouble();
  if(this->angryStartTime < 0 || this->angryStartTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterAngryAtPlayerMessage -"<<"Forbidden value (" << this->angryStartTime << ") on element of GameRolePlayMonsterAngryAtPlayerMessage.angryStartTime.";
  }
}

void GameRolePlayMonsterAngryAtPlayerMessage::_attackTimeFunc(Reader *input)
{
  this->attackTime = input->readDouble();
  if(this->attackTime < 0 || this->attackTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterAngryAtPlayerMessage -"<<"Forbidden value (" << this->attackTime << ") on element of GameRolePlayMonsterAngryAtPlayerMessage.attackTime.";
  }
}

GameRolePlayMonsterAngryAtPlayerMessage::GameRolePlayMonsterAngryAtPlayerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYMONSTERANGRYATPLAYERMESSAGE;
}

