#include "MapNpcsQuestStatusUpdateMessage.h"

void MapNpcsQuestStatusUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_MapNpcsQuestStatusUpdateMessage(output);
}

void MapNpcsQuestStatusUpdateMessage::serializeAs_MapNpcsQuestStatusUpdateMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MapNpcsQuestStatusUpdateMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  output->writeShort((short)this->npcsIdsWithQuest.size());
  for(uint _i2 = 0; _i2 < this->npcsIdsWithQuest.size(); _i2++)
  {
    output->writeInt((int)this->npcsIdsWithQuest[_i2]);
  }
  output->writeShort((short)this->questFlags.size());
  for(uint _i3 = 0; _i3 < this->questFlags.size(); _i3++)
  {
    (this->questFlags[_i3]).serializeAs_GameRolePlayNpcQuestFlag(output);
  }
  output->writeShort((short)this->npcsIdsWithoutQuest.size());
  for(uint _i4 = 0; _i4 < this->npcsIdsWithoutQuest.size(); _i4++)
  {
    output->writeInt((int)this->npcsIdsWithoutQuest[_i4]);
  }
}

void MapNpcsQuestStatusUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapNpcsQuestStatusUpdateMessage(input);
}

void MapNpcsQuestStatusUpdateMessage::deserializeAs_MapNpcsQuestStatusUpdateMessage(Reader *input)
{
  auto _val2 = 0;
  GameRolePlayNpcQuestFlag _item3 ;
  auto _val4 = 0;
  this->_mapIdFunc(input);
  uint _npcsIdsWithQuestLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _npcsIdsWithQuestLen; _i2++)
  {
    _val2 = input->readInt();
    this->npcsIdsWithQuest.append(_val2);
  }
  uint _questFlagsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _questFlagsLen; _i3++)
  {
    _item3 = GameRolePlayNpcQuestFlag();
    _item3.deserialize(input);
    this->questFlags.append(_item3);
  }
  uint _npcsIdsWithoutQuestLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _npcsIdsWithoutQuestLen; _i4++)
  {
    _val4 = input->readInt();
    this->npcsIdsWithoutQuest.append(_val4);
  }
}

void MapNpcsQuestStatusUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapNpcsQuestStatusUpdateMessage(tree);
}

void MapNpcsQuestStatusUpdateMessage::deserializeAsyncAs_MapNpcsQuestStatusUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MapNpcsQuestStatusUpdateMessage::_mapIdFunc, this, std::placeholders::_1));
  this->_npcsIdsWithQuesttree = tree.addChild(std::bind(&MapNpcsQuestStatusUpdateMessage::_npcsIdsWithQuesttreeFunc, this, std::placeholders::_1));
  this->_questFlagstree = tree.addChild(std::bind(&MapNpcsQuestStatusUpdateMessage::_questFlagstreeFunc, this, std::placeholders::_1));
  this->_npcsIdsWithoutQuesttree = tree.addChild(std::bind(&MapNpcsQuestStatusUpdateMessage::_npcsIdsWithoutQuesttreeFunc, this, std::placeholders::_1));
}

void MapNpcsQuestStatusUpdateMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MapNpcsQuestStatusUpdateMessage -"<<"Forbidden value (" << this->mapId << ") on element of MapNpcsQuestStatusUpdateMessage.mapId.";
  }
}

void MapNpcsQuestStatusUpdateMessage::_npcsIdsWithQuesttreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_npcsIdsWithQuesttree.addChild(std::bind(&MapNpcsQuestStatusUpdateMessage::_npcsIdsWithQuestFunc, this, std::placeholders::_1));
  }
}

void MapNpcsQuestStatusUpdateMessage::_npcsIdsWithQuestFunc(Reader *input)
{
  int _val = input->readInt();
  this->npcsIdsWithQuest.append(_val);
}

void MapNpcsQuestStatusUpdateMessage::_questFlagstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_questFlagstree.addChild(std::bind(&MapNpcsQuestStatusUpdateMessage::_questFlagsFunc, this, std::placeholders::_1));
  }
}

void MapNpcsQuestStatusUpdateMessage::_questFlagsFunc(Reader *input)
{
  GameRolePlayNpcQuestFlag _item = GameRolePlayNpcQuestFlag();
  _item.deserialize(input);
  this->questFlags.append(_item);
}

void MapNpcsQuestStatusUpdateMessage::_npcsIdsWithoutQuesttreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_npcsIdsWithoutQuesttree.addChild(std::bind(&MapNpcsQuestStatusUpdateMessage::_npcsIdsWithoutQuestFunc, this, std::placeholders::_1));
  }
}

void MapNpcsQuestStatusUpdateMessage::_npcsIdsWithoutQuestFunc(Reader *input)
{
  int _val = input->readInt();
  this->npcsIdsWithoutQuest.append(_val);
}

MapNpcsQuestStatusUpdateMessage::MapNpcsQuestStatusUpdateMessage()
{
  m_type = MessageEnum::MAPNPCSQUESTSTATUSUPDATEMESSAGE;
}

