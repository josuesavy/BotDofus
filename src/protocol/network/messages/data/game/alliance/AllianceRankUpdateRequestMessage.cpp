#include "AllianceRankUpdateRequestMessage.h"

void AllianceRankUpdateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceRankUpdateRequestMessage(output);
}

void AllianceRankUpdateRequestMessage::serializeAs_AllianceRankUpdateRequestMessage(Writer *output)
{
  this->rank.serializeAs_RankInformation(output);
}

void AllianceRankUpdateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceRankUpdateRequestMessage(input);
}

void AllianceRankUpdateRequestMessage::deserializeAs_AllianceRankUpdateRequestMessage(Reader *input)
{
  this->rank = RankInformation();
  this->rank.deserialize(input);
}

void AllianceRankUpdateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceRankUpdateRequestMessage(tree);
}

void AllianceRankUpdateRequestMessage::deserializeAsyncAs_AllianceRankUpdateRequestMessage(FuncTree tree)
{
  this->_ranktree = tree.addChild(std::bind(&AllianceRankUpdateRequestMessage::_ranktreeFunc, this, std::placeholders::_1));
}

void AllianceRankUpdateRequestMessage::_ranktreeFunc(Reader *input)
{
  this->rank = RankInformation();
  this->rank.deserializeAsync(this->_ranktree);
}

AllianceRankUpdateRequestMessage::AllianceRankUpdateRequestMessage()
{
  m_type = MessageEnum::ALLIANCERANKUPDATEREQUESTMESSAGE;
}

