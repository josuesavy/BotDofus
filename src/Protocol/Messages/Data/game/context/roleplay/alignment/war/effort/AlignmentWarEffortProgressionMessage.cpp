#include "AlignmentWarEffortProgressionMessage.h"

void AlignmentWarEffortProgressionMessage::serialize(Writer *output)
{
  this->serializeAs_AlignmentWarEffortProgressionMessage(output);
}

void AlignmentWarEffortProgressionMessage::serializeAs_AlignmentWarEffortProgressionMessage(Writer *output)
{
  output->writeShort((short)this->effortProgressions.size());
  for(uint _i1 = 0; _i1 < this->effortProgressions.size(); _i1++)
  {
    (this->effortProgressions[_i1]).serializeAs_AlignmentWarEffortInformation(output);
  }
}

void AlignmentWarEffortProgressionMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlignmentWarEffortProgressionMessage(input);
}

void AlignmentWarEffortProgressionMessage::deserializeAs_AlignmentWarEffortProgressionMessage(Reader *input)
{
  AlignmentWarEffortInformation _item1 ;
  uint _effortProgressionsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _effortProgressionsLen; _i1++)
  {
    _item1 = AlignmentWarEffortInformation();
    _item1.deserialize(input);
    this->effortProgressions.append(_item1);
  }
}

void AlignmentWarEffortProgressionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlignmentWarEffortProgressionMessage(tree);
}

void AlignmentWarEffortProgressionMessage::deserializeAsyncAs_AlignmentWarEffortProgressionMessage(FuncTree tree)
{
  this->_effortProgressionstree = tree.addChild(std::bind(&AlignmentWarEffortProgressionMessage::_effortProgressionstreeFunc, this, std::placeholders::_1));
}

void AlignmentWarEffortProgressionMessage::_effortProgressionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_effortProgressionstree.addChild(std::bind(&AlignmentWarEffortProgressionMessage::_effortProgressionsFunc, this, std::placeholders::_1));
  }
}

void AlignmentWarEffortProgressionMessage::_effortProgressionsFunc(Reader *input)
{
  AlignmentWarEffortInformation _item = AlignmentWarEffortInformation();
  _item.deserialize(input);
  this->effortProgressions.append(_item);
}

AlignmentWarEffortProgressionMessage::AlignmentWarEffortProgressionMessage()
{
  m_type = MessageEnum::ALIGNMENTWAREFFORTPROGRESSIONMESSAGE;
}

