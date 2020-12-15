#include "GameFightSpectatePlayerRequestMessage.h"

void GameFightSpectatePlayerRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightSpectatePlayerRequestMessage(output);
}

void GameFightSpectatePlayerRequestMessage::serializeAs_GameFightSpectatePlayerRequestMessage(Writer *output)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightSpectatePlayerRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void GameFightSpectatePlayerRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightSpectatePlayerRequestMessage(input);
}

void GameFightSpectatePlayerRequestMessage::deserializeAs_GameFightSpectatePlayerRequestMessage(Reader *input)
{
  this->_playerIdFunc(input);
}

void GameFightSpectatePlayerRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightSpectatePlayerRequestMessage(tree);
}

void GameFightSpectatePlayerRequestMessage::deserializeAsyncAs_GameFightSpectatePlayerRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightSpectatePlayerRequestMessage::_playerIdFunc, this, std::placeholders::_1));
}

void GameFightSpectatePlayerRequestMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightSpectatePlayerRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of GameFightSpectatePlayerRequestMessage.playerId.";
  }
}

GameFightSpectatePlayerRequestMessage::GameFightSpectatePlayerRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE;
}

