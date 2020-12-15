#include "GameActionFightDeathMessage.h"

void GameActionFightDeathMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightDeathMessage(output);
}

void GameActionFightDeathMessage::serializeAs_GameActionFightDeathMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDeathMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
}

void GameActionFightDeathMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightDeathMessage(input);
}

void GameActionFightDeathMessage::deserializeAs_GameActionFightDeathMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
}

void GameActionFightDeathMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightDeathMessage(tree);
}

void GameActionFightDeathMessage::deserializeAsyncAs_GameActionFightDeathMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightDeathMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GameActionFightDeathMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightDeathMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightDeathMessage.targetId.";
  }
}

GameActionFightDeathMessage::GameActionFightDeathMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDEATHMESSAGE;
}

