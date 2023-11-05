#include "ObjectsDeletedMessage.h"

void ObjectsDeletedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectsDeletedMessage(output);
}

void ObjectsDeletedMessage::serializeAs_ObjectsDeletedMessage(Writer *output)
{
  output->writeShort((short)this->objectUID.size());
  for(uint _i1 = 0; _i1 < this->objectUID.size(); _i1++)
  {
    if(this->objectUID[_i1] < 0)
    {
      qDebug()<<"ERREUR - ObjectsDeletedMessage -"<<"Forbidden value (" << this->objectUID[_i1] << ") on element 1 (starting at 1) of objectUID.";
    }
    output->writeVarInt((int)this->objectUID[_i1]);
  }
}

void ObjectsDeletedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectsDeletedMessage(input);
}

void ObjectsDeletedMessage::deserializeAs_ObjectsDeletedMessage(Reader *input)
{
  uint _val1 = 0;
  uint _objectUIDLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _objectUIDLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ObjectsDeletedMessage -"<<"Forbidden value (" << _val1 << ") on elements of objectUID.";
    }
    this->objectUID.append(_val1);
  }
}

void ObjectsDeletedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectsDeletedMessage(tree);
}

void ObjectsDeletedMessage::deserializeAsyncAs_ObjectsDeletedMessage(FuncTree tree)
{
  this->_objectUIDtree = tree.addChild(std::bind(&ObjectsDeletedMessage::_objectUIDtreeFunc, this, std::placeholders::_1));
}

void ObjectsDeletedMessage::_objectUIDtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectUIDtree.addChild(std::bind(&ObjectsDeletedMessage::_objectUIDFunc, this, std::placeholders::_1));
  }
}

void ObjectsDeletedMessage::_objectUIDFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ObjectsDeletedMessage -"<<"Forbidden value (" << _val << ") on elements of objectUID.";
  }
  this->objectUID.append(_val);
}

ObjectsDeletedMessage::ObjectsDeletedMessage()
{
  m_type = MessageEnum::OBJECTSDELETEDMESSAGE;
}

