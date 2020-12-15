#include "GameMapMovementCancelMessage.h"

void GameMapMovementCancelMessage::serialize(Writer *output)
{
  this->serializeAs_GameMapMovementCancelMessage(output);
}

void GameMapMovementCancelMessage::serializeAs_GameMapMovementCancelMessage(Writer *output)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameMapMovementCancelMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
}

void GameMapMovementCancelMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameMapMovementCancelMessage(input);
}

void GameMapMovementCancelMessage::deserializeAs_GameMapMovementCancelMessage(Reader *input)
{
  this->_cellIdFunc(input);
}

void GameMapMovementCancelMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameMapMovementCancelMessage(tree);
}

void GameMapMovementCancelMessage::deserializeAsyncAs_GameMapMovementCancelMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameMapMovementCancelMessage::_cellIdFunc, this, std::placeholders::_1));
}

void GameMapMovementCancelMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameMapMovementCancelMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameMapMovementCancelMessage.cellId.";
  }
}

GameMapMovementCancelMessage::GameMapMovementCancelMessage()
{
  m_type = MessageEnum::GAMEMAPMOVEMENTCANCELMESSAGE;
}

