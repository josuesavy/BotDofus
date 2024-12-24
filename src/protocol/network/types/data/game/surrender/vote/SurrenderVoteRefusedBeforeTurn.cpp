#include "SurrenderVoteRefusedBeforeTurn.h"

void SurrenderVoteRefusedBeforeTurn::serialize(Writer *output)
{
  this->serializeAs_SurrenderVoteRefusedBeforeTurn(output);
}

void SurrenderVoteRefusedBeforeTurn::serializeAs_SurrenderVoteRefusedBeforeTurn(Writer *output)
{
  SurrenderVoteRefused::serializeAs_SurrenderVoteRefused(output);
  output->writeInt((int)this->minTurnForSurrenderVote);
}

void SurrenderVoteRefusedBeforeTurn::deserialize(Reader *input)
{
  this->deserializeAs_SurrenderVoteRefusedBeforeTurn(input);
}

void SurrenderVoteRefusedBeforeTurn::deserializeAs_SurrenderVoteRefusedBeforeTurn(Reader *input)
{
  SurrenderVoteRefused::deserialize(input);
  this->_minTurnForSurrenderVoteFunc(input);
}

void SurrenderVoteRefusedBeforeTurn::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SurrenderVoteRefusedBeforeTurn(tree);
}

void SurrenderVoteRefusedBeforeTurn::deserializeAsyncAs_SurrenderVoteRefusedBeforeTurn(FuncTree tree)
{
  SurrenderVoteRefused::deserializeAsync(tree);
  tree.addChild(std::bind(&SurrenderVoteRefusedBeforeTurn::_minTurnForSurrenderVoteFunc, this, std::placeholders::_1));
}

void SurrenderVoteRefusedBeforeTurn::_minTurnForSurrenderVoteFunc(Reader *input)
{
  this->minTurnForSurrenderVote = input->readInt();
}

SurrenderVoteRefusedBeforeTurn::SurrenderVoteRefusedBeforeTurn()
{
  m_types<<ClassEnum::SURRENDERVOTEREFUSEDBEFORETURN;
}

bool SurrenderVoteRefusedBeforeTurn::operator==(const SurrenderVoteRefusedBeforeTurn &compared)
{
  if(minTurnForSurrenderVote == compared.minTurnForSurrenderVote)
  return true;
  
  return false;
}

