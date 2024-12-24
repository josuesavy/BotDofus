#include "EvolutiveObjectRecycleResultMessage.h"

void EvolutiveObjectRecycleResultMessage::serialize(Writer *output)
{
  this->serializeAs_EvolutiveObjectRecycleResultMessage(output);
}

void EvolutiveObjectRecycleResultMessage::serializeAs_EvolutiveObjectRecycleResultMessage(Writer *output)
{
  output->writeShort((short)this->recycledItems.size());
  for(uint _i1 = 0; _i1 < this->recycledItems.size(); _i1++)
  {
    (this->recycledItems[_i1]).serializeAs_RecycledItem(output);
  }
}

void EvolutiveObjectRecycleResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_EvolutiveObjectRecycleResultMessage(input);
}

void EvolutiveObjectRecycleResultMessage::deserializeAs_EvolutiveObjectRecycleResultMessage(Reader *input)
{
  RecycledItem _item1 ;
  uint _recycledItemsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _recycledItemsLen; _i1++)
  {
    _item1 = RecycledItem();
    _item1.deserialize(input);
    this->recycledItems.append(_item1);
  }
}

void EvolutiveObjectRecycleResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EvolutiveObjectRecycleResultMessage(tree);
}

void EvolutiveObjectRecycleResultMessage::deserializeAsyncAs_EvolutiveObjectRecycleResultMessage(FuncTree tree)
{
  this->_recycledItemstree = tree.addChild(std::bind(&EvolutiveObjectRecycleResultMessage::_recycledItemstreeFunc, this, std::placeholders::_1));
}

void EvolutiveObjectRecycleResultMessage::_recycledItemstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_recycledItemstree.addChild(std::bind(&EvolutiveObjectRecycleResultMessage::_recycledItemsFunc, this, std::placeholders::_1));
  }
}

void EvolutiveObjectRecycleResultMessage::_recycledItemsFunc(Reader *input)
{
  RecycledItem _item = RecycledItem();
  _item.deserialize(input);
  this->recycledItems.append(_item);
}

EvolutiveObjectRecycleResultMessage::EvolutiveObjectRecycleResultMessage()
{
  m_type = MessageEnum::EVOLUTIVEOBJECTRECYCLERESULTMESSAGE;
}

