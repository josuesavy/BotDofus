#include "GameActionFightChangeLookMessage.h"

void GameActionFightChangeLookMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightChangeLookMessage(output);
}

void GameActionFightChangeLookMessage::serializeAs_GameActionFightChangeLookMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightChangeLookMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  this->entityLook->serializeAs_EntityLook(output);
}

void GameActionFightChangeLookMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightChangeLookMessage(input);
}

void GameActionFightChangeLookMessage::deserializeAs_GameActionFightChangeLookMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->entityLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->entityLook->deserialize(input);
}

void GameActionFightChangeLookMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightChangeLookMessage(tree);
}

void GameActionFightChangeLookMessage::deserializeAsyncAs_GameActionFightChangeLookMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightChangeLookMessage::_targetIdFunc, this, std::placeholders::_1));
  this->_entityLooktree = tree.addChild(std::bind(&GameActionFightChangeLookMessage::_entityLooktreeFunc, this, std::placeholders::_1));
}

void GameActionFightChangeLookMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightChangeLookMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightChangeLookMessage.targetId.";
  }
}

void GameActionFightChangeLookMessage::_entityLooktreeFunc(Reader *input)
{
  this->entityLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->entityLook->deserializeAsync(this->_entityLooktree);
}

GameActionFightChangeLookMessage::GameActionFightChangeLookMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCHANGELOOKMESSAGE;
}

