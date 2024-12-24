#include "ArenaRankInfos.h"

void ArenaRankInfos::serialize(Writer *output)
{
  this->serializeAs_ArenaRankInfos(output);
}

void ArenaRankInfos::serializeAs_ArenaRankInfos(Writer *output)
{
  output->writeInt((int)this->arenaType);
  if(this->leagueRanking == NULL)
  {
    output->writeByte(0);
  }
  else
  {
    output->writeByte(1);
    this->leagueRanking->serializeAs_ArenaLeagueRanking(output);
  }
  output->writeVarShort((int)this->bestLeagueId);
  if(this->bestRating < 0 || this->bestRating > 20000)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->bestRating << ") on element bestRating.";
  }
  output->writeInt((int)this->bestRating);
  if(this->dailyVictoryCount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->dailyVictoryCount << ") on element dailyVictoryCount.";
  }
  output->writeVarShort((int)this->dailyVictoryCount);
  if(this->seasonVictoryCount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->seasonVictoryCount << ") on element seasonVictoryCount.";
  }
  output->writeVarShort((int)this->seasonVictoryCount);
  if(this->dailyFightcount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->dailyFightcount << ") on element dailyFightcount.";
  }
  output->writeVarShort((int)this->dailyFightcount);
  if(this->seasonFightcount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->seasonFightcount << ") on element seasonFightcount.";
  }
  output->writeVarShort((int)this->seasonFightcount);
  if(this->numFightNeededForLadder < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->numFightNeededForLadder << ") on element numFightNeededForLadder.";
  }
  output->writeShort((short)this->numFightNeededForLadder);
}

void ArenaRankInfos::deserialize(Reader *input)
{
  this->deserializeAs_ArenaRankInfos(input);
}

void ArenaRankInfos::deserializeAs_ArenaRankInfos(Reader *input)
{
  this->_arenaTypeFunc(input);
  if(input->readByte() == 0)
  {
    this->leagueRanking = NULL;
  }
  else
  {
    this->leagueRanking = new ArenaLeagueRanking();
    this->leagueRanking->deserialize(input);
  }
  this->_bestLeagueIdFunc(input);
  this->_bestRatingFunc(input);
  this->_dailyVictoryCountFunc(input);
  this->_seasonVictoryCountFunc(input);
  this->_dailyFightcountFunc(input);
  this->_seasonFightcountFunc(input);
  this->_numFightNeededForLadderFunc(input);
}

void ArenaRankInfos::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ArenaRankInfos(tree);
}

void ArenaRankInfos::deserializeAsyncAs_ArenaRankInfos(FuncTree tree)
{
  tree.addChild(std::bind(&ArenaRankInfos::_arenaTypeFunc, this, std::placeholders::_1));
  this->_leagueRankingtree = tree.addChild(std::bind(&ArenaRankInfos::_leagueRankingtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_bestLeagueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_bestRatingFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_dailyVictoryCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_seasonVictoryCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_dailyFightcountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_seasonFightcountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_numFightNeededForLadderFunc, this, std::placeholders::_1));
}

void ArenaRankInfos::_arenaTypeFunc(Reader *input)
{
  this->arenaType = input->readInt();
  if(this->arenaType < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->arenaType << ") on element of ArenaRankInfos.arenaType.";
  }
}

void ArenaRankInfos::_leagueRankingtreeFunc(Reader *input)
{
  this->leagueRanking = new ArenaLeagueRanking();
  this->leagueRanking->deserializeAsync(this->_leagueRankingtree);
}

void ArenaRankInfos::_bestLeagueIdFunc(Reader *input)
{
  this->bestLeagueId = input->readVarShort();
}

void ArenaRankInfos::_bestRatingFunc(Reader *input)
{
  this->bestRating = input->readInt();
  if(this->bestRating < 0 || this->bestRating > 20000)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->bestRating << ") on element of ArenaRankInfos.bestRating.";
  }
}

void ArenaRankInfos::_dailyVictoryCountFunc(Reader *input)
{
  this->dailyVictoryCount = input->readVarUhShort();
  if(this->dailyVictoryCount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->dailyVictoryCount << ") on element of ArenaRankInfos.dailyVictoryCount.";
  }
}

void ArenaRankInfos::_seasonVictoryCountFunc(Reader *input)
{
  this->seasonVictoryCount = input->readVarUhShort();
  if(this->seasonVictoryCount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->seasonVictoryCount << ") on element of ArenaRankInfos.seasonVictoryCount.";
  }
}

void ArenaRankInfos::_dailyFightcountFunc(Reader *input)
{
  this->dailyFightcount = input->readVarUhShort();
  if(this->dailyFightcount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->dailyFightcount << ") on element of ArenaRankInfos.dailyFightcount.";
  }
}

void ArenaRankInfos::_seasonFightcountFunc(Reader *input)
{
  this->seasonFightcount = input->readVarUhShort();
  if(this->seasonFightcount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->seasonFightcount << ") on element of ArenaRankInfos.seasonFightcount.";
  }
}

void ArenaRankInfos::_numFightNeededForLadderFunc(Reader *input)
{
  this->numFightNeededForLadder = input->readShort();
  if(this->numFightNeededForLadder < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->numFightNeededForLadder << ") on element of ArenaRankInfos.numFightNeededForLadder.";
  }
}

ArenaRankInfos::ArenaRankInfos()
{
  m_types<<ClassEnum::ARENARANKINFOS;
}

bool ArenaRankInfos::operator==(const ArenaRankInfos &compared)
{
  if(arenaType == compared.arenaType)
  if(leagueRanking == compared.leagueRanking)
  if(bestLeagueId == compared.bestLeagueId)
  if(bestRating == compared.bestRating)
  if(dailyVictoryCount == compared.dailyVictoryCount)
  if(seasonVictoryCount == compared.seasonVictoryCount)
  if(dailyFightcount == compared.dailyFightcount)
  if(seasonFightcount == compared.seasonFightcount)
  if(numFightNeededForLadder == compared.numFightNeededForLadder)
  if(_leagueRankingtree == compared._leagueRankingtree)
  return true;
  
  return false;
}

