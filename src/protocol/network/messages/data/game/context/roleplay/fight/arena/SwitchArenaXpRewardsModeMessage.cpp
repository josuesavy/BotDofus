#include "SwitchArenaXpRewardsModeMessage.h"

void SwitchArenaXpRewardsModeMessage::serialize(Writer *output)
{
  this->serializeAs_SwitchArenaXpRewardsModeMessage(output);
}

void SwitchArenaXpRewardsModeMessage::serializeAs_SwitchArenaXpRewardsModeMessage(Writer *output)
{
  output->writeBool(this->xpRewards);
}

void SwitchArenaXpRewardsModeMessage::deserialize(Reader *input)
{
  this->deserializeAs_SwitchArenaXpRewardsModeMessage(input);
}

void SwitchArenaXpRewardsModeMessage::deserializeAs_SwitchArenaXpRewardsModeMessage(Reader *input)
{
  this->_xpRewardsFunc(input);
}

void SwitchArenaXpRewardsModeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SwitchArenaXpRewardsModeMessage(tree);
}

void SwitchArenaXpRewardsModeMessage::deserializeAsyncAs_SwitchArenaXpRewardsModeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SwitchArenaXpRewardsModeMessage::_xpRewardsFunc, this, std::placeholders::_1));
}

void SwitchArenaXpRewardsModeMessage::_xpRewardsFunc(Reader *input)
{
  this->xpRewards = input->readBool();
}

SwitchArenaXpRewardsModeMessage::SwitchArenaXpRewardsModeMessage()
{
  m_type = MessageEnum::SWITCHARENAXPREWARDSMODEMESSAGE;
}

