#include "GameRolePlayAggressionMessage.h"

void GameRolePlayAggressionMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayAggressionMessage(output);
}

void GameRolePlayAggressionMessage::serializeAs_GameRolePlayAggressionMessage(Writer *output)
{
  if(this->attackerId < 0 || this->attackerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayAggressionMessage -"<<"Forbidden value (" << this->attackerId << ") on element attackerId.";
  }
  output->writeVarLong((double)this->attackerId);
  if(this->defenderId < 0 || this->defenderId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayAggressionMessage -"<<"Forbidden value (" << this->defenderId << ") on element defenderId.";
  }
  output->writeVarLong((double)this->defenderId);
}

void GameRolePlayAggressionMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayAggressionMessage(input);
}

void GameRolePlayAggressionMessage::deserializeAs_GameRolePlayAggressionMessage(Reader *input)
{
  this->_attackerIdFunc(input);
  this->_defenderIdFunc(input);
}

void GameRolePlayAggressionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayAggressionMessage(tree);
}

void GameRolePlayAggressionMessage::deserializeAsyncAs_GameRolePlayAggressionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayAggressionMessage::_attackerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayAggressionMessage::_defenderIdFunc, this, std::placeholders::_1));
}

void GameRolePlayAggressionMessage::_attackerIdFunc(Reader *input)
{
  this->attackerId = input->readVarUhLong();
  if(this->attackerId < 0 || this->attackerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayAggressionMessage -"<<"Forbidden value (" << this->attackerId << ") on element of GameRolePlayAggressionMessage.attackerId.";
  }
}

void GameRolePlayAggressionMessage::_defenderIdFunc(Reader *input)
{
  this->defenderId = input->readVarUhLong();
  if(this->defenderId < 0 || this->defenderId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayAggressionMessage -"<<"Forbidden value (" << this->defenderId << ") on element of GameRolePlayAggressionMessage.defenderId.";
  }
}

GameRolePlayAggressionMessage::GameRolePlayAggressionMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYAGGRESSIONMESSAGE;
}

