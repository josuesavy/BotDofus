#include "AccessoryPreviewRequestMessage.h"

void AccessoryPreviewRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AccessoryPreviewRequestMessage(output);
}

void AccessoryPreviewRequestMessage::serializeAs_AccessoryPreviewRequestMessage(Writer *output)
{
  output->writeShort((short)this->genericId.size());
  for(uint _i1 = 0; _i1 < this->genericId.size(); _i1++)
  {
    if(this->genericId[_i1] < 0)
    {
      qDebug()<<"ERREUR - AccessoryPreviewRequestMessage -"<<"Forbidden value (" << this->genericId[_i1] << ") on element 1 (starting at 1) of genericId.";
    }
    output->writeVarInt((int)this->genericId[_i1]);
  }
}

void AccessoryPreviewRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AccessoryPreviewRequestMessage(input);
}

void AccessoryPreviewRequestMessage::deserializeAs_AccessoryPreviewRequestMessage(Reader *input)
{
  uint _val1 = 0;
  uint _genericIdLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _genericIdLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - AccessoryPreviewRequestMessage -"<<"Forbidden value (" << _val1 << ") on elements of genericId.";
    }
    this->genericId.append(_val1);
  }
}

void AccessoryPreviewRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccessoryPreviewRequestMessage(tree);
}

void AccessoryPreviewRequestMessage::deserializeAsyncAs_AccessoryPreviewRequestMessage(FuncTree tree)
{
  this->_genericIdtree = tree.addChild(std::bind(&AccessoryPreviewRequestMessage::_genericIdtreeFunc, this, std::placeholders::_1));
}

void AccessoryPreviewRequestMessage::_genericIdtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_genericIdtree.addChild(std::bind(&AccessoryPreviewRequestMessage::_genericIdFunc, this, std::placeholders::_1));
  }
}

void AccessoryPreviewRequestMessage::_genericIdFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - AccessoryPreviewRequestMessage -"<<"Forbidden value (" << _val << ") on elements of genericId.";
  }
  this->genericId.append(_val);
}

AccessoryPreviewRequestMessage::AccessoryPreviewRequestMessage()
{
  m_type = MessageEnum::ACCESSORYPREVIEWREQUESTMESSAGE;
}

