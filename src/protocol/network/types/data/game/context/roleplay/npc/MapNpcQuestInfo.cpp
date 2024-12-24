#include "MapNpcQuestInfo.h"

void MapNpcQuestInfo::serialize(Writer *output)
{
  this->serializeAs_MapNpcQuestInfo(output);
}

void MapNpcQuestInfo::serializeAs_MapNpcQuestInfo(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - MapNpcQuestInfo -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
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
}

void MapNpcQuestInfo::deserialize(Reader *input)
{
  this->deserializeAs_MapNpcQuestInfo(input);
}

void MapNpcQuestInfo::deserializeAs_MapNpcQuestInfo(Reader *input)
{
  int _val2 = 0;
  GameRolePlayNpcQuestFlag _item3 ;
  this->_mapIdFunc(input);
  uint _npcsIdsWithQuestLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _npcsIdsWithQuestLen; _i2++)
  {
    _val2 = int(input->readInt());
    this->npcsIdsWithQuest.append(_val2);
  }
  uint _questFlagsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _questFlagsLen; _i3++)
  {
    _item3 = GameRolePlayNpcQuestFlag();
    _item3.deserialize(input);
    this->questFlags.append(_item3);
  }
}

void MapNpcQuestInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapNpcQuestInfo(tree);
}

void MapNpcQuestInfo::deserializeAsyncAs_MapNpcQuestInfo(FuncTree tree)
{
  tree.addChild(std::bind(&MapNpcQuestInfo::_mapIdFunc, this, std::placeholders::_1));
  this->_npcsIdsWithQuesttree = tree.addChild(std::bind(&MapNpcQuestInfo::_npcsIdsWithQuesttreeFunc, this, std::placeholders::_1));
  this->_questFlagstree = tree.addChild(std::bind(&MapNpcQuestInfo::_questFlagstreeFunc, this, std::placeholders::_1));
}

void MapNpcQuestInfo::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - MapNpcQuestInfo -"<<"Forbidden value (" << this->mapId << ") on element of MapNpcQuestInfo.mapId.";
  }
}

void MapNpcQuestInfo::_npcsIdsWithQuesttreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_npcsIdsWithQuesttree.addChild(std::bind(&MapNpcQuestInfo::_npcsIdsWithQuestFunc, this, std::placeholders::_1));
  }
}

void MapNpcQuestInfo::_npcsIdsWithQuestFunc(Reader *input)
{
  int _val = int(input->readInt());
  this->npcsIdsWithQuest.append(_val);
}

void MapNpcQuestInfo::_questFlagstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_questFlagstree.addChild(std::bind(&MapNpcQuestInfo::_questFlagsFunc, this, std::placeholders::_1));
  }
}

void MapNpcQuestInfo::_questFlagsFunc(Reader *input)
{
  GameRolePlayNpcQuestFlag _item = GameRolePlayNpcQuestFlag();
  _item.deserialize(input);
  this->questFlags.append(_item);
}

MapNpcQuestInfo::MapNpcQuestInfo()
{
  m_types<<ClassEnum::MAPNPCQUESTINFO;
}

bool MapNpcQuestInfo::operator==(const MapNpcQuestInfo &compared)
{
  if(mapId == compared.mapId)
  if(npcsIdsWithQuest == compared.npcsIdsWithQuest)
  if(questFlags == compared.questFlags)
  if(_npcsIdsWithQuesttree == compared._npcsIdsWithQuesttree)
  if(_questFlagstree == compared._questFlagstree)
  return true;
  
  return false;
}

