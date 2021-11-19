#include "GameFightNewRoundMessage.h"

void GameFightNewRoundMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightNewRoundMessage(output);
}

void GameFightNewRoundMessage::serializeAs_GameFightNewRoundMessage(Writer *output)
{
  if(this->roundNumber < 0)
  {
    qDebug()<<"ERREUR - GameFightNewRoundMessage -"<<"Forbidden value (" << this->roundNumber << ") on element roundNumber.";
  }
  output->writeVarInt((int)this->roundNumber);
}

void GameFightNewRoundMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightNewRoundMessage(input);
}

void GameFightNewRoundMessage::deserializeAs_GameFightNewRoundMessage(Reader *input)
{
  this->_roundNumberFunc(input);
}

void GameFightNewRoundMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightNewRoundMessage(tree);
}

void GameFightNewRoundMessage::deserializeAsyncAs_GameFightNewRoundMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightNewRoundMessage::_roundNumberFunc, this, std::placeholders::_1));
}

void GameFightNewRoundMessage::_roundNumberFunc(Reader *input)
{
  this->roundNumber = input->readVarUhInt();
  if(this->roundNumber < 0)
  {
    qDebug()<<"ERREUR - GameFightNewRoundMessage -"<<"Forbidden value (" << this->roundNumber << ") on element of GameFightNewRoundMessage.roundNumber.";
  }
}

GameFightNewRoundMessage::GameFightNewRoundMessage()
{
  m_type = MessageEnum::GAMEFIGHTNEWROUNDMESSAGE;
}

