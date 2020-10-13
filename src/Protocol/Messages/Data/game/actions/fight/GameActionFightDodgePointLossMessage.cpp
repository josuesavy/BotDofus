#include "GameActionFightDodgePointLossMessage.h"

void GameActionFightDodgePointLossMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightDodgePointLossMessage(output);
}

void GameActionFightDodgePointLossMessage::serializeAs_GameActionFightDodgePointLossMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDodgePointLossMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->amount < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDodgePointLossMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
  }
  output->writeVarShort((int)this->amount);
}

void GameActionFightDodgePointLossMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightDodgePointLossMessage(input);
}

void GameActionFightDodgePointLossMessage::deserializeAs_GameActionFightDodgePointLossMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_amountFunc(input);
}

void GameActionFightDodgePointLossMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightDodgePointLossMessage(tree);
}

void GameActionFightDodgePointLossMessage::deserializeAsyncAs_GameActionFightDodgePointLossMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightDodgePointLossMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightDodgePointLossMessage::_amountFunc, this, std::placeholders::_1));
}

void GameActionFightDodgePointLossMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDodgePointLossMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightDodgePointLossMessage.targetId.";
  }
}

void GameActionFightDodgePointLossMessage::_amountFunc(Reader *input)
{
  this->amount = input->readVarUhShort();
  if(this->amount < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDodgePointLossMessage -"<<"Forbidden value (" << this->amount << ") on element of GameActionFightDodgePointLossMessage.amount.";
  }
}

GameActionFightDodgePointLossMessage::GameActionFightDodgePointLossMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE;
}

