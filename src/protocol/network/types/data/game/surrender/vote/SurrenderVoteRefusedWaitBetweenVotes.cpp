#include "SurrenderVoteRefusedWaitBetweenVotes.h"

void SurrenderVoteRefusedWaitBetweenVotes::serialize(Writer *output)
{
  this->serializeAs_SurrenderVoteRefusedWaitBetweenVotes(output);
}

void SurrenderVoteRefusedWaitBetweenVotes::serializeAs_SurrenderVoteRefusedWaitBetweenVotes(Writer *output)
{
  SurrenderVoteRefused::serializeAs_SurrenderVoteRefused(output);
  output->writeInt((int)this->nextVoteTimestamp);
}

void SurrenderVoteRefusedWaitBetweenVotes::deserialize(Reader *input)
{
  this->deserializeAs_SurrenderVoteRefusedWaitBetweenVotes(input);
}

void SurrenderVoteRefusedWaitBetweenVotes::deserializeAs_SurrenderVoteRefusedWaitBetweenVotes(Reader *input)
{
  SurrenderVoteRefused::deserialize(input);
  this->_nextVoteTimestampFunc(input);
}

void SurrenderVoteRefusedWaitBetweenVotes::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SurrenderVoteRefusedWaitBetweenVotes(tree);
}

void SurrenderVoteRefusedWaitBetweenVotes::deserializeAsyncAs_SurrenderVoteRefusedWaitBetweenVotes(FuncTree tree)
{
  SurrenderVoteRefused::deserializeAsync(tree);
  tree.addChild(std::bind(&SurrenderVoteRefusedWaitBetweenVotes::_nextVoteTimestampFunc, this, std::placeholders::_1));
}

void SurrenderVoteRefusedWaitBetweenVotes::_nextVoteTimestampFunc(Reader *input)
{
  this->nextVoteTimestamp = input->readInt();
}

SurrenderVoteRefusedWaitBetweenVotes::SurrenderVoteRefusedWaitBetweenVotes()
{
  m_types<<ClassEnum::SURRENDERVOTEREFUSEDWAITBETWEENVOTES;
}

bool SurrenderVoteRefusedWaitBetweenVotes::operator==(const SurrenderVoteRefusedWaitBetweenVotes &compared)
{
  if(nextVoteTimestamp == compared.nextVoteTimestamp)
  return true;
  
  return false;
}

