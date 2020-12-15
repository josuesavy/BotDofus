#include "GameFightJoinRequestMessage.h"

void GameFightJoinRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightJoinRequestMessage(output);
}

void GameFightJoinRequestMessage::serializeAs_GameFightJoinRequestMessage(Writer *output)
{
  if(this->fighterId < -9.007199254740992E15 || this->fighterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightJoinRequestMessage -"<<"Forbidden value (" << this->fighterId << ") on element fighterId.";
  }
  output->writeDouble(this->fighterId);
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightJoinRequestMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
}

void GameFightJoinRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightJoinRequestMessage(input);
}

void GameFightJoinRequestMessage::deserializeAs_GameFightJoinRequestMessage(Reader *input)
{
  this->_fighterIdFunc(input);
  this->_fightIdFunc(input);
}

void GameFightJoinRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightJoinRequestMessage(tree);
}

void GameFightJoinRequestMessage::deserializeAsyncAs_GameFightJoinRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightJoinRequestMessage::_fighterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightJoinRequestMessage::_fightIdFunc, this, std::placeholders::_1));
}

void GameFightJoinRequestMessage::_fighterIdFunc(Reader *input)
{
  this->fighterId = input->readDouble();
  if(this->fighterId < -9.007199254740992E15 || this->fighterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightJoinRequestMessage -"<<"Forbidden value (" << this->fighterId << ") on element of GameFightJoinRequestMessage.fighterId.";
  }
}

void GameFightJoinRequestMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightJoinRequestMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameFightJoinRequestMessage.fightId.";
  }
}

GameFightJoinRequestMessage::GameFightJoinRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTJOINREQUESTMESSAGE;
}

