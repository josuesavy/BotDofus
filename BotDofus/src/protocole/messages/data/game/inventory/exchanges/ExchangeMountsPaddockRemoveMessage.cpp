#include "ExchangeMountsPaddockRemoveMessage.h"

void ExchangeMountsPaddockRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMountsPaddockRemoveMessage(output);
}

void ExchangeMountsPaddockRemoveMessage::serializeAs_ExchangeMountsPaddockRemoveMessage(Writer *output)
{
  output->writeShort((short)this->mountsId.size());
  for(uint _i1 = 0; _i1 < this->mountsId.size(); _i1++)
  {
    output->writeVarInt((int)this->mountsId[_i1]);
  }
}

void ExchangeMountsPaddockRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMountsPaddockRemoveMessage(input);
}

void ExchangeMountsPaddockRemoveMessage::deserializeAs_ExchangeMountsPaddockRemoveMessage(Reader *input)
{
  auto _val1 = 0;
  uint _mountsIdLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _mountsIdLen; _i1++)
  {
    _val1 = input->readVarInt();
    this->mountsId.append(_val1);
  }
}

void ExchangeMountsPaddockRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMountsPaddockRemoveMessage(tree);
}

void ExchangeMountsPaddockRemoveMessage::deserializeAsyncAs_ExchangeMountsPaddockRemoveMessage(FuncTree tree)
{
  this->_mountsIdtree = tree.addChild(std::bind(&ExchangeMountsPaddockRemoveMessage::_mountsIdtreeFunc, this, std::placeholders::_1));
}

void ExchangeMountsPaddockRemoveMessage::_mountsIdtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_mountsIdtree.addChild(std::bind(&ExchangeMountsPaddockRemoveMessage::_mountsIdFunc, this, std::placeholders::_1));
  }
}

void ExchangeMountsPaddockRemoveMessage::_mountsIdFunc(Reader *input)
{
  int _val = input->readVarInt();
  this->mountsId.append(_val);
}

ExchangeMountsPaddockRemoveMessage::ExchangeMountsPaddockRemoveMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE;
}

