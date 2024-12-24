#include "GameActionFightStealKamaMessage.h"

void GameActionFightStealKamaMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightStealKamaMessage(output);
}

void GameActionFightStealKamaMessage::serializeAs_GameActionFightStealKamaMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightStealKamaMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->amount < 0 || this->amount > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightStealKamaMessage -"<<"Forbidden value (" << this->amount << ") on element amount.";
  }
  output->writeVarLong((double)this->amount);
}

void GameActionFightStealKamaMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightStealKamaMessage(input);
}

void GameActionFightStealKamaMessage::deserializeAs_GameActionFightStealKamaMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_amountFunc(input);
}

void GameActionFightStealKamaMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightStealKamaMessage(tree);
}

void GameActionFightStealKamaMessage::deserializeAsyncAs_GameActionFightStealKamaMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightStealKamaMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightStealKamaMessage::_amountFunc, this, std::placeholders::_1));
}

void GameActionFightStealKamaMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightStealKamaMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightStealKamaMessage.targetId.";
  }
}

void GameActionFightStealKamaMessage::_amountFunc(Reader *input)
{
  this->amount = input->readVarUhLong();
  if(this->amount < 0 || this->amount > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightStealKamaMessage -"<<"Forbidden value (" << this->amount << ") on element of GameActionFightStealKamaMessage.amount.";
  }
}

GameActionFightStealKamaMessage::GameActionFightStealKamaMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSTEALKAMAMESSAGE;
}

