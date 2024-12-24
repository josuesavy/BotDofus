#include "HaapiBufferListMessage.h"

void HaapiBufferListMessage::serialize(Writer *output)
{
  this->serializeAs_HaapiBufferListMessage(output);
}

void HaapiBufferListMessage::serializeAs_HaapiBufferListMessage(Writer *output)
{
  output->writeShort((short)this->buffers.size());
  for(uint _i1 = 0; _i1 < this->buffers.size(); _i1++)
  {
    (this->buffers[_i1]).serializeAs_BufferInformation(output);
  }
}

void HaapiBufferListMessage::deserialize(Reader *input)
{
  this->deserializeAs_HaapiBufferListMessage(input);
}

void HaapiBufferListMessage::deserializeAs_HaapiBufferListMessage(Reader *input)
{
  BufferInformation _item1 ;
  uint _buffersLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _buffersLen; _i1++)
  {
    _item1 = BufferInformation();
    _item1.deserialize(input);
    this->buffers.append(_item1);
  }
}

void HaapiBufferListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HaapiBufferListMessage(tree);
}

void HaapiBufferListMessage::deserializeAsyncAs_HaapiBufferListMessage(FuncTree tree)
{
  this->_bufferstree = tree.addChild(std::bind(&HaapiBufferListMessage::_bufferstreeFunc, this, std::placeholders::_1));
}

void HaapiBufferListMessage::_bufferstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_bufferstree.addChild(std::bind(&HaapiBufferListMessage::_buffersFunc, this, std::placeholders::_1));
  }
}

void HaapiBufferListMessage::_buffersFunc(Reader *input)
{
  BufferInformation _item = BufferInformation();
  _item.deserialize(input);
  this->buffers.append(_item);
}

HaapiBufferListMessage::HaapiBufferListMessage()
{
  m_type = MessageEnum::HAAPIBUFFERLISTMESSAGE;
}

