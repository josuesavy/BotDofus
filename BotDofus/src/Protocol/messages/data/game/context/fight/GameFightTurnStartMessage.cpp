#include "GameFightTurnStartMessage.h"

void GameFightTurnStartMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightTurnStartMessage(output);
}

void GameFightTurnStartMessage::serializeAs_GameFightTurnStartMessage(Writer *output)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnStartMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
  if(this->waitTime < 0)
  {
    qDebug()<<"ERREUR - GameFightTurnStartMessage -"<<"Forbidden value (" << this->waitTime << ") on element waitTime.";
  }
  output->writeVarInt((int)this->waitTime);
}

void GameFightTurnStartMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightTurnStartMessage(input);
}

void GameFightTurnStartMessage::deserializeAs_GameFightTurnStartMessage(Reader *input)
{
  this->_idFunc(input);
  this->_waitTimeFunc(input);
}

void GameFightTurnStartMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightTurnStartMessage(tree);
}

void GameFightTurnStartMessage::deserializeAsyncAs_GameFightTurnStartMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightTurnStartMessage::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightTurnStartMessage::_waitTimeFunc, this, std::placeholders::_1));
}

void GameFightTurnStartMessage::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnStartMessage -"<<"Forbidden value (" << this->id << ") on element of GameFightTurnStartMessage.id.";
  }
}

void GameFightTurnStartMessage::_waitTimeFunc(Reader *input)
{
  this->waitTime = input->readVarUhInt();
  if(this->waitTime < 0)
  {
    qDebug()<<"ERREUR - GameFightTurnStartMessage -"<<"Forbidden value (" << this->waitTime << ") on element of GameFightTurnStartMessage.waitTime.";
  }
}

GameFightTurnStartMessage::GameFightTurnStartMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNSTARTMESSAGE;
}

