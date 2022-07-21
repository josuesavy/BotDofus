#include "GuildLogbookInformationMessage.h"

void GuildLogbookInformationMessage::serialize(Writer *output)
{
  this->serializeAs_GuildLogbookInformationMessage(output);
}

void GuildLogbookInformationMessage::serializeAs_GuildLogbookInformationMessage(Writer *output)
{
  output->writeShort((short)this->globalActivities.size());
  for(uint _i1 = 0; _i1 < this->globalActivities.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<GuildLogbookEntryBasicInformation>(this->globalActivities[_i1])->getTypes().last());
    qSharedPointerCast<GuildLogbookEntryBasicInformation>(this->globalActivities[_i1])->serialize(output);
  }
  output->writeShort((short)this->chestActivities.size());
  for(uint _i2 = 0; _i2 < this->chestActivities.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<GuildLogbookEntryBasicInformation>(this->chestActivities[_i2])->getTypes().last());
    qSharedPointerCast<GuildLogbookEntryBasicInformation>(this->chestActivities[_i2])->serialize(output);
  }
}

void GuildLogbookInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildLogbookInformationMessage(input);
}

void GuildLogbookInformationMessage::deserializeAs_GuildLogbookInformationMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<GuildLogbookEntryBasicInformation> _item1 ;
  uint _id2 = 0;
  QSharedPointer<GuildLogbookEntryBasicInformation> _item2 ;
  uint _globalActivitiesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _globalActivitiesLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<GuildLogbookEntryBasicInformation>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->globalActivities.append(_item1);
  }
  uint _chestActivitiesLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _chestActivitiesLen; _i2++)
  {
    _id2 = input->readUShort();
    _item2 = qSharedPointerCast<GuildLogbookEntryBasicInformation>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->chestActivities.append(_item2);
  }
}

void GuildLogbookInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildLogbookInformationMessage(tree);
}

void GuildLogbookInformationMessage::deserializeAsyncAs_GuildLogbookInformationMessage(FuncTree tree)
{
  this->_globalActivitiestree = tree.addChild(std::bind(&GuildLogbookInformationMessage::_globalActivitiestreeFunc, this, std::placeholders::_1));
  this->_chestActivitiestree = tree.addChild(std::bind(&GuildLogbookInformationMessage::_chestActivitiestreeFunc, this, std::placeholders::_1));
}

void GuildLogbookInformationMessage::_globalActivitiestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_globalActivitiestree.addChild(std::bind(&GuildLogbookInformationMessage::_globalActivitiesFunc, this, std::placeholders::_1));
  }
}

void GuildLogbookInformationMessage::_globalActivitiesFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<GuildLogbookEntryBasicInformation> _item = qSharedPointerCast<GuildLogbookEntryBasicInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->globalActivities.append(_item);
}

void GuildLogbookInformationMessage::_chestActivitiestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_chestActivitiestree.addChild(std::bind(&GuildLogbookInformationMessage::_chestActivitiesFunc, this, std::placeholders::_1));
  }
}

void GuildLogbookInformationMessage::_chestActivitiesFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<GuildLogbookEntryBasicInformation> _item = qSharedPointerCast<GuildLogbookEntryBasicInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->chestActivities.append(_item);
}

GuildLogbookInformationMessage::GuildLogbookInformationMessage()
{
  m_type = MessageEnum::GUILDLOGBOOKINFORMATIONMESSAGE;
}

