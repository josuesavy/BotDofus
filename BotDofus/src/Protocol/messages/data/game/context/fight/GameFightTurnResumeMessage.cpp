#include "GameFightTurnResumeMessage.h"

void GameFightTurnResumeMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightTurnResumeMessage(output);
}

void GameFightTurnResumeMessage::serializeAs_GameFightTurnResumeMessage(Writer *output)
{
  GameFightTurnStartMessage::serializeAs_GameFightTurnStartMessage(output);
  if(this->remainingTime < 0)
  {
    qDebug()<<"ERREUR - GameFightTurnResumeMessage -"<<"Forbidden value (" << this->remainingTime << ") on element remainingTime.";
  }
  output->writeVarInt((int)this->remainingTime);
}

void GameFightTurnResumeMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightTurnResumeMessage(input);
}

void GameFightTurnResumeMessage::deserializeAs_GameFightTurnResumeMessage(Reader *input)
{
  GameFightTurnStartMessage::deserialize(input);
  this->_remainingTimeFunc(input);
}

void GameFightTurnResumeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightTurnResumeMessage(tree);
}

void GameFightTurnResumeMessage::deserializeAsyncAs_GameFightTurnResumeMessage(FuncTree tree)
{
  GameFightTurnStartMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightTurnResumeMessage::_remainingTimeFunc, this, std::placeholders::_1));
}

void GameFightTurnResumeMessage::_remainingTimeFunc(Reader *input)
{
  this->remainingTime = input->readVarUhInt();
  if(this->remainingTime < 0)
  {
    qDebug()<<"ERREUR - GameFightTurnResumeMessage -"<<"Forbidden value (" << this->remainingTime << ") on element of GameFightTurnResumeMessage.remainingTime.";
  }
}

GameFightTurnResumeMessage::GameFightTurnResumeMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNRESUMEMESSAGE;
}

