#include "GameActionFightLifePointsGainMessage.h"

void GameActionFightLifePointsGainMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightLifePointsGainMessage(output);
}

void GameActionFightLifePointsGainMessage::serializeAs_GameActionFightLifePointsGainMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsGainMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->delta < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsGainMessage -"<<"Forbidden value (" << this->delta << ") on element delta.";
  }
  output->writeVarInt((int)this->delta);
}

void GameActionFightLifePointsGainMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightLifePointsGainMessage(input);
}

void GameActionFightLifePointsGainMessage::deserializeAs_GameActionFightLifePointsGainMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_deltaFunc(input);
}

void GameActionFightLifePointsGainMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightLifePointsGainMessage(tree);
}

void GameActionFightLifePointsGainMessage::deserializeAsyncAs_GameActionFightLifePointsGainMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightLifePointsGainMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightLifePointsGainMessage::_deltaFunc, this, std::placeholders::_1));
}

void GameActionFightLifePointsGainMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsGainMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightLifePointsGainMessage.targetId.";
  }
}

void GameActionFightLifePointsGainMessage::_deltaFunc(Reader *input)
{
  this->delta = input->readVarUhInt();
  if(this->delta < 0)
  {
    qDebug()<<"ERREUR - GameActionFightLifePointsGainMessage -"<<"Forbidden value (" << this->delta << ") on element of GameActionFightLifePointsGainMessage.delta.";
  }
}

GameActionFightLifePointsGainMessage::GameActionFightLifePointsGainMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE;
}

