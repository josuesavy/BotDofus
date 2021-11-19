#include "GameActionFightThrowCharacterMessage.h"

void GameActionFightThrowCharacterMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightThrowCharacterMessage(output);
}

void GameActionFightThrowCharacterMessage::serializeAs_GameActionFightThrowCharacterMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightThrowCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightThrowCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeShort((short)this->cellId);
}

void GameActionFightThrowCharacterMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightThrowCharacterMessage(input);
}

void GameActionFightThrowCharacterMessage::deserializeAs_GameActionFightThrowCharacterMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_cellIdFunc(input);
}

void GameActionFightThrowCharacterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightThrowCharacterMessage(tree);
}

void GameActionFightThrowCharacterMessage::deserializeAsyncAs_GameActionFightThrowCharacterMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightThrowCharacterMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightThrowCharacterMessage::_cellIdFunc, this, std::placeholders::_1));
}

void GameActionFightThrowCharacterMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightThrowCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightThrowCharacterMessage.targetId.";
  }
}

void GameActionFightThrowCharacterMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readShort();
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightThrowCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightThrowCharacterMessage.cellId.";
  }
}

GameActionFightThrowCharacterMessage::GameActionFightThrowCharacterMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTHROWCHARACTERMESSAGE;
}

