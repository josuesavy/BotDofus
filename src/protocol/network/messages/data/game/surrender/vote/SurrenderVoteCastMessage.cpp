#include "SurrenderVoteCastMessage.h"

void SurrenderVoteCastMessage::serialize(Writer *output)
{
  this->serializeAs_SurrenderVoteCastMessage(output);
}

void SurrenderVoteCastMessage::serializeAs_SurrenderVoteCastMessage(Writer *output)
{
  output->writeBool(this->vote);
}

void SurrenderVoteCastMessage::deserialize(Reader *input)
{
  this->deserializeAs_SurrenderVoteCastMessage(input);
}

void SurrenderVoteCastMessage::deserializeAs_SurrenderVoteCastMessage(Reader *input)
{
  this->_voteFunc(input);
}

void SurrenderVoteCastMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SurrenderVoteCastMessage(tree);
}

void SurrenderVoteCastMessage::deserializeAsyncAs_SurrenderVoteCastMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SurrenderVoteCastMessage::_voteFunc, this, std::placeholders::_1));
}

void SurrenderVoteCastMessage::_voteFunc(Reader *input)
{
  this->vote = input->readBool();
}

SurrenderVoteCastMessage::SurrenderVoteCastMessage()
{
  m_type = MessageEnum::SURRENDERVOTECASTMESSAGE;
}

