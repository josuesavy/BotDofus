#include "GameRolePlayArenaLeagueRewardsMessage.h"

void GameRolePlayArenaLeagueRewardsMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaLeagueRewardsMessage(output);
}

void GameRolePlayArenaLeagueRewardsMessage::serializeAs_GameRolePlayArenaLeagueRewardsMessage(Writer *output)
{
  if(this->seasonId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaLeagueRewardsMessage -"<<"Forbidden value (" << this->seasonId << ") on element seasonId.";
  }
  output->writeVarShort((int)this->seasonId);
  if(this->leagueId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaLeagueRewardsMessage -"<<"Forbidden value (" << this->leagueId << ") on element leagueId.";
  }
  output->writeVarShort((int)this->leagueId);
  output->writeInt((int)this->ladderPosition);
  output->writeBool(this->endSeasonReward);
}

void GameRolePlayArenaLeagueRewardsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaLeagueRewardsMessage(input);
}

void GameRolePlayArenaLeagueRewardsMessage::deserializeAs_GameRolePlayArenaLeagueRewardsMessage(Reader *input)
{
  this->_seasonIdFunc(input);
  this->_leagueIdFunc(input);
  this->_ladderPositionFunc(input);
  this->_endSeasonRewardFunc(input);
}

void GameRolePlayArenaLeagueRewardsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaLeagueRewardsMessage(tree);
}

void GameRolePlayArenaLeagueRewardsMessage::deserializeAsyncAs_GameRolePlayArenaLeagueRewardsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaLeagueRewardsMessage::_seasonIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaLeagueRewardsMessage::_leagueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaLeagueRewardsMessage::_ladderPositionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaLeagueRewardsMessage::_endSeasonRewardFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaLeagueRewardsMessage::_seasonIdFunc(Reader *input)
{
  this->seasonId = input->readVarUhShort();
  if(this->seasonId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaLeagueRewardsMessage -"<<"Forbidden value (" << this->seasonId << ") on element of GameRolePlayArenaLeagueRewardsMessage.seasonId.";
  }
}

void GameRolePlayArenaLeagueRewardsMessage::_leagueIdFunc(Reader *input)
{
  this->leagueId = input->readVarUhShort();
  if(this->leagueId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaLeagueRewardsMessage -"<<"Forbidden value (" << this->leagueId << ") on element of GameRolePlayArenaLeagueRewardsMessage.leagueId.";
  }
}

void GameRolePlayArenaLeagueRewardsMessage::_ladderPositionFunc(Reader *input)
{
  this->ladderPosition = input->readInt();
}

void GameRolePlayArenaLeagueRewardsMessage::_endSeasonRewardFunc(Reader *input)
{
  this->endSeasonReward = input->readBool();
}

GameRolePlayArenaLeagueRewardsMessage::GameRolePlayArenaLeagueRewardsMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENALEAGUEREWARDSMESSAGE;
}

