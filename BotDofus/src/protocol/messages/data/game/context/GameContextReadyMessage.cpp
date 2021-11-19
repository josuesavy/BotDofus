#include "GameContextReadyMessage.h"

void GameContextReadyMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextReadyMessage(output);
}

void GameContextReadyMessage::serializeAs_GameContextReadyMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextReadyMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
}

void GameContextReadyMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextReadyMessage(input);
}

void GameContextReadyMessage::deserializeAs_GameContextReadyMessage(Reader *input)
{
  this->_mapIdFunc(input);
}

void GameContextReadyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextReadyMessage(tree);
}

void GameContextReadyMessage::deserializeAsyncAs_GameContextReadyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameContextReadyMessage::_mapIdFunc, this, std::placeholders::_1));
}

void GameContextReadyMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextReadyMessage -"<<"Forbidden value (" << this->mapId << ") on element of GameContextReadyMessage.mapId.";
  }
}

GameContextReadyMessage::GameContextReadyMessage()
{
  m_type = MessageEnum::GAMECONTEXTREADYMESSAGE;
}

