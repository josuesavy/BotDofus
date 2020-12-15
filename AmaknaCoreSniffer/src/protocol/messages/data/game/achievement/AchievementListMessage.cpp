#include "AchievementListMessage.h"

void AchievementListMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementListMessage(output);
}

void AchievementListMessage::serializeAs_AchievementListMessage(Writer *output)
{
  output->writeShort((short)this->finishedAchievements.size());
  for(uint _i1 = 0; _i1 < this->finishedAchievements.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<AchievementAchieved>(this->finishedAchievements[_i1])->getTypes().last());
    qSharedPointerCast<AchievementAchieved>(this->finishedAchievements[_i1])->serialize(output);
  }
}

void AchievementListMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementListMessage(input);
}

void AchievementListMessage::deserializeAs_AchievementListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<AchievementAchieved> _item1 ;
  uint _finishedAchievementsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _finishedAchievementsLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<AchievementAchieved>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->finishedAchievements.append(_item1);
  }
}

void AchievementListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementListMessage(tree);
}

void AchievementListMessage::deserializeAsyncAs_AchievementListMessage(FuncTree tree)
{
  this->_finishedAchievementstree = tree.addChild(std::bind(&AchievementListMessage::_finishedAchievementstreeFunc, this, std::placeholders::_1));
}

void AchievementListMessage::_finishedAchievementstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_finishedAchievementstree.addChild(std::bind(&AchievementListMessage::_finishedAchievementsFunc, this, std::placeholders::_1));
  }
}

void AchievementListMessage::_finishedAchievementsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<AchievementAchieved> _item = qSharedPointerCast<AchievementAchieved>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->finishedAchievements.append(_item);
}

AchievementListMessage::AchievementListMessage()
{
  m_type = MessageEnum::ACHIEVEMENTLISTMESSAGE;
}

