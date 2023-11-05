#include "GameActionFightReduceDamagesMessage.h"

void GameActionFightReduceDamagesMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightReduceDamagesMessage(output);
}

void GameActionFightReduceDamagesMessage::serializeAs_GameActionFightReduceDamagesMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightReduceDamagesMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->amount < 0)
  {
    qDebug()<<"ERREUR - GameActionFightReduceDamagesMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
  }
  output->writeVarInt((int)this->amount);
}

void GameActionFightReduceDamagesMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightReduceDamagesMessage(input);
}

void GameActionFightReduceDamagesMessage::deserializeAs_GameActionFightReduceDamagesMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_amountFunc(input);
}

void GameActionFightReduceDamagesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightReduceDamagesMessage(tree);
}

void GameActionFightReduceDamagesMessage::deserializeAsyncAs_GameActionFightReduceDamagesMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightReduceDamagesMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightReduceDamagesMessage::_amountFunc, this, std::placeholders::_1));
}

void GameActionFightReduceDamagesMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightReduceDamagesMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightReduceDamagesMessage.targetId.";
  }
}

void GameActionFightReduceDamagesMessage::_amountFunc(Reader *input)
{
  this->amount = input->readVarUhInt();
  if(this->amount < 0)
  {
    qDebug()<<"ERREUR - GameActionFightReduceDamagesMessage -"<<"Forbidden value (" << this->amount << ") on element of GameActionFightReduceDamagesMessage.amount.";
  }
}

GameActionFightReduceDamagesMessage::GameActionFightReduceDamagesMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE;
}

