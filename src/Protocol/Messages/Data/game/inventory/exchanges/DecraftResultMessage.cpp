#include "DecraftResultMessage.h"

void DecraftResultMessage::serialize(Writer *output)
{
  this->serializeAs_DecraftResultMessage(output);
}

void DecraftResultMessage::serializeAs_DecraftResultMessage(Writer *output)
{
  output->writeShort((short)this->results.size());
  for(uint _i1 = 0; _i1 < this->results.size(); _i1++)
  {
    (this->results[_i1]).serializeAs_DecraftedItemStackInfo(output);
  }
}

void DecraftResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_DecraftResultMessage(input);
}

void DecraftResultMessage::deserializeAs_DecraftResultMessage(Reader *input)
{
  DecraftedItemStackInfo _item1 ;
  uint _resultsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _resultsLen; _i1++)
  {
    _item1 = DecraftedItemStackInfo();
    _item1.deserialize(input);
    this->results.append(_item1);
  }
}

void DecraftResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DecraftResultMessage(tree);
}

void DecraftResultMessage::deserializeAsyncAs_DecraftResultMessage(FuncTree tree)
{
  this->_resultstree = tree.addChild(std::bind(&DecraftResultMessage::_resultstreeFunc, this, std::placeholders::_1));
}

void DecraftResultMessage::_resultstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_resultstree.addChild(std::bind(&DecraftResultMessage::_resultsFunc, this, std::placeholders::_1));
  }
}

void DecraftResultMessage::_resultsFunc(Reader *input)
{
  DecraftedItemStackInfo _item = DecraftedItemStackInfo();
  _item.deserialize(input);
  this->results.append(_item);
}

DecraftResultMessage::DecraftResultMessage()
{
  m_type = MessageEnum::DECRAFTRESULTMESSAGE;
}

