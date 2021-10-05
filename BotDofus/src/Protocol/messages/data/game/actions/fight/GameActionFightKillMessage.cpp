#include "GameActionFightKillMessage.h"

void GameActionFightKillMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightKillMessage(output);
}

void GameActionFightKillMessage::serializeAs_GameActionFightKillMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightKillMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
}

void GameActionFightKillMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightKillMessage(input);
}

void GameActionFightKillMessage::deserializeAs_GameActionFightKillMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
}

void GameActionFightKillMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightKillMessage(tree);
}

void GameActionFightKillMessage::deserializeAsyncAs_GameActionFightKillMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightKillMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GameActionFightKillMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightKillMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightKillMessage.targetId.";
  }
}

GameActionFightKillMessage::GameActionFightKillMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTKILLMESSAGE;
}

