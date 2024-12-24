#include "GameActionFightCarryCharacterMessage.h"

void GameActionFightCarryCharacterMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightCarryCharacterMessage(output);
}

void GameActionFightCarryCharacterMessage::serializeAs_GameActionFightCarryCharacterMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightCarryCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightCarryCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeShort((short)this->cellId);
}

void GameActionFightCarryCharacterMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightCarryCharacterMessage(input);
}

void GameActionFightCarryCharacterMessage::deserializeAs_GameActionFightCarryCharacterMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_cellIdFunc(input);
}

void GameActionFightCarryCharacterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightCarryCharacterMessage(tree);
}

void GameActionFightCarryCharacterMessage::deserializeAsyncAs_GameActionFightCarryCharacterMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightCarryCharacterMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightCarryCharacterMessage::_cellIdFunc, this, std::placeholders::_1));
}

void GameActionFightCarryCharacterMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightCarryCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightCarryCharacterMessage.targetId.";
  }
}

void GameActionFightCarryCharacterMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readShort();
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightCarryCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightCarryCharacterMessage.cellId.";
  }
}

GameActionFightCarryCharacterMessage::GameActionFightCarryCharacterMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCARRYCHARACTERMESSAGE;
}

