#include "AchievementDetailedListMessage.h"

void AchievementDetailedListMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementDetailedListMessage(output);
}

void AchievementDetailedListMessage::serializeAs_AchievementDetailedListMessage(Writer *output)
{
  output->writeShort((short)this->startedAchievements.size());
  for(uint _i1 = 0; _i1 < this->startedAchievements.size(); _i1++)
  {
    (this->startedAchievements[_i1]).serializeAs_Achievement(output);
  }
  output->writeShort((short)this->finishedAchievements.size());
  for(uint _i2 = 0; _i2 < this->finishedAchievements.size(); _i2++)
  {
    (this->finishedAchievements[_i2]).serializeAs_Achievement(output);
  }
}

void AchievementDetailedListMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementDetailedListMessage(input);
}

void AchievementDetailedListMessage::deserializeAs_AchievementDetailedListMessage(Reader *input)
{
  Achievement _item1 ;
  Achievement _item2 ;
  uint _startedAchievementsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _startedAchievementsLen; _i1++)
  {
    _item1 = Achievement();
    _item1.deserialize(input);
    this->startedAchievements.append(_item1);
  }
  uint _finishedAchievementsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _finishedAchievementsLen; _i2++)
  {
    _item2 = Achievement();
    _item2.deserialize(input);
    this->finishedAchievements.append(_item2);
  }
}

void AchievementDetailedListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementDetailedListMessage(tree);
}

void AchievementDetailedListMessage::deserializeAsyncAs_AchievementDetailedListMessage(FuncTree tree)
{
  this->_startedAchievementstree = tree.addChild(std::bind(&AchievementDetailedListMessage::_startedAchievementstreeFunc, this, std::placeholders::_1));
  this->_finishedAchievementstree = tree.addChild(std::bind(&AchievementDetailedListMessage::_finishedAchievementstreeFunc, this, std::placeholders::_1));
}

void AchievementDetailedListMessage::_startedAchievementstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_startedAchievementstree.addChild(std::bind(&AchievementDetailedListMessage::_startedAchievementsFunc, this, std::placeholders::_1));
  }
}

void AchievementDetailedListMessage::_startedAchievementsFunc(Reader *input)
{
  Achievement _item = Achievement();
  _item.deserialize(input);
  this->startedAchievements.append(_item);
}

void AchievementDetailedListMessage::_finishedAchievementstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_finishedAchievementstree.addChild(std::bind(&AchievementDetailedListMessage::_finishedAchievementsFunc, this, std::placeholders::_1));
  }
}

void AchievementDetailedListMessage::_finishedAchievementsFunc(Reader *input)
{
  Achievement _item = Achievement();
  _item.deserialize(input);
  this->finishedAchievements.append(_item);
}

AchievementDetailedListMessage::AchievementDetailedListMessage()
{
  m_type = MessageEnum::ACHIEVEMENTDETAILEDLISTMESSAGE;
}

