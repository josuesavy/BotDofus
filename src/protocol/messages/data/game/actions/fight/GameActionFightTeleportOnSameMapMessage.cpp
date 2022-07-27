#include "GameActionFightTeleportOnSameMapMessage.h"

void GameActionFightTeleportOnSameMapMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightTeleportOnSameMapMessage(output);
}

void GameActionFightTeleportOnSameMapMessage::serializeAs_GameActionFightTeleportOnSameMapMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightTeleportOnSameMapMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightTeleportOnSameMapMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeShort((short)this->cellId);
}

void GameActionFightTeleportOnSameMapMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightTeleportOnSameMapMessage(input);
}

void GameActionFightTeleportOnSameMapMessage::deserializeAs_GameActionFightTeleportOnSameMapMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_cellIdFunc(input);
}

void GameActionFightTeleportOnSameMapMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightTeleportOnSameMapMessage(tree);
}

void GameActionFightTeleportOnSameMapMessage::deserializeAsyncAs_GameActionFightTeleportOnSameMapMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightTeleportOnSameMapMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightTeleportOnSameMapMessage::_cellIdFunc, this, std::placeholders::_1));
}

void GameActionFightTeleportOnSameMapMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightTeleportOnSameMapMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightTeleportOnSameMapMessage.targetId.";
  }
}

void GameActionFightTeleportOnSameMapMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readShort();
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightTeleportOnSameMapMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightTeleportOnSameMapMessage.cellId.";
  }
}

GameActionFightTeleportOnSameMapMessage::GameActionFightTeleportOnSameMapMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE;
}

