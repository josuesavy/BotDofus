#include "AchievementAlmostFinishedDetailedListMessage.h"

void AchievementAlmostFinishedDetailedListMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementAlmostFinishedDetailedListMessage(output);
}

void AchievementAlmostFinishedDetailedListMessage::serializeAs_AchievementAlmostFinishedDetailedListMessage(Writer *output)
{
  output->writeShort((short)this->almostFinishedAchievements.size());
  for(uint _i1 = 0; _i1 < this->almostFinishedAchievements.size(); _i1++)
  {
    (this->almostFinishedAchievements[_i1]).serializeAs_Achievement(output);
  }
}

void AchievementAlmostFinishedDetailedListMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementAlmostFinishedDetailedListMessage(input);
}

void AchievementAlmostFinishedDetailedListMessage::deserializeAs_AchievementAlmostFinishedDetailedListMessage(Reader *input)
{
  Achievement _item1 ;
  uint _almostFinishedAchievementsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _almostFinishedAchievementsLen; _i1++)
  {
    _item1 = Achievement();
    _item1.deserialize(input);
    this->almostFinishedAchievements.append(_item1);
  }
}

void AchievementAlmostFinishedDetailedListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementAlmostFinishedDetailedListMessage(tree);
}

void AchievementAlmostFinishedDetailedListMessage::deserializeAsyncAs_AchievementAlmostFinishedDetailedListMessage(FuncTree tree)
{
  this->_almostFinishedAchievementstree = tree.addChild(std::bind(&AchievementAlmostFinishedDetailedListMessage::_almostFinishedAchievementstreeFunc, this, std::placeholders::_1));
}

void AchievementAlmostFinishedDetailedListMessage::_almostFinishedAchievementstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_almostFinishedAchievementstree.addChild(std::bind(&AchievementAlmostFinishedDetailedListMessage::_almostFinishedAchievementsFunc, this, std::placeholders::_1));
  }
}

void AchievementAlmostFinishedDetailedListMessage::_almostFinishedAchievementsFunc(Reader *input)
{
  Achievement _item = Achievement();
  _item.deserialize(input);
  this->almostFinishedAchievements.append(_item);
}

AchievementAlmostFinishedDetailedListMessage::AchievementAlmostFinishedDetailedListMessage()
{
  m_type = MessageEnum::ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTMESSAGE;
}

