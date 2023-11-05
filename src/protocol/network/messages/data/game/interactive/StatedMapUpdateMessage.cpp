#include "StatedMapUpdateMessage.h"

void StatedMapUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_StatedMapUpdateMessage(output);
}

void StatedMapUpdateMessage::serializeAs_StatedMapUpdateMessage(Writer *output)
{
  output->writeShort((short)this->statedElements.size());
  for(uint _i1 = 0; _i1 < this->statedElements.size(); _i1++)
  {
    (this->statedElements[_i1]).serializeAs_StatedElement(output);
  }
}

void StatedMapUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_StatedMapUpdateMessage(input);
}

void StatedMapUpdateMessage::deserializeAs_StatedMapUpdateMessage(Reader *input)
{
  StatedElement _item1 ;
  uint _statedElementsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _statedElementsLen; _i1++)
  {
    _item1 = StatedElement();
    _item1.deserialize(input);
    this->statedElements.append(_item1);
  }
}

void StatedMapUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StatedMapUpdateMessage(tree);
}

void StatedMapUpdateMessage::deserializeAsyncAs_StatedMapUpdateMessage(FuncTree tree)
{
  this->_statedElementstree = tree.addChild(std::bind(&StatedMapUpdateMessage::_statedElementstreeFunc, this, std::placeholders::_1));
}

void StatedMapUpdateMessage::_statedElementstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_statedElementstree.addChild(std::bind(&StatedMapUpdateMessage::_statedElementsFunc, this, std::placeholders::_1));
  }
}

void StatedMapUpdateMessage::_statedElementsFunc(Reader *input)
{
  StatedElement _item = StatedElement();
  _item.deserialize(input);
  this->statedElements.append(_item);
}

StatedMapUpdateMessage::StatedMapUpdateMessage()
{
  m_type = MessageEnum::STATEDMAPUPDATEMESSAGE;
}

