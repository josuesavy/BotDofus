#include "GameActionFightInvisibleDetectedMessage.h"

void GameActionFightInvisibleDetectedMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightInvisibleDetectedMessage(output);
}

void GameActionFightInvisibleDetectedMessage::serializeAs_GameActionFightInvisibleDetectedMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibleDetectedMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibleDetectedMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeShort((short)this->cellId);
}

void GameActionFightInvisibleDetectedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightInvisibleDetectedMessage(input);
}

void GameActionFightInvisibleDetectedMessage::deserializeAs_GameActionFightInvisibleDetectedMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_cellIdFunc(input);
}

void GameActionFightInvisibleDetectedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightInvisibleDetectedMessage(tree);
}

void GameActionFightInvisibleDetectedMessage::deserializeAsyncAs_GameActionFightInvisibleDetectedMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightInvisibleDetectedMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightInvisibleDetectedMessage::_cellIdFunc, this, std::placeholders::_1));
}

void GameActionFightInvisibleDetectedMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibleDetectedMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightInvisibleDetectedMessage.targetId.";
  }
}

void GameActionFightInvisibleDetectedMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readShort();
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightInvisibleDetectedMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightInvisibleDetectedMessage.cellId.";
  }
}

GameActionFightInvisibleDetectedMessage::GameActionFightInvisibleDetectedMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE;
}

