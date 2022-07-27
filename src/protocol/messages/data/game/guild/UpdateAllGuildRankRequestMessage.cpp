#include "UpdateAllGuildRankRequestMessage.h"

void UpdateAllGuildRankRequestMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateAllGuildRankRequestMessage(output);
}

void UpdateAllGuildRankRequestMessage::serializeAs_UpdateAllGuildRankRequestMessage(Writer *output)
{
  output->writeShort((short)this->ranks.size());
  for(uint _i1 = 0; _i1 < this->ranks.size(); _i1++)
  {
    (this->ranks[_i1]).serializeAs_GuildRankInformation(output);
  }
}

void UpdateAllGuildRankRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateAllGuildRankRequestMessage(input);
}

void UpdateAllGuildRankRequestMessage::deserializeAs_UpdateAllGuildRankRequestMessage(Reader *input)
{
  GuildRankInformation _item1 ;
  uint _ranksLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _ranksLen; _i1++)
  {
    _item1 = GuildRankInformation();
    _item1.deserialize(input);
    this->ranks.append(_item1);
  }
}

void UpdateAllGuildRankRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateAllGuildRankRequestMessage(tree);
}

void UpdateAllGuildRankRequestMessage::deserializeAsyncAs_UpdateAllGuildRankRequestMessage(FuncTree tree)
{
  this->_rankstree = tree.addChild(std::bind(&UpdateAllGuildRankRequestMessage::_rankstreeFunc, this, std::placeholders::_1));
}

void UpdateAllGuildRankRequestMessage::_rankstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_rankstree.addChild(std::bind(&UpdateAllGuildRankRequestMessage::_ranksFunc, this, std::placeholders::_1));
  }
}

void UpdateAllGuildRankRequestMessage::_ranksFunc(Reader *input)
{
  GuildRankInformation _item = GuildRankInformation();
  _item.deserialize(input);
  this->ranks.append(_item);
}

UpdateAllGuildRankRequestMessage::UpdateAllGuildRankRequestMessage()
{
  m_type = MessageEnum::UPDATEALLGUILDRANKREQUESTMESSAGE;
}

