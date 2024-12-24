#include "CheckIntegrityMessage.h"

void CheckIntegrityMessage::serialize(Writer *output)
{
  this->serializeAs_CheckIntegrityMessage(output);
}

void CheckIntegrityMessage::serializeAs_CheckIntegrityMessage(Writer *output)
{
  output->writeVarInt((int)this->data.size());
  for(uint _i1 = 0; _i1 < this->data.size(); _i1++)
  {
    output->writeByte(this->data[_i1]);
  }
}

void CheckIntegrityMessage::deserialize(Reader *input)
{
  this->deserializeAs_CheckIntegrityMessage(input);
}

void CheckIntegrityMessage::deserializeAs_CheckIntegrityMessage(Reader *input)
{
  int _val1 = 0;
  uint _dataLen = uint(input->readVarInt());
  for(uint _i1 = 0; _i1 < _dataLen; _i1++)
  {
    _val1 = int(input->readByte());
    this->data.append(_val1);
  }
}

void CheckIntegrityMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CheckIntegrityMessage(tree);
}

void CheckIntegrityMessage::deserializeAsyncAs_CheckIntegrityMessage(FuncTree tree)
{
  this->_datatree = tree.addChild(std::bind(&CheckIntegrityMessage::_datatreeFunc, this, std::placeholders::_1));
}

void CheckIntegrityMessage::_datatreeFunc(Reader *input)
{
  uint length = uint(input->readVarInt());
  for(uint i = 0; i < length; i++)
  {
    this->_datatree.addChild(std::bind(&CheckIntegrityMessage::_dataFunc, this, std::placeholders::_1));
  }
}

void CheckIntegrityMessage::_dataFunc(Reader *input)
{
  int _val = int(input->readByte());
  this->data.append(_val);
}

CheckIntegrityMessage::CheckIntegrityMessage()
{
  m_type = MessageEnum::CHECKINTEGRITYMESSAGE;
}

