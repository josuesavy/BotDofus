#include "ArenaRankInfos.h"

void ArenaRankInfos::serialize(Writer *output)
{
  this->serializeAs_ArenaRankInfos(output);
}

void ArenaRankInfos::serializeAs_ArenaRankInfos(Writer *output)
{
  if(this->ranking == NULL)
  {
    output->writeByte(0);
  }
  else
  {
    output->writeByte(1);
    this->ranking->serializeAs_ArenaRanking(output);
  }
  if(this->leagueRanking == NULL)
  {
    output->writeByte(0);
  }
  else
  {
    output->writeByte(1);
    this->leagueRanking->serializeAs_ArenaLeagueRanking(output);
  }
  if(this->victoryCount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->victoryCount << ") on element victoryCount.";
  }
  output->writeVarShort((int)this->victoryCount);
  if(this->fightcount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->fightcount << ") on element fightcount.";
  }
  output->writeVarShort((int)this->fightcount);
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
  if(input->readByte() == 0)
  {
    this->ranking = NULL;
  }
  else
  {
    this->ranking = new ArenaRanking();
    this->ranking->deserialize(input);
  }
  if(input->readByte() == 0)
  {
    this->leagueRanking = NULL;
  }
  else
  {
    this->leagueRanking = new ArenaLeagueRanking();
    this->leagueRanking->deserialize(input);
  }
  this->_victoryCountFunc(input);
  this->_fightcountFunc(input);
  this->_numFightNeededForLadderFunc(input);
}

void ArenaRankInfos::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ArenaRankInfos(tree);
}

void ArenaRankInfos::deserializeAsyncAs_ArenaRankInfos(FuncTree tree)
{
  this->_rankingtree = tree.addChild(std::bind(&ArenaRankInfos::_rankingtreeFunc, this, std::placeholders::_1));
  this->_leagueRankingtree = tree.addChild(std::bind(&ArenaRankInfos::_leagueRankingtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_victoryCountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_fightcountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRankInfos::_numFightNeededForLadderFunc, this, std::placeholders::_1));
}

void ArenaRankInfos::_rankingtreeFunc(Reader *input)
{
  this->ranking = new ArenaRanking();
  this->ranking->deserializeAsync(this->_rankingtree);
}

void ArenaRankInfos::_leagueRankingtreeFunc(Reader *input)
{
  this->leagueRanking = new ArenaLeagueRanking();
  this->leagueRanking->deserializeAsync(this->_leagueRankingtree);
}

void ArenaRankInfos::_victoryCountFunc(Reader *input)
{
  this->victoryCount = input->readVarUhShort();
  if(this->victoryCount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->victoryCount << ") on element of ArenaRankInfos.victoryCount.";
  }
}

void ArenaRankInfos::_fightcountFunc(Reader *input)
{
  this->fightcount = input->readVarUhShort();
  if(this->fightcount < 0)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->fightcount << ") on element of ArenaRankInfos.fightcount.";
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
  if(ranking == compared.ranking)
  if(leagueRanking == compared.leagueRanking)
  if(victoryCount == compared.victoryCount)
  if(fightcount == compared.fightcount)
  if(numFightNeededForLadder == compared.numFightNeededForLadder)
  if(_rankingtree == compared._rankingtree)
  if(_leagueRankingtree == compared._leagueRankingtree)
  return true;
  
  return false;
}

