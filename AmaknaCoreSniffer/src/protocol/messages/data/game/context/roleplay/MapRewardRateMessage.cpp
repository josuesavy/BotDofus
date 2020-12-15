#include "MapRewardRateMessage.h"

void MapRewardRateMessage::serialize(Writer *output)
{
  this->serializeAs_MapRewardRateMessage(output);
}

void MapRewardRateMessage::serializeAs_MapRewardRateMessage(Writer *output)
{
  output->writeVarShort((int)this->mapRate);
  output->writeVarShort((int)this->subAreaRate);
  output->writeVarShort((int)this->totalRate);
}

void MapRewardRateMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapRewardRateMessage(input);
}

void MapRewardRateMessage::deserializeAs_MapRewardRateMessage(Reader *input)
{
  this->_mapRateFunc(input);
  this->_subAreaRateFunc(input);
  this->_totalRateFunc(input);
}

void MapRewardRateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapRewardRateMessage(tree);
}

void MapRewardRateMessage::deserializeAsyncAs_MapRewardRateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MapRewardRateMessage::_mapRateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapRewardRateMessage::_subAreaRateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapRewardRateMessage::_totalRateFunc, this, std::placeholders::_1));
}

void MapRewardRateMessage::_mapRateFunc(Reader *input)
{
  this->mapRate = input->readVarShort();
}

void MapRewardRateMessage::_subAreaRateFunc(Reader *input)
{
  this->subAreaRate = input->readVarShort();
}

void MapRewardRateMessage::_totalRateFunc(Reader *input)
{
  this->totalRate = input->readVarShort();
}

MapRewardRateMessage::MapRewardRateMessage()
{
  m_type = MessageEnum::MAPREWARDRATEMESSAGE;
}

