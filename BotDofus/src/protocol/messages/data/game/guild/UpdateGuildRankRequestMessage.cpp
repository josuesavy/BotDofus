#include "UpdateGuildRankRequestMessage.h"

void UpdateGuildRankRequestMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateGuildRankRequestMessage(output);
}

void UpdateGuildRankRequestMessage::serializeAs_UpdateGuildRankRequestMessage(Writer *output)
{
  this->rank.serializeAs_GuildRankInformation(output);
}

void UpdateGuildRankRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateGuildRankRequestMessage(input);
}

void UpdateGuildRankRequestMessage::deserializeAs_UpdateGuildRankRequestMessage(Reader *input)
{
  this->rank = GuildRankInformation();
  this->rank.deserialize(input);
}

void UpdateGuildRankRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateGuildRankRequestMessage(tree);
}

void UpdateGuildRankRequestMessage::deserializeAsyncAs_UpdateGuildRankRequestMessage(FuncTree tree)
{
  this->_ranktree = tree.addChild(std::bind(&UpdateGuildRankRequestMessage::_ranktreeFunc, this, std::placeholders::_1));
}

void UpdateGuildRankRequestMessage::_ranktreeFunc(Reader *input)
{
  this->rank = GuildRankInformation();
  this->rank.deserializeAsync(this->_ranktree);
}

UpdateGuildRankRequestMessage::UpdateGuildRankRequestMessage()
{
  m_type = MessageEnum::UPDATEGUILDRANKREQUESTMESSAGE;
}

