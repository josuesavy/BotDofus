#include "GameFightOptionStateUpdateMessage.h"

void GameFightOptionStateUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightOptionStateUpdateMessage(output);
}

void GameFightOptionStateUpdateMessage::serializeAs_GameFightOptionStateUpdateMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightOptionStateUpdateMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeByte(this->teamId);
  output->writeByte(this->option);
  output->writeBool(this->state);
}

void GameFightOptionStateUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightOptionStateUpdateMessage(input);
}

void GameFightOptionStateUpdateMessage::deserializeAs_GameFightOptionStateUpdateMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_teamIdFunc(input);
  this->_optionFunc(input);
  this->_stateFunc(input);
}

void GameFightOptionStateUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightOptionStateUpdateMessage(tree);
}

void GameFightOptionStateUpdateMessage::deserializeAsyncAs_GameFightOptionStateUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightOptionStateUpdateMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightOptionStateUpdateMessage::_teamIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightOptionStateUpdateMessage::_optionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightOptionStateUpdateMessage::_stateFunc, this, std::placeholders::_1));
}

void GameFightOptionStateUpdateMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightOptionStateUpdateMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameFightOptionStateUpdateMessage.fightId.";
  }
}

void GameFightOptionStateUpdateMessage::_teamIdFunc(Reader *input)
{
  this->teamId = input->readByte();
  if(this->teamId < 0)
  {
    qDebug()<<"ERREUR - GameFightOptionStateUpdateMessage -"<<"Forbidden value (" << this->teamId << ") on element of GameFightOptionStateUpdateMessage.teamId.";
  }
}

void GameFightOptionStateUpdateMessage::_optionFunc(Reader *input)
{
  this->option = input->readByte();
  if(this->option < 0)
  {
    qDebug()<<"ERREUR - GameFightOptionStateUpdateMessage -"<<"Forbidden value (" << this->option << ") on element of GameFightOptionStateUpdateMessage.option.";
  }
}

void GameFightOptionStateUpdateMessage::_stateFunc(Reader *input)
{
  this->state = input->readBool();
}

GameFightOptionStateUpdateMessage::GameFightOptionStateUpdateMessage()
{
  m_type = MessageEnum::GAMEFIGHTOPTIONSTATEUPDATEMESSAGE;
}

