#include "GameRolePlayAttackMonsterRequestMessage.h"

void GameRolePlayAttackMonsterRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayAttackMonsterRequestMessage(output);
}

void GameRolePlayAttackMonsterRequestMessage::serializeAs_GameRolePlayAttackMonsterRequestMessage(Writer *output)
{
  if(this->monsterGroupId < -9007199254740992 || this->monsterGroupId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayAttackMonsterRequestMessage -"<<"Forbidden value (" << this->monsterGroupId << ") on element monsterGroupId.";
  }
  output->writeDouble(this->monsterGroupId);
}

void GameRolePlayAttackMonsterRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayAttackMonsterRequestMessage(input);
}

void GameRolePlayAttackMonsterRequestMessage::deserializeAs_GameRolePlayAttackMonsterRequestMessage(Reader *input)
{
  this->_monsterGroupIdFunc(input);
}

void GameRolePlayAttackMonsterRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayAttackMonsterRequestMessage(tree);
}

void GameRolePlayAttackMonsterRequestMessage::deserializeAsyncAs_GameRolePlayAttackMonsterRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayAttackMonsterRequestMessage::_monsterGroupIdFunc, this, std::placeholders::_1));
}

void GameRolePlayAttackMonsterRequestMessage::_monsterGroupIdFunc(Reader *input)
{
  this->monsterGroupId = input->readDouble();
  if(this->monsterGroupId < -9007199254740992 || this->monsterGroupId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayAttackMonsterRequestMessage -"<<"Forbidden value (" << this->monsterGroupId << ") on element of GameRolePlayAttackMonsterRequestMessage.monsterGroupId.";
  }
}

GameRolePlayAttackMonsterRequestMessage::GameRolePlayAttackMonsterRequestMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE;
}

