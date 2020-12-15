#include "GameRolePlayMonsterNotAngryAtPlayerMessage.h"

void GameRolePlayMonsterNotAngryAtPlayerMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayMonsterNotAngryAtPlayerMessage(output);
}

void GameRolePlayMonsterNotAngryAtPlayerMessage::serializeAs_GameRolePlayMonsterNotAngryAtPlayerMessage(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterNotAngryAtPlayerMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  if(this->monsterGroupId < -9.007199254740992E15 || this->monsterGroupId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterNotAngryAtPlayerMessage -"<<"Forbidden value (" << this->monsterGroupId << ") on element monsterGroupId.";
  }
  output->writeDouble(this->monsterGroupId);
}

void GameRolePlayMonsterNotAngryAtPlayerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayMonsterNotAngryAtPlayerMessage(input);
}

void GameRolePlayMonsterNotAngryAtPlayerMessage::deserializeAs_GameRolePlayMonsterNotAngryAtPlayerMessage(Reader *input)
{
  this->_playerIdFunc(input);
  this->_monsterGroupIdFunc(input);
}

void GameRolePlayMonsterNotAngryAtPlayerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayMonsterNotAngryAtPlayerMessage(tree);
}

void GameRolePlayMonsterNotAngryAtPlayerMessage::deserializeAsyncAs_GameRolePlayMonsterNotAngryAtPlayerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayMonsterNotAngryAtPlayerMessage::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayMonsterNotAngryAtPlayerMessage::_monsterGroupIdFunc, this, std::placeholders::_1));
}

void GameRolePlayMonsterNotAngryAtPlayerMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterNotAngryAtPlayerMessage -"<<"Forbidden value (" << this->playerId << ") on element of GameRolePlayMonsterNotAngryAtPlayerMessage.playerId.";
  }
}

void GameRolePlayMonsterNotAngryAtPlayerMessage::_monsterGroupIdFunc(Reader *input)
{
  this->monsterGroupId = input->readDouble();
  if(this->monsterGroupId < -9.007199254740992E15 || this->monsterGroupId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayMonsterNotAngryAtPlayerMessage -"<<"Forbidden value (" << this->monsterGroupId << ") on element of GameRolePlayMonsterNotAngryAtPlayerMessage.monsterGroupId.";
  }
}

GameRolePlayMonsterNotAngryAtPlayerMessage::GameRolePlayMonsterNotAngryAtPlayerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYMONSTERNOTANGRYATPLAYERMESSAGE;
}

