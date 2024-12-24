#include "ArenaLeagueRanking.h"

void ArenaLeagueRanking::serialize(Writer *output)
{
  this->serializeAs_ArenaLeagueRanking(output);
}

void ArenaLeagueRanking::serializeAs_ArenaLeagueRanking(Writer *output)
{
  if(this->rating < 0 || this->rating > 20000)
  {
    qDebug()<<"ERREUR - ArenaLeagueRanking -"<<"Forbidden value (" << this->rating << ") on element rating.";
  }
  output->writeInt((int)this->rating);
  output->writeVarShort((int)this->leagueId);
  output->writeInt((int)this->ladderPosition);
}

void ArenaLeagueRanking::deserialize(Reader *input)
{
  this->deserializeAs_ArenaLeagueRanking(input);
}

void ArenaLeagueRanking::deserializeAs_ArenaLeagueRanking(Reader *input)
{
  this->_ratingFunc(input);
  this->_leagueIdFunc(input);
  this->_ladderPositionFunc(input);
}

void ArenaLeagueRanking::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ArenaLeagueRanking(tree);
}

void ArenaLeagueRanking::deserializeAsyncAs_ArenaLeagueRanking(FuncTree tree)
{
  tree.addChild(std::bind(&ArenaLeagueRanking::_ratingFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaLeagueRanking::_leagueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaLeagueRanking::_ladderPositionFunc, this, std::placeholders::_1));
}

void ArenaLeagueRanking::_ratingFunc(Reader *input)
{
  this->rating = input->readInt();
  if(this->rating < 0 || this->rating > 20000)
  {
    qDebug()<<"ERREUR - ArenaLeagueRanking -"<<"Forbidden value (" << this->rating << ") on element of ArenaLeagueRanking.rating.";
  }
}

void ArenaLeagueRanking::_leagueIdFunc(Reader *input)
{
  this->leagueId = input->readVarShort();
}

void ArenaLeagueRanking::_ladderPositionFunc(Reader *input)
{
  this->ladderPosition = input->readInt();
}

ArenaLeagueRanking::ArenaLeagueRanking()
{
  m_types<<ClassEnum::ARENALEAGUERANKING;
}

bool ArenaLeagueRanking::operator==(const ArenaLeagueRanking &compared)
{
  if(rating == compared.rating)
  if(leagueId == compared.leagueId)
  if(ladderPosition == compared.ladderPosition)
  return true;
  
  return false;
}

