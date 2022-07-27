#include "GuildRanksMessage.h"

void GuildRanksMessage::serialize(Writer *output)
{
  this->serializeAs_GuildRanksMessage(output);
}

void GuildRanksMessage::serializeAs_GuildRanksMessage(Writer *output)
{
  output->writeShort((short)this->ranks.size());
  for(uint _i1 = 0; _i1 < this->ranks.size(); _i1++)
  {
    (this->ranks[_i1]).serializeAs_GuildRankInformation(output);
  }
}

void GuildRanksMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildRanksMessage(input);
}

void GuildRanksMessage::deserializeAs_GuildRanksMessage(Reader *input)
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

void GuildRanksMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildRanksMessage(tree);
}

void GuildRanksMessage::deserializeAsyncAs_GuildRanksMessage(FuncTree tree)
{
  this->_rankstree = tree.addChild(std::bind(&GuildRanksMessage::_rankstreeFunc, this, std::placeholders::_1));
}

void GuildRanksMessage::_rankstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_rankstree.addChild(std::bind(&GuildRanksMessage::_ranksFunc, this, std::placeholders::_1));
  }
}

void GuildRanksMessage::_ranksFunc(Reader *input)
{
  GuildRankInformation _item = GuildRankInformation();
  _item.deserialize(input);
  this->ranks.append(_item);
}

GuildRanksMessage::GuildRanksMessage()
{
  m_type = MessageEnum::GUILDRANKSMESSAGE;
}

