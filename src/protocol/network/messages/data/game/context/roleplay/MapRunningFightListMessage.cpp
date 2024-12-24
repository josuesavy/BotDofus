#include "MapRunningFightListMessage.h"

void MapRunningFightListMessage::serialize(Writer *output)
{
  this->serializeAs_MapRunningFightListMessage(output);
}

void MapRunningFightListMessage::serializeAs_MapRunningFightListMessage(Writer *output)
{
  output->writeShort((short)this->fights.size());
  for(uint _i1 = 0; _i1 < this->fights.size(); _i1++)
  {
    (this->fights[_i1]).serializeAs_FightExternalInformations(output);
  }
}

void MapRunningFightListMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapRunningFightListMessage(input);
}

void MapRunningFightListMessage::deserializeAs_MapRunningFightListMessage(Reader *input)
{
  FightExternalInformations _item1 ;
  uint _fightsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _fightsLen; _i1++)
  {
    _item1 = FightExternalInformations();
    _item1.deserialize(input);
    this->fights.append(_item1);
  }
}

void MapRunningFightListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapRunningFightListMessage(tree);
}

void MapRunningFightListMessage::deserializeAsyncAs_MapRunningFightListMessage(FuncTree tree)
{
  this->_fightstree = tree.addChild(std::bind(&MapRunningFightListMessage::_fightstreeFunc, this, std::placeholders::_1));
}

void MapRunningFightListMessage::_fightstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_fightstree.addChild(std::bind(&MapRunningFightListMessage::_fightsFunc, this, std::placeholders::_1));
  }
}

void MapRunningFightListMessage::_fightsFunc(Reader *input)
{
  FightExternalInformations _item = FightExternalInformations();
  _item.deserialize(input);
  this->fights.append(_item);
}

MapRunningFightListMessage::MapRunningFightListMessage()
{
  m_type = MessageEnum::MAPRUNNINGFIGHTLISTMESSAGE;
}

