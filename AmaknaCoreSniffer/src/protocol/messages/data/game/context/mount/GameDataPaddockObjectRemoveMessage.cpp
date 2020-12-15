#include "GameDataPaddockObjectRemoveMessage.h"

void GameDataPaddockObjectRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_GameDataPaddockObjectRemoveMessage(output);
}

void GameDataPaddockObjectRemoveMessage::serializeAs_GameDataPaddockObjectRemoveMessage(Writer *output)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameDataPaddockObjectRemoveMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
}

void GameDataPaddockObjectRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameDataPaddockObjectRemoveMessage(input);
}

void GameDataPaddockObjectRemoveMessage::deserializeAs_GameDataPaddockObjectRemoveMessage(Reader *input)
{
  this->_cellIdFunc(input);
}

void GameDataPaddockObjectRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameDataPaddockObjectRemoveMessage(tree);
}

void GameDataPaddockObjectRemoveMessage::deserializeAsyncAs_GameDataPaddockObjectRemoveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameDataPaddockObjectRemoveMessage::_cellIdFunc, this, std::placeholders::_1));
}

void GameDataPaddockObjectRemoveMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameDataPaddockObjectRemoveMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameDataPaddockObjectRemoveMessage.cellId.";
  }
}

GameDataPaddockObjectRemoveMessage::GameDataPaddockObjectRemoveMessage()
{
  m_type = MessageEnum::GAMEDATAPADDOCKOBJECTREMOVEMESSAGE;
}

