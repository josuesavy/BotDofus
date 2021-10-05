#include "ExchangeMountsStableRemoveMessage.h"

void ExchangeMountsStableRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMountsStableRemoveMessage(output);
}

void ExchangeMountsStableRemoveMessage::serializeAs_ExchangeMountsStableRemoveMessage(Writer *output)
{
  output->writeShort((short)this->mountsId.size());
  for(uint _i1 = 0; _i1 < this->mountsId.size(); _i1++)
  {
    output->writeVarInt((int)this->mountsId[_i1]);
  }
}

void ExchangeMountsStableRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMountsStableRemoveMessage(input);
}

void ExchangeMountsStableRemoveMessage::deserializeAs_ExchangeMountsStableRemoveMessage(Reader *input)
{
  auto _val1 = 0;
  uint _mountsIdLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _mountsIdLen; _i1++)
  {
    _val1 = input->readVarInt();
    this->mountsId.append(_val1);
  }
}

void ExchangeMountsStableRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMountsStableRemoveMessage(tree);
}

void ExchangeMountsStableRemoveMessage::deserializeAsyncAs_ExchangeMountsStableRemoveMessage(FuncTree tree)
{
  this->_mountsIdtree = tree.addChild(std::bind(&ExchangeMountsStableRemoveMessage::_mountsIdtreeFunc, this, std::placeholders::_1));
}

void ExchangeMountsStableRemoveMessage::_mountsIdtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_mountsIdtree.addChild(std::bind(&ExchangeMountsStableRemoveMessage::_mountsIdFunc, this, std::placeholders::_1));
  }
}

void ExchangeMountsStableRemoveMessage::_mountsIdFunc(Reader *input)
{
  int _val = input->readVarInt();
  this->mountsId.append(_val);
}

ExchangeMountsStableRemoveMessage::ExchangeMountsStableRemoveMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSSTABLEREMOVEMESSAGE;
}

