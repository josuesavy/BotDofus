#include "AchievementsPioneerRanksMessage.h"

void AchievementsPioneerRanksMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementsPioneerRanksMessage(output);
}

void AchievementsPioneerRanksMessage::serializeAs_AchievementsPioneerRanksMessage(Writer *output)
{
  output->writeShort((short)this->achievementsPioneerRanks.size());
  for(uint _i1 = 0; _i1 < this->achievementsPioneerRanks.size(); _i1++)
  {
    (this->achievementsPioneerRanks[_i1]).serializeAs_AchievementPioneerRank(output);
  }
}

void AchievementsPioneerRanksMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementsPioneerRanksMessage(input);
}

void AchievementsPioneerRanksMessage::deserializeAs_AchievementsPioneerRanksMessage(Reader *input)
{
  AchievementPioneerRank _item1 ;
  uint _achievementsPioneerRanksLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _achievementsPioneerRanksLen; _i1++)
  {
    _item1 = AchievementPioneerRank();
    _item1.deserialize(input);
    this->achievementsPioneerRanks.append(_item1);
  }
}

void AchievementsPioneerRanksMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementsPioneerRanksMessage(tree);
}

void AchievementsPioneerRanksMessage::deserializeAsyncAs_AchievementsPioneerRanksMessage(FuncTree tree)
{
  this->_achievementsPioneerRankstree = tree.addChild(std::bind(&AchievementsPioneerRanksMessage::_achievementsPioneerRankstreeFunc, this, std::placeholders::_1));
}

void AchievementsPioneerRanksMessage::_achievementsPioneerRankstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_achievementsPioneerRankstree.addChild(std::bind(&AchievementsPioneerRanksMessage::_achievementsPioneerRanksFunc, this, std::placeholders::_1));
  }
}

void AchievementsPioneerRanksMessage::_achievementsPioneerRanksFunc(Reader *input)
{
  AchievementPioneerRank _item = AchievementPioneerRank();
  _item.deserialize(input);
  this->achievementsPioneerRanks.append(_item);
}

AchievementsPioneerRanksMessage::AchievementsPioneerRanksMessage()
{
  m_type = MessageEnum::ACHIEVEMENTSPIONEERRANKSMESSAGE;
}

