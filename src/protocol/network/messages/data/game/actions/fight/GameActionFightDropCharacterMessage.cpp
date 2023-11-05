#include "GameActionFightDropCharacterMessage.h"

void GameActionFightDropCharacterMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightDropCharacterMessage(output);
}

void GameActionFightDropCharacterMessage::serializeAs_GameActionFightDropCharacterMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightDropCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightDropCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeShort((short)this->cellId);
}

void GameActionFightDropCharacterMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightDropCharacterMessage(input);
}

void GameActionFightDropCharacterMessage::deserializeAs_GameActionFightDropCharacterMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_cellIdFunc(input);
}

void GameActionFightDropCharacterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightDropCharacterMessage(tree);
}

void GameActionFightDropCharacterMessage::deserializeAsyncAs_GameActionFightDropCharacterMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightDropCharacterMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightDropCharacterMessage::_cellIdFunc, this, std::placeholders::_1));
}

void GameActionFightDropCharacterMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightDropCharacterMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightDropCharacterMessage.targetId.";
  }
}

void GameActionFightDropCharacterMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readShort();
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightDropCharacterMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightDropCharacterMessage.cellId.";
  }
}

GameActionFightDropCharacterMessage::GameActionFightDropCharacterMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDROPCHARACTERMESSAGE;
}

