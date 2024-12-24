#include "SurrenderVoteEndMessage.h"

void SurrenderVoteEndMessage::serialize(Writer *output)
{
  this->serializeAs_SurrenderVoteEndMessage(output);
}

void SurrenderVoteEndMessage::serializeAs_SurrenderVoteEndMessage(Writer *output)
{
  output->writeBool(this->voteResult);
}

void SurrenderVoteEndMessage::deserialize(Reader *input)
{
  this->deserializeAs_SurrenderVoteEndMessage(input);
}

void SurrenderVoteEndMessage::deserializeAs_SurrenderVoteEndMessage(Reader *input)
{
  this->_voteResultFunc(input);
}

void SurrenderVoteEndMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SurrenderVoteEndMessage(tree);
}

void SurrenderVoteEndMessage::deserializeAsyncAs_SurrenderVoteEndMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SurrenderVoteEndMessage::_voteResultFunc, this, std::placeholders::_1));
}

void SurrenderVoteEndMessage::_voteResultFunc(Reader *input)
{
  this->voteResult = input->readBool();
}

SurrenderVoteEndMessage::SurrenderVoteEndMessage()
{
  m_type = MessageEnum::SURRENDERVOTEENDMESSAGE;
}

