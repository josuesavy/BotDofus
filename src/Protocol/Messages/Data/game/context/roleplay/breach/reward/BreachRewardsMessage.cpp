#include "BreachRewardsMessage.h"

void BreachRewardsMessage::serialize(Writer *output)
{
  this->serializeAs_BreachRewardsMessage(output);
}

void BreachRewardsMessage::serializeAs_BreachRewardsMessage(Writer *output)
{
  output->writeShort((short)this->rewards.size());
  for(uint _i1 = 0; _i1 < this->rewards.size(); _i1++)
  {
    (this->rewards[_i1]).serializeAs_BreachReward(output);
  }
}

void BreachRewardsMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachRewardsMessage(input);
}

void BreachRewardsMessage::deserializeAs_BreachRewardsMessage(Reader *input)
{
  BreachReward _item1 ;
  uint _rewardsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _rewardsLen; _i1++)
  {
    _item1 = BreachReward();
    _item1.deserialize(input);
    this->rewards.append(_item1);
  }
}

void BreachRewardsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachRewardsMessage(tree);
}

void BreachRewardsMessage::deserializeAsyncAs_BreachRewardsMessage(FuncTree tree)
{
  this->_rewardstree = tree.addChild(std::bind(&BreachRewardsMessage::_rewardstreeFunc, this, std::placeholders::_1));
}

void BreachRewardsMessage::_rewardstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_rewardstree.addChild(std::bind(&BreachRewardsMessage::_rewardsFunc, this, std::placeholders::_1));
  }
}

void BreachRewardsMessage::_rewardsFunc(Reader *input)
{
  BreachReward _item = BreachReward();
  _item.deserialize(input);
  this->rewards.append(_item);
}

BreachRewardsMessage::BreachRewardsMessage()
{
  m_type = MessageEnum::BREACHREWARDSMESSAGE;
}

