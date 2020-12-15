#include "ListMapNpcsQuestStatusUpdateMessage.h"

void ListMapNpcsQuestStatusUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_ListMapNpcsQuestStatusUpdateMessage(output);
}

void ListMapNpcsQuestStatusUpdateMessage::serializeAs_ListMapNpcsQuestStatusUpdateMessage(Writer *output)
{
  output->writeShort((short)this->mapInfo.size());
  for(uint _i1 = 0; _i1 < this->mapInfo.size(); _i1++)
  {
    (this->mapInfo[_i1]).serializeAs_MapNpcQuestInfo(output);
  }
}

void ListMapNpcsQuestStatusUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_ListMapNpcsQuestStatusUpdateMessage(input);
}

void ListMapNpcsQuestStatusUpdateMessage::deserializeAs_ListMapNpcsQuestStatusUpdateMessage(Reader *input)
{
  MapNpcQuestInfo _item1 ;
  uint _mapInfoLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _mapInfoLen; _i1++)
  {
    _item1 = MapNpcQuestInfo();
    _item1.deserialize(input);
    this->mapInfo.append(_item1);
  }
}

void ListMapNpcsQuestStatusUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ListMapNpcsQuestStatusUpdateMessage(tree);
}

void ListMapNpcsQuestStatusUpdateMessage::deserializeAsyncAs_ListMapNpcsQuestStatusUpdateMessage(FuncTree tree)
{
  this->_mapInfotree = tree.addChild(std::bind(&ListMapNpcsQuestStatusUpdateMessage::_mapInfotreeFunc, this, std::placeholders::_1));
}

void ListMapNpcsQuestStatusUpdateMessage::_mapInfotreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_mapInfotree.addChild(std::bind(&ListMapNpcsQuestStatusUpdateMessage::_mapInfoFunc, this, std::placeholders::_1));
  }
}

void ListMapNpcsQuestStatusUpdateMessage::_mapInfoFunc(Reader *input)
{
  MapNpcQuestInfo _item = MapNpcQuestInfo();
  _item.deserialize(input);
  this->mapInfo.append(_item);
}

ListMapNpcsQuestStatusUpdateMessage::ListMapNpcsQuestStatusUpdateMessage()
{
  m_type = MessageEnum::LISTMAPNPCSQUESTSTATUSUPDATEMESSAGE;
}

