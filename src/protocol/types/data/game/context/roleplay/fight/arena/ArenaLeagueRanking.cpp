#include "ArenaLeagueRanking.h"

void ArenaLeagueRanking::serialize(Writer *output)
{
  this->serializeAs_ArenaLeagueRanking(output);
}

void ArenaLeagueRanking::serializeAs_ArenaLeagueRanking(Writer *output)
{
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - ArenaLeagueRanking -"<<"Forbidden value (" << this->rank << ") on element rank.";
  }
  output->writeVarShort((int)this->rank);
  if(this->leagueId < 0)
  {
    qDebug()<<"ERREUR - ArenaLeagueRanking -"<<"Forbidden value (" << this->leagueId << ") on element leagueId.";
  }
  output->writeVarShort((int)this->leagueId);
  output->writeVarShort((int)this->leaguePoints);
  output->writeVarShort((int)this->totalLeaguePoints);
  output->writeInt((int)this->ladderPosition);
}

void ArenaLeagueRanking::deserialize(Reader *input)
{
  this->deserializeAs_ArenaLeagueRanking(input);
}

void ArenaLeagueRanking::deserializeAs_ArenaLeagueRanking(Reader *input)
{
  this->_rankFunc(input);
  this->_leagueIdFunc(input);
  this->_leaguePointsFunc(input);
  this->_totalLeaguePointsFunc(input);
  this->_ladderPositionFunc(input);
}

void ArenaLeagueRanking::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ArenaLeagueRanking(tree);
}

void ArenaLeagueRanking::deserializeAsyncAs_ArenaLeagueRanking(FuncTree tree)
{
  tree.addChild(std::bind(&ArenaLeagueRanking::_rankFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaLeagueRanking::_leagueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaLeagueRanking::_leaguePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaLeagueRanking::_totalLeaguePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaLeagueRanking::_ladderPositionFunc, this, std::placeholders::_1));
}

void ArenaLeagueRanking::_rankFunc(Reader *input)
{
  this->rank = input->readVarUhShort();
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - ArenaLeagueRanking -"<<"Forbidden value (" << this->rank << ") on element of ArenaLeagueRanking.rank.";
  }
}

void ArenaLeagueRanking::_leagueIdFunc(Reader *input)
{
  this->leagueId = input->readVarUhShort();
  if(this->leagueId < 0)
  {
    qDebug()<<"ERREUR - ArenaLeagueRanking -"<<"Forbidden value (" << this->leagueId << ") on element of ArenaLeagueRanking.leagueId.";
  }
}

void ArenaLeagueRanking::_leaguePointsFunc(Reader *input)
{
  this->leaguePoints = input->readVarShort();
}

void ArenaLeagueRanking::_totalLeaguePointsFunc(Reader *input)
{
  this->totalLeaguePoints = input->readVarShort();
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
  if(rank == compared.rank)
  if(leagueId == compared.leagueId)
  if(leaguePoints == compared.leaguePoints)
  if(totalLeaguePoints == compared.totalLeaguePoints)
  if(ladderPosition == compared.ladderPosition)
  return true;
  
  return false;
}

