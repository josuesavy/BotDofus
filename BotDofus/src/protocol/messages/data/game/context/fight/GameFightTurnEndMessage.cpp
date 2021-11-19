#include "GameFightTurnEndMessage.h"

void GameFightTurnEndMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightTurnEndMessage(output);
}

void GameFightTurnEndMessage::serializeAs_GameFightTurnEndMessage(Writer *output)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnEndMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
}

void GameFightTurnEndMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightTurnEndMessage(input);
}

void GameFightTurnEndMessage::deserializeAs_GameFightTurnEndMessage(Reader *input)
{
  this->_idFunc(input);
}

void GameFightTurnEndMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightTurnEndMessage(tree);
}

void GameFightTurnEndMessage::deserializeAsyncAs_GameFightTurnEndMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightTurnEndMessage::_idFunc, this, std::placeholders::_1));
}

void GameFightTurnEndMessage::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnEndMessage -"<<"Forbidden value (" << this->id << ") on element of GameFightTurnEndMessage.id.";
  }
}

GameFightTurnEndMessage::GameFightTurnEndMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNENDMESSAGE;
}

