#include "FollowedQuestsMessage.h"

void FollowedQuestsMessage::serialize(Writer *output)
{
  this->serializeAs_FollowedQuestsMessage(output);
}

void FollowedQuestsMessage::serializeAs_FollowedQuestsMessage(Writer *output)
{
  output->writeShort((short)this->quests.size());
  for(uint _i1 = 0; _i1 < this->quests.size(); _i1++)
  {
    qSharedPointerCast<QuestActiveDetailedInformations>(this->quests[_i1])->serializeAs_QuestActiveDetailedInformations(output);
  }
}

void FollowedQuestsMessage::deserialize(Reader *input)
{
  this->deserializeAs_FollowedQuestsMessage(input);
}

void FollowedQuestsMessage::deserializeAs_FollowedQuestsMessage(Reader *input)
{
  QSharedPointer<QuestActiveDetailedInformations> _item1 ;
  uint _questsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _questsLen; _i1++)
  {
    _item1 = QSharedPointer<QuestActiveDetailedInformations>(new QuestActiveDetailedInformations() );
    _item1->deserialize(input);
    this->quests.append(_item1);
  }
}

void FollowedQuestsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FollowedQuestsMessage(tree);
}

void FollowedQuestsMessage::deserializeAsyncAs_FollowedQuestsMessage(FuncTree tree)
{
  this->_queststree = tree.addChild(std::bind(&FollowedQuestsMessage::_queststreeFunc, this, std::placeholders::_1));
}

void FollowedQuestsMessage::_queststreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_queststree.addChild(std::bind(&FollowedQuestsMessage::_questsFunc, this, std::placeholders::_1));
  }
}

void FollowedQuestsMessage::_questsFunc(Reader *input)
{
  QSharedPointer<QuestActiveDetailedInformations> _item = QSharedPointer<QuestActiveDetailedInformations>(new QuestActiveDetailedInformations() );
  _item->deserialize(input);
  this->quests.append(_item);
}

FollowedQuestsMessage::FollowedQuestsMessage()
{
  m_type = MessageEnum::FOLLOWEDQUESTSMESSAGE;
}

