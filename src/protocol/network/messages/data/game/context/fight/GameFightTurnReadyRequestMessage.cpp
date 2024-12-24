#include "GameFightTurnReadyRequestMessage.h"

void GameFightTurnReadyRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightTurnReadyRequestMessage(output);
}

void GameFightTurnReadyRequestMessage::serializeAs_GameFightTurnReadyRequestMessage(Writer *output)
{
  if(this->id < -9007199254740992 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightTurnReadyRequestMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
}

void GameFightTurnReadyRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightTurnReadyRequestMessage(input);
}

void GameFightTurnReadyRequestMessage::deserializeAs_GameFightTurnReadyRequestMessage(Reader *input)
{
  this->_idFunc(input);
}

void GameFightTurnReadyRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightTurnReadyRequestMessage(tree);
}

void GameFightTurnReadyRequestMessage::deserializeAsyncAs_GameFightTurnReadyRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightTurnReadyRequestMessage::_idFunc, this, std::placeholders::_1));
}

void GameFightTurnReadyRequestMessage::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9007199254740992 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightTurnReadyRequestMessage -"<<"Forbidden value (" << this->id << ") on element of GameFightTurnReadyRequestMessage.id.";
  }
}

GameFightTurnReadyRequestMessage::GameFightTurnReadyRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNREADYREQUESTMESSAGE;
}

