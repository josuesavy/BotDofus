#include "ArenaRanking.h"

void ArenaRanking::serialize(Writer *output)
{
  this->serializeAs_ArenaRanking(output);
}

void ArenaRanking::serializeAs_ArenaRanking(Writer *output)
{
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - ArenaRanking -"<<"Forbidden value (" << this->rank << ") on element rank.";
  }
  output->writeVarShort((int)this->rank);
  if(this->bestRank < 0 || this->bestRank > 20000)
  {
    qDebug()<<"ERREUR - ArenaRanking -"<<"Forbidden value (" << this->bestRank << ") on element bestRank.";
  }
  output->writeVarShort((int)this->bestRank);
}

void ArenaRanking::deserialize(Reader *input)
{
  this->deserializeAs_ArenaRanking(input);
}

void ArenaRanking::deserializeAs_ArenaRanking(Reader *input)
{
  this->_rankFunc(input);
  this->_bestRankFunc(input);
}

void ArenaRanking::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ArenaRanking(tree);
}

void ArenaRanking::deserializeAsyncAs_ArenaRanking(FuncTree tree)
{
  tree.addChild(std::bind(&ArenaRanking::_rankFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ArenaRanking::_bestRankFunc, this, std::placeholders::_1));
}

void ArenaRanking::_rankFunc(Reader *input)
{
  this->rank = input->readVarUhShort();
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - ArenaRanking -"<<"Forbidden value (" << this->rank << ") on element of ArenaRanking.rank.";
  }
}

void ArenaRanking::_bestRankFunc(Reader *input)
{
  this->bestRank = input->readVarUhShort();
  if(this->bestRank < 0 || this->bestRank > 20000)
  {
    qDebug()<<"ERREUR - ArenaRanking -"<<"Forbidden value (" << this->bestRank << ") on element of ArenaRanking.bestRank.";
  }
}

ArenaRanking::ArenaRanking()
{
  m_types<<ClassEnum::ARENARANKING;
}

bool ArenaRanking::operator==(const ArenaRanking &compared)
{
  if(rank == compared.rank)
  if(bestRank == compared.bestRank)
  return true;
  
  return false;
}

