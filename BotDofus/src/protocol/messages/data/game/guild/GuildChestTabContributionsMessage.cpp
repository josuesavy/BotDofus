#include "GuildChestTabContributionsMessage.h"

void GuildChestTabContributionsMessage::serialize(Writer *output)
{
  this->serializeAs_GuildChestTabContributionsMessage(output);
}

void GuildChestTabContributionsMessage::serializeAs_GuildChestTabContributionsMessage(Writer *output)
{
  output->writeShort((short)this->contributions.size());
  for(uint _i1 = 0; _i1 < this->contributions.size(); _i1++)
  {
    (this->contributions[_i1]).serializeAs_Contribution(output);
  }
}

void GuildChestTabContributionsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildChestTabContributionsMessage(input);
}

void GuildChestTabContributionsMessage::deserializeAs_GuildChestTabContributionsMessage(Reader *input)
{
  Contribution _item1 ;
  uint _contributionsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _contributionsLen; _i1++)
  {
    _item1 = Contribution();
    _item1.deserialize(input);
    this->contributions.append(_item1);
  }
}

void GuildChestTabContributionsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildChestTabContributionsMessage(tree);
}

void GuildChestTabContributionsMessage::deserializeAsyncAs_GuildChestTabContributionsMessage(FuncTree tree)
{
  this->_contributionstree = tree.addChild(std::bind(&GuildChestTabContributionsMessage::_contributionstreeFunc, this, std::placeholders::_1));
}

void GuildChestTabContributionsMessage::_contributionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_contributionstree.addChild(std::bind(&GuildChestTabContributionsMessage::_contributionsFunc, this, std::placeholders::_1));
  }
}

void GuildChestTabContributionsMessage::_contributionsFunc(Reader *input)
{
  Contribution _item = Contribution();
  _item.deserialize(input);
  this->contributions.append(_item);
}

GuildChestTabContributionsMessage::GuildChestTabContributionsMessage()
{
  m_type = MessageEnum::GUILDCHESTTABCONTRIBUTIONSMESSAGE;
}

