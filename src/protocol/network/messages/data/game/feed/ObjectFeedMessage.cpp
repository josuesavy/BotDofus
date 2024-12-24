#include "ObjectFeedMessage.h"

void ObjectFeedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectFeedMessage(output);
}

void ObjectFeedMessage::serializeAs_ObjectFeedMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectFeedMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  output->writeShort((short)this->meal.size());
  for(uint _i2 = 0; _i2 < this->meal.size(); _i2++)
  {
    (this->meal[_i2]).serializeAs_ObjectItemQuantity(output);
  }
}

void ObjectFeedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectFeedMessage(input);
}

void ObjectFeedMessage::deserializeAs_ObjectFeedMessage(Reader *input)
{
  ObjectItemQuantity _item2 ;
  this->_objectUIDFunc(input);
  uint _mealLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _mealLen; _i2++)
  {
    _item2 = ObjectItemQuantity();
    _item2.deserialize(input);
    this->meal.append(_item2);
  }
}

void ObjectFeedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectFeedMessage(tree);
}

void ObjectFeedMessage::deserializeAsyncAs_ObjectFeedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectFeedMessage::_objectUIDFunc, this, std::placeholders::_1));
  this->_mealtree = tree.addChild(std::bind(&ObjectFeedMessage::_mealtreeFunc, this, std::placeholders::_1));
}

void ObjectFeedMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectFeedMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectFeedMessage.objectUID.";
  }
}

void ObjectFeedMessage::_mealtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_mealtree.addChild(std::bind(&ObjectFeedMessage::_mealFunc, this, std::placeholders::_1));
  }
}

void ObjectFeedMessage::_mealFunc(Reader *input)
{
  ObjectItemQuantity _item = ObjectItemQuantity();
  _item.deserialize(input);
  this->meal.append(_item);
}

ObjectFeedMessage::ObjectFeedMessage()
{
  m_type = MessageEnum::OBJECTFEEDMESSAGE;
}

