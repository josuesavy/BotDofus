#include "GameFightNewWaveMessage.h"

void GameFightNewWaveMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightNewWaveMessage(output);
}

void GameFightNewWaveMessage::serializeAs_GameFightNewWaveMessage(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GameFightNewWaveMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeByte(this->id);
  output->writeByte(this->teamId);
  output->writeShort((short)this->nbTurnBeforeNextWave);
}

void GameFightNewWaveMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightNewWaveMessage(input);
}

void GameFightNewWaveMessage::deserializeAs_GameFightNewWaveMessage(Reader *input)
{
  this->_idFunc(input);
  this->_teamIdFunc(input);
  this->_nbTurnBeforeNextWaveFunc(input);
}

void GameFightNewWaveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightNewWaveMessage(tree);
}

void GameFightNewWaveMessage::deserializeAsyncAs_GameFightNewWaveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightNewWaveMessage::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightNewWaveMessage::_teamIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightNewWaveMessage::_nbTurnBeforeNextWaveFunc, this, std::placeholders::_1));
}

void GameFightNewWaveMessage::_idFunc(Reader *input)
{
  this->id = input->readByte();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GameFightNewWaveMessage -"<<"Forbidden value (" << this->id << ") on element of GameFightNewWaveMessage.id.";
  }
}

void GameFightNewWaveMessage::_teamIdFunc(Reader *input)
{
  this->teamId = input->readByte();
  if(this->teamId < 0)
  {
    qDebug()<<"ERREUR - GameFightNewWaveMessage -"<<"Forbidden value (" << this->teamId << ") on element of GameFightNewWaveMessage.teamId.";
  }
}

void GameFightNewWaveMessage::_nbTurnBeforeNextWaveFunc(Reader *input)
{
  this->nbTurnBeforeNextWave = input->readShort();
}

GameFightNewWaveMessage::GameFightNewWaveMessage()
{
  m_type = MessageEnum::GAMEFIGHTNEWWAVEMESSAGE;
}

