#include "GameFightPlacementPositionRequestMessage.h"

void GameFightPlacementPositionRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightPlacementPositionRequestMessage(output);
}

void GameFightPlacementPositionRequestMessage::serializeAs_GameFightPlacementPositionRequestMessage(Writer *output)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementPositionRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
}

void GameFightPlacementPositionRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightPlacementPositionRequestMessage(input);
}

void GameFightPlacementPositionRequestMessage::deserializeAs_GameFightPlacementPositionRequestMessage(Reader *input)
{
  this->_cellIdFunc(input);
}

void GameFightPlacementPositionRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightPlacementPositionRequestMessage(tree);
}

void GameFightPlacementPositionRequestMessage::deserializeAsyncAs_GameFightPlacementPositionRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightPlacementPositionRequestMessage::_cellIdFunc, this, std::placeholders::_1));
}

void GameFightPlacementPositionRequestMessage::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementPositionRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameFightPlacementPositionRequestMessage.cellId.";
  }
}

GameFightPlacementPositionRequestMessage::GameFightPlacementPositionRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE;
}

