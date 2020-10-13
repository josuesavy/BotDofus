#include "GameRolePlayShowActorWithEventMessage.h"

void GameRolePlayShowActorWithEventMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayShowActorWithEventMessage(output);
}

void GameRolePlayShowActorWithEventMessage::serializeAs_GameRolePlayShowActorWithEventMessage(Writer *output)
{
  GameRolePlayShowActorMessage::serializeAs_GameRolePlayShowActorMessage(output);
  if(this->actorEventId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayShowActorWithEventMessage -"<<"Forbidden value (" << this->actorEventId << ") on element actorEventId.";
  }
  output->writeByte(this->actorEventId);
}

void GameRolePlayShowActorWithEventMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayShowActorWithEventMessage(input);
}

void GameRolePlayShowActorWithEventMessage::deserializeAs_GameRolePlayShowActorWithEventMessage(Reader *input)
{
  GameRolePlayShowActorMessage::deserialize(input);
  this->_actorEventIdFunc(input);
}

void GameRolePlayShowActorWithEventMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayShowActorWithEventMessage(tree);
}

void GameRolePlayShowActorWithEventMessage::deserializeAsyncAs_GameRolePlayShowActorWithEventMessage(FuncTree tree)
{
  GameRolePlayShowActorMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayShowActorWithEventMessage::_actorEventIdFunc, this, std::placeholders::_1));
}

void GameRolePlayShowActorWithEventMessage::_actorEventIdFunc(Reader *input)
{
  this->actorEventId = input->readByte();
  if(this->actorEventId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayShowActorWithEventMessage -"<<"Forbidden value (" << this->actorEventId << ") on element of GameRolePlayShowActorWithEventMessage.actorEventId.";
  }
}

GameRolePlayShowActorWithEventMessage::GameRolePlayShowActorWithEventMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE;
}

