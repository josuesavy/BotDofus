#include "ExchangeObjectsRemovedMessage.h"

void ExchangeObjectsRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectsRemovedMessage(output);
}

void ExchangeObjectsRemovedMessage::serializeAs_ExchangeObjectsRemovedMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  output->writeShort((short)this->objectUID.size());
  for(uint _i1 = 0; _i1 < this->objectUID.size(); _i1++)
  {
    if(this->objectUID[_i1] < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectsRemovedMessage -"<<"Forbidden value (" << this->objectUID[_i1] << ") on element 1 (starting at 1) of objectUID.";
    }
    output->writeVarInt((int)this->objectUID[_i1]);
  }
}

void ExchangeObjectsRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectsRemovedMessage(input);
}

void ExchangeObjectsRemovedMessage::deserializeAs_ExchangeObjectsRemovedMessage(Reader *input)
{
  uint _val1 = 0;
  ExchangeObjectMessage::deserialize(input);
  uint _objectUIDLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _objectUIDLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ExchangeObjectsRemovedMessage -"<<"Forbidden value (" << _val1 << ") on elements of objectUID.";
    }
    this->objectUID.append(_val1);
  }
}

void ExchangeObjectsRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectsRemovedMessage(tree);
}

void ExchangeObjectsRemovedMessage::deserializeAsyncAs_ExchangeObjectsRemovedMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  this->_objectUIDtree = tree.addChild(std::bind(&ExchangeObjectsRemovedMessage::_objectUIDtreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectsRemovedMessage::_objectUIDtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectUIDtree.addChild(std::bind(&ExchangeObjectsRemovedMessage::_objectUIDFunc, this, std::placeholders::_1));
  }
}

void ExchangeObjectsRemovedMessage::_objectUIDFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectsRemovedMessage -"<<"Forbidden value (" << _val << ") on elements of objectUID.";
  }
  this->objectUID.append(_val);
}

ExchangeObjectsRemovedMessage::ExchangeObjectsRemovedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTSREMOVEDMESSAGE;
}

