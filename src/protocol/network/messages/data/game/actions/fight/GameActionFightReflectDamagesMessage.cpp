#include "GameActionFightReflectDamagesMessage.h"

void GameActionFightReflectDamagesMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightReflectDamagesMessage(output);
}

void GameActionFightReflectDamagesMessage::serializeAs_GameActionFightReflectDamagesMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightReflectDamagesMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
}

void GameActionFightReflectDamagesMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightReflectDamagesMessage(input);
}

void GameActionFightReflectDamagesMessage::deserializeAs_GameActionFightReflectDamagesMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
}

void GameActionFightReflectDamagesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightReflectDamagesMessage(tree);
}

void GameActionFightReflectDamagesMessage::deserializeAsyncAs_GameActionFightReflectDamagesMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightReflectDamagesMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GameActionFightReflectDamagesMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightReflectDamagesMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightReflectDamagesMessage.targetId.";
  }
}

GameActionFightReflectDamagesMessage::GameActionFightReflectDamagesMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE;
}

