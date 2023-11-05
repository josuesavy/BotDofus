#include "GameActionFightSlideMessage.h"

void GameActionFightSlideMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightSlideMessage(output);
}

void GameActionFightSlideMessage::serializeAs_GameActionFightSlideMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->startCellId < -1 || this->startCellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->startCellId << ") on element startCellId.";
  }
  output->writeShort((short)this->startCellId);
  if(this->endCellId < -1 || this->endCellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->endCellId << ") on element endCellId.";
  }
  output->writeShort((short)this->endCellId);
}

void GameActionFightSlideMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightSlideMessage(input);
}

void GameActionFightSlideMessage::deserializeAs_GameActionFightSlideMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_startCellIdFunc(input);
  this->_endCellIdFunc(input);
}

void GameActionFightSlideMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightSlideMessage(tree);
}

void GameActionFightSlideMessage::deserializeAsyncAs_GameActionFightSlideMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightSlideMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightSlideMessage::_startCellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightSlideMessage::_endCellIdFunc, this, std::placeholders::_1));
}

void GameActionFightSlideMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9007199254740992 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightSlideMessage.targetId.";
  }
}

void GameActionFightSlideMessage::_startCellIdFunc(Reader *input)
{
  this->startCellId = input->readShort();
  if(this->startCellId < -1 || this->startCellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->startCellId << ") on element of GameActionFightSlideMessage.startCellId.";
  }
}

void GameActionFightSlideMessage::_endCellIdFunc(Reader *input)
{
  this->endCellId = input->readShort();
  if(this->endCellId < -1 || this->endCellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightSlideMessage -"<<"Forbidden value (" << this->endCellId << ") on element of GameActionFightSlideMessage.endCellId.";
  }
}

GameActionFightSlideMessage::GameActionFightSlideMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSLIDEMESSAGE;
}

