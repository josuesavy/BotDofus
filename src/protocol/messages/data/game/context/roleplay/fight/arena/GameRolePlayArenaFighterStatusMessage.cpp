#include "GameRolePlayArenaFighterStatusMessage.h"

void GameRolePlayArenaFighterStatusMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaFighterStatusMessage(output);
}

void GameRolePlayArenaFighterStatusMessage::serializeAs_GameRolePlayArenaFighterStatusMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFighterStatusMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFighterStatusMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeBool(this->accepted);
}

void GameRolePlayArenaFighterStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaFighterStatusMessage(input);
}

void GameRolePlayArenaFighterStatusMessage::deserializeAs_GameRolePlayArenaFighterStatusMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_playerIdFunc(input);
  this->_acceptedFunc(input);
}

void GameRolePlayArenaFighterStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaFighterStatusMessage(tree);
}

void GameRolePlayArenaFighterStatusMessage::deserializeAsyncAs_GameRolePlayArenaFighterStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaFighterStatusMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaFighterStatusMessage::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaFighterStatusMessage::_acceptedFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaFighterStatusMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFighterStatusMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayArenaFighterStatusMessage.fightId.";
  }
}

void GameRolePlayArenaFighterStatusMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFighterStatusMessage -"<<"Forbidden value (" << this->playerId << ") on element of GameRolePlayArenaFighterStatusMessage.playerId.";
  }
}

void GameRolePlayArenaFighterStatusMessage::_acceptedFunc(Reader *input)
{
  this->accepted = input->readBool();
}

GameRolePlayArenaFighterStatusMessage::GameRolePlayArenaFighterStatusMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE;
}

